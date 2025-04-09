#include <ncurses.h>
#include <iostream>
#include <vector>

using namespace std;

// Compilar
// g++ -o nCursesExemplo nCursesExemplo.cpp -lncurses ; ./nCursesExemplo

// O que você pode fazer:
// - Use as setas do teclado para mover o @.
// - Pressione q para sair.

int main()
{
    vector<string> log;
    int x = 10, y = 5; // Posição inicial
    int ch;
    int linha_log = 0;

    // Inicializa ncurses
    initscr();            // Começa a janela ncurses
    cbreak();             // Desabilita o buffering de linha
    noecho();             // Não mostra as teclas digitadas
    keypad(stdscr, TRUE); // Habilita teclas como setas
    curs_set(0);          // Esconde o cursor

    string tecla_str;

    // Sai com a tecla 'q')
    while ((ch = getch()) != 'q')
    {
        // clear(); // Limpa a tela a cada movimento
        // mvprintw(0, 0, "Teclas pressionadas (pressione 'q' para sair):");
        // for (size_t i = 0; i < log.size(); ++i)
        // {
        //     mvprintw(i + 1, 2, "- %s", log[i].c_str());
        // }

        // mvprintw(y, x, "@");         // Imprime o caractere na nova posição
        // mvwaddch(stdscr, 4, 4, 'X'); // Outra forma de imprimir na posição (0, 0)
        // refresh(); // Atualiza a tela

        // mvwaddch(stdscr, 4, 4, 'X'); // Outra forma de imprimir na posição (0, 0)
        tecla_str = "";
        if ((ch == KEY_ENTER) || (ch == '\n'))
        {
            // mvprintw(0, 0, "ENTER pressionado na posicao Y: %d, X: %d ", y, x);
            // mvprintw(x, y, "ENTER pressionado na posicao Y: %d, X: %d ", y, x);
            // move(y, x); // Volta cursor pra onde estava
            tecla_str = string("ASCII: ") + to_string(x)+" "+to_string(y);
            // tecla_str = string("ASCII: ") + to_string(getyx(stdscr, y, x)); // Pega posição do cursor

        }

        // mvwaddch(stdscr, y, x, ' '); // Limpa a posição anterior
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
            // default:
            //     tecla_str = string("ASCII: ") + to_string(ch);
        }

        // Adiciona ao log// Sai com a tecla 'q'
        log.push_back(tecla_str);

        clear();
        mvprintw(0, 0, "Teclas pressionadas (pressione 'q' para sair):");
        for (size_t i = 0; i < log.size(); ++i)
        {
            mvprintw(i + 1, 2, "- %s", log[i].c_str());
        }

        mvprintw(y, x, "@");         // Imprime o caractere na nova posição
        mvwaddch(stdscr, 4, 4, 'X'); // Outra forma de imprimir na posição (0, 0)
        refresh(); // Atualiza a tela
    }

    endwin(); // Encerra o modo ncurses
    return 0;
}