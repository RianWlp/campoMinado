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

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // Inicializa o ncurses
    initscr();            // Começa a janela ncurses
    cbreak();             // Desabilita o buffering de linha
    noecho();             // Não mostra as teclas digitadas
    keypad(stdscr, TRUE); // Habilita teclas como setas
    curs_set(0);          // Esconde o cursor

    cout << "Bem vindo ao campo minado em C++" << endl;
    // cout << "Informe o tamanho o mapa desejado" << endl;
    mapa mapa;
    mapa.quantBombas = 150;
    mapa.tamanhoMapa = 40;

    // Inicializa o mapa com apenas zeros (0)
    // mapa.mapa = vector<vector<char>>(mapa.tamanhoMapa, vector<char>(mapa.tamanhoMapa, '0'));
    mapa.coordsBombas = vector<vector<char>>(mapa.tamanhoMapa, vector<char>(mapa.tamanhoMapa, 'X'));

    int ch,
        y = 0,
        x = 0;

    string log;
    bool primeiroClick = false;
    vector<string> vetorLogs;

    clear();
    do
    {
        log = "";
        if ((ch == KEY_ENTER) || (ch == '\n') && !primeiroClick)
        {
            mapa = randomizarBombas(mapa);
            // for (int i = 0; i < mapa.tamanhoMapa; i++)
            // {
            //     for (int j = 0; j < mapa.tamanhoMapa; j++)
            //     {
            //         if (mapa.coordsBombas[i][j] == '*')
            //         {
            //             mvprintw(i + 1, mapa.tamanhoMapa * 2, "- i: %d j: %d", i, j);
            //         }
            //     }
            // }

            // exibirMapa(mapa);
            primeiroClick = true;
        }

        if ((ch == KEY_ENTER) || (ch == '\n'))
        {
            int metadeX = x / 2;

            // Vai dividir por dois por conta dos espacos postos no mapa (Gambirra)
            log = string("ASCII: ") + to_string(metadeX) + " " + to_string(y);
            vetorLogs.push_back(log);
            log = string("Valor da posicao bomba ") + mapa.coordsBombas[metadeX][y] + to_string(mapa.coordsBombas[metadeX][y] == '*');
            vetorLogs.push_back(log);

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
                // exit(0);
            }
        }

        // O ch é o código da tecla pressionada

        switch (ch)
        {
        case KEY_UP:
            y--;
            break;
        case KEY_DOWN:
            y++;
            break;
        case KEY_LEFT:
            x--;
            break;
        case KEY_RIGHT:
            x++;
            break;
        }

        // vetorLogs.push_back(log);
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

        for (size_t i = 0; i < vetorLogs.size(); ++i)
        {
            mvprintw(i + 1, mapa.tamanhoMapa * 2, "- %s", vetorLogs[i].c_str());
            // if (i > 20) {

            //     for (size_t i = 0; i < vetorLogs.size(); ++i)
            //     {
            //         mvprintw(i + 1, mapa.tamanhoMapa * 2, " ");
            //     }
            //     // mvprintw(i + 1, mapa.tamanhoMapa * 2, " ");
            // }
        }
        refresh();

        // Sai com a tecla 'q')
    } while ((ch = getch()) != 'q');

    // Encerra o modo ncurses
    endwin();
    // montarMapa(mapa);
    return 0;
}
