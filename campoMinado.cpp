#include <iostream>
#include <vector>
using namespace std;

// Funções possivelmente uteis
void randomizarBombas(){}
void montarMapa(){}
void mostrarBombas() {}
void mostrarMapa() {}

// https://stackoverflow.com/questions/12375591/vector-of-vectors-to-create-matrix

int main(int argc, char *argv[])
{
    vector<vector<char> > mapa;

    return 0;
}

int randomizarValor()
{
    srand(time(NULL));
    return rand() % 100 + 1;
}

void listarPontuacoes(vector<int> pontuacoes)
{
    for (int i = 0; i < pontuacoes.size(); i++)
    {
        cout << "Código da pontuação: " << i << " Pontuação: " << pontuacoes[i] << "\n";
    }
}

int main(int argc, char *argv[])
{
    int opcao;
    int tamanho;
    vector<int> pontuacoes = {1, 4, 2, 3};

    do
    {
        cout
            << "\nEscolha uma opção:\n"
            << "1. Jogar\n"
            << "2. Ver histório de pontuações\n"
            << "3. Ver última pontuação\n"
            << "4. Remover pontuação deseja\n";

        cin >> opcao;
        switch (opcao)
        {
        case (1):
            pontuacoes.push_back(randomizarValor());
            break;
        case (2):
            listarPontuacoes(pontuacoes);
            break;
        case (3):
            tamanho = (pontuacoes.end() - pontuacoes.begin()) - 1;
            cout << "A sua última pontuação foi de " << pontuacoes[tamanho];
            break;
        case (4):
            int index;
            cout << "Escolha qual pontuação você deseja remover\n";
            cin >> index;
            if (pontuacoes[index])
            {
                pontuacoes.erase(pontuacoes.begin() + index);
                cout << "A pontuação de código " << index << " foi excluída\n";
            }
            break;
        default:
            cout << "Opção selecionada inválida, tente novamente\n";
            break;
        }

    } while (opcao != 5);
    return 0;
}
