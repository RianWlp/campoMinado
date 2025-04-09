#include <iostream>
#include <vector>
#include <ncurses.h>
#include <curses.h> // Essa lib é necessária caso for usar cores

using namespace std;

// g++ -o campoMinadoV2 campoMinadoV2.cpp -lncurses ; ./campoMinadoV2

int main(int argc, char *argv[])
{
    // Inicializa o ncurses
    initscr();            // Começa a janela ncurses
    cbreak();             // Desabilita o buffering de linha
    noecho();             // Não mostra as teclas digitadas
    keypad(stdscr, TRUE); // Habilita teclas como setas
    curs_set(0);          // Esconde o cursor

    // srand(time(NULL));
}




