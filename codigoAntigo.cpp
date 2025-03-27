#include <locale> //Importa a biblioteca de acentuação essa biblioteca não é necessária para o linux assim sendo necessária só para windows
 #include <iostream>
 #include <stdio.h>
 #include <cstdlib> //Importa a biblioteca de limpar a tela para o clear(System("cls"));
 #include <ctime>
 #include <string>
 #include <iostream>
 #include <time.h>
 
 using namespace std;
 
 // clear ; rm game ; g++ -o game game.cpp ; ./game
 
 void criarMapa()
 {
     string mapa[10][10];
 
     for (int i = 0; i < 10; i++)
     {
         for (int j = 0; j < 10; j++)
         {
             mapa[i][j] = criarBombas()+"";
             // mapa[i][j] = "0";
         }
     }
 
     for (int i = 0; i < 10; i++)
     {
         for (int j = 0; j < 10; j++)
         {
             cout << mapa[i][j] << " ";
         }
         cout << endl;
     }
 
     // for (auto *i : mapa)
     // {
     //     for (auto *j : mapa)
     //     {
     //         // cout << i.get() << endl;
     //         // cout << mapa;
     //         // mapa[i][j] = "0";
     //         // mapa[] = "0";
     //         // cout << "0 ";
     //     }
     //     cout << endl;
     // }
 };
 
 int criarBombas()
 {
 
     // Use current time as seed for random generator
 
 
     int numero;
     srand(time(0));
 
     for (int i = 0; i < 4; i++)
         numero = rand();
 
     return numero;
 };
 
 void verificarPosicao(){};
 
 int main()
 {
 
     cout << "Bem vindo ao campo minado em C++" << endl;
 
     criarMapa();
 
     return 0;
 }