#include <iostream>
#include <vector>
#include <ncurses.h>
#include <curses.h> // Essa lib é necessária caso for usar cores

using namespace std;

// g++ -o campoMinadoV2 campoMinadoV2.cpp -lncurses ; ./campoMinadoV2

struct mapa
{
    int tamanhoMapa;
    int quantBombas;
    vector<vector<char>> mapa;
    vector<vector<char>> coordsBombas;
};

void exibirLogs(vector<string> logs, mapa mapa)
{
    for (size_t i = 0; i < logs.size(); ++i)
    {
        mvprintw(i + 1, mapa.tamanhoMapa * 2, "- %s", logs[i].c_str());
    }
    refresh();
}

void exibirMapa(mapa mapa)
{
    cout << endl
         << endl;
    for (int i = 0; i < mapa.tamanhoMapa; i++)
    {
        if (i > 9)
        {
            cout << i << " ";
        }
        else
        {
            cout << i << "  ";
        }

        for (int j = 0; j < mapa.tamanhoMapa; j++)
        {
            cout << mapa.coordsBombas[i][j] << " ";
        }
        cout << endl;
    }
}

void montarMapa(mapa mapa)
{
    // int x, y;
    clear();
    for (int x = 0; x < mapa.tamanhoMapa; x++)
    {
        for (int y = 0; y < mapa.tamanhoMapa; y++)
        {
            mvprintw(y, x, "0"); // Imprime o caractere na nova posição
            refresh();           // Atualiza a tela
        }
    }
    endwin(); // Encerra o modo ncurses
}

int randomizarValor(int range)
{
    return rand() % range + 1;
}

// mapa randomizarBombas(int quantidadeBombas, int tamanhoMapa, vector<vector<char>> mapa)
mapa randomizarBombas(mapa mapa)
{
    int x,
        y;
    for (int i = 0; i < mapa.quantBombas; i++)
    {
        // Garante que a posição gerada não tenha uma bomba já
        do
        {
            x = randomizarValor(mapa.tamanhoMapa);
            y = randomizarValor(mapa.tamanhoMapa);
        } while (x == mapa.tamanhoMapa || y == mapa.tamanhoMapa);
        mapa.coordsBombas[x][y] = '*';
    }
    return mapa;
}

// Precisa ser testada
void calcularBombas (mapa mapa) {

    int x,
        y;

    for (int i = 0; i < mapa.tamanhoMapa; i++)
    {
        for (int j = 0; j < mapa.tamanhoMapa; j++)
        {
            if (mapa.coordsBombas[i][j] == '*')
            {
                // Verifica as posições adjacentes
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (i + x >= 0 && i + x < mapa.tamanhoMapa && j + y >= 0 && j + y < mapa.tamanhoMapa)
                        {
                            if (mapa.coordsBombas[i + x][j + y] != '*')
                            {
                                mapa.coordsBombas[i + x][j + y]++;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // Proximo passo vai ser liberar o mapa apos a posicao que nao (e) uma bomba ser pressionada
    srand(time(NULL));

    // Inicializa o ncurses
    // initscr();            // Começa a janela ncurses
    // cbreak();             // Desabilita o buffering de linha
    // noecho();             // Não mostra as teclas digitadas
    // keypad(stdscr, TRUE); // Habilita teclas como setas
    // curs_set(0);          // Esconde o cursor

    cout << "Bem vindo ao campo minado em C++" << endl;
    // cout << "Informe o tamanho o mapa desejado" << endl;
    mapa mapa;
    mapa.quantBombas = 150;
    mapa.tamanhoMapa = 40;

    // Inicializa o mapa com apenas zeros (0)
    mapa.coordsBombas = vector<vector<char>>(mapa.tamanhoMapa, vector<char>(mapa.tamanhoMapa, '0'));

    int ch = 0,
        y = 0,
        x = 0;

    string log;
    bool primeiroClick = false;
    vector<string> vetorLogs;

    mapa = randomizarBombas(mapa);
    exibirMapa(mapa);

    return 0;

    do
    {
        log = "";

        if ((ch == KEY_ENTER) || (ch == '\n'))
        {
            primeiroClick = true;
            // Vai dividir por dois por conta dos espacos postos no mapa (Gambirra)
            int metadeX = x / 2;

            vetorLogs.push_back(string("ASCII ->> ") + "C:" + to_string(metadeX) + " L:" + to_string(y));
            vetorLogs.push_back(string("Valor da posicao pressionada: ") + mapa.coordsBombas[metadeX][y] + " | Bomba? " + (mapa.coordsBombas[metadeX][y] == '*' ? "Sim" : "Não"));

            if (vetorLogs.size() > 20)
            {
                vetorLogs.erase(vetorLogs.begin());
                // vetorLogs.clear();
                // vetorLogs.erase(vetorLogs.end());
            }

            if (mapa.coordsBombas[metadeX][y] == '*')
            {
                mvprintw(mapa.tamanhoMapa + 2, 0, "BOMBA! Você perdeu!");

                // Revela todas as bombas
                for (int i = 0; i < mapa.tamanhoMapa; ++i)
                {
                    for (int j = 0; j < mapa.tamanhoMapa; ++j)
                    {
                        if (mapa.coordsBombas[i][j] == '*')
                        {
                            mvprintw(i, j * 2, "* ");
                        }
                    }
                }

                refresh();
                getch();
                endwin();
                exit(0);
            }
        }
        else if (ch == KEY_UP)
        {
            y--;
        }
        else if (ch == KEY_DOWN)
        {
            y++;
        }
        else if (ch == KEY_LEFT)
        {
            x--;
        }
        else if (ch == KEY_RIGHT)
        {
            x++;
        }
        else if (!primeiroClick)
        {
            mapa = randomizarBombas(mapa);
        }

        // Antes de andar valida se a proxima posicao (e) uma bomba
        for (int xM = 0; xM < mapa.tamanhoMapa; xM++)
        {
            for (int yM = 0; yM < mapa.tamanhoMapa; yM++)
            {
                // O vezes 2 conta como sendo uma posicao do mapa, ou seja, se o mapa tiver 10 ele vai ser o dobro
                mvprintw(xM, yM * 2, "0 "); // Imprime "0 " (zero + espaço)
            }
            refresh(); // Atualiza a tela
        }

        mvprintw(y, x, "@"); // Imprime o caractere na nova posição
        refresh();

        exibirLogs(vetorLogs, mapa);

        // Sai com a tecla 'q')
    } while ((ch = getch()) != 'q');

    // Encerra o modo ncurses
    endwin();
    // montarMapa(mapa);
    return 0;
}
