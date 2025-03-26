#include <iostream>
#include <vector>
using namespace std;

// Regras campo minado

/**
O Campo Minado é um jogo clássico de lógica, onde o objetivo é revelar todas as células seguras de um tabuleiro sem clicar em uma mina. Aqui estão as regras principais:

Regras do Campo Minado
Tabuleiro:

O jogo ocorre em uma grade (geralmente quadrada) de células ocultas.

Algumas dessas células contêm minas, outras estão vazias.

- Objetivo:
Revelar todas as células que não contêm minas.
Se você revelar todas as células seguras, você vence o jogo.

- Como jogar:
O jogador clica em uma célula para revelá-la.
Se a célula contiver uma mina, o jogo termina e o jogador perde.
Se a célula estiver vazia, um número pode aparecer, indicando quantas minas existem nas células adjacentes (horizontais, verticais e diagonais).
Se a célula não tiver minas ao redor (número 0), todas as células vizinhas são automaticamente reveladas.

- Marcando minas:
O jogador pode marcar células onde acredita que há minas usando uma bandeira.
Isso ajuda a evitar cliques acidentais em minas.

- Vitória e Derrota:
Vitória: O jogador vence ao revelar todas as células seguras, sem tocar em nenhuma mina.
Derrota: O jogo termina imediatamente se o jogador clicar em uma mina.

- Dicas e Estratégias:
O primeiro clique nunca será uma mina.
Use os números revelados para deduzir onde estão as minas.
Marque as minas suspeitas com bandeiras para não esquecê-las.
Se houver incerteza, tente minimizar os riscos ao escolher uma célula para revelar.

Essas são as regras básicas do jogo, mas algumas variações incluem tabuleiros maiores, diferentes quantidades de minas e modos de dificuldade variados.e
*/

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
            tamanho = (pontuacoes.end() - pontuacoes.begin()) -1;
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
