#include <iostream>
#include <vector>
using namespace std;

// https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix
struct mapa
{
    vector<vector<char>> grid;
    int sizeGrid;
    int quantidadeBombas;
    vector<vector<char>> coordenadasBombas;
};

int randomizarValor(int range)
{
    return rand() % range + 1;
}

// mapa randomizarBombas(int quantidadeBombas, int tamanhoMapa, vector<vector<char>> mapa)
mapa randomizarBombas(mapa mapa)
{
    int x,
        y;
    for (int i = 0; i < mapa.quantidadeBombas; i++)
    {
        // Garante que a posição gerada não tenha uma bomba já
        do
        {
            x = randomizarValor(mapa.sizeGrid);
            y = randomizarValor(mapa.sizeGrid);
        } while (x == mapa.sizeGrid || y == mapa.sizeGrid);
        mapa.coordenadasBombas[x][y] = '*';
        // mapa.grid[x][y] = '*';
    }
    return mapa;
}

void exibirMapa(mapa mapa)
{
    // Sempre vai ser quadrado 10x10, 20x20 ex.

    // for (int i = 0; i < mapa.sizeGrid; i++)
    // {
    //     cout << i << " ";
    // }

    cout << endl << endl;
    // int tamanhoMapa = mapa.grid.size();

    // std::string espacos = "";
    for (int i = 0; i < mapa.sizeGrid; i++)
    {
        // espacos = i+"";
        // cout << espacos.length() << "    ";
        // cout << espacos << " ";

        // Isso precisa ser dinamico
        if (i > 9)
        {
            cout << i << " ";
        }
        else
        {
            cout << i << "  ";
        }

        for (int j = 0; j < mapa.sizeGrid; j++)
        {
            // cout << j << " ";
            cout << mapa.grid[i][j] << " ";
            // cout << mapa.grid[i][j] << "  ";
        }
        cout << endl;
    }
}

void validarCoordenadaBomba () {

    // Vai cruzar a grid com as coordenadas das bombas no mapa
}

void mostrarBombas() {}

// Instalar o ncursors no Linux, ele pode resolver o problema dos Index
// sudo apt-get install libncurses5-dev libncursesw5-dev

int main(int argc, char *argv[])
{
    srand(time(NULL));
    cout << "Bem vindo ao campo minado em C++" << endl;
    // cout << "Informe o tamanho o mapa desejado" << endl;
    mapa mapa;
    mapa.quantidadeBombas = 40;
    mapa.sizeGrid = 40;

    // Inicializa o mapa com apenas zeros (0)
    mapa.grid              = vector<vector<char>>(mapa.sizeGrid, vector<char>(mapa.sizeGrid, '0'));
    mapa.coordenadasBombas = vector<vector<char>>(mapa.sizeGrid, vector<char>(mapa.sizeGrid, '0'));

    mapa = randomizarBombas(mapa);
    exibirMapa(mapa);
}

void listarPontuacoes(vector<int> pontuacoes)
{
    for (int i = 0; i < pontuacoes.size(); i++)
    {
        cout << "Código da pontuação: " << i << " Pontuação: " << pontuacoes[i] << "\n";
    }
}