#include "../libs/io.hpp"
#include "../EstruturaDeDados/Matriz/GrafoMatriz.h"
#include <iostream>
#include <string> 

using namespace std;

class MenuMatriz{
    
    public: 
        GrafoMatriz* grafo;

        void menu() {
            int opcao = 0;

            cout << "> Menu > Matriz" << endl << endl;
            cout << "1) Instanciar Grafo (Matriz) " << endl;
            cout << "2) Adicionar Vértice" << endl;
            cout << "3) Adicionar Aresta" << endl;
            cout << "4) Remover Vértice" << endl;
            cout << "5) Remover Aresta" << endl;
            cout << "6) Consultar Vasinhos de um Vértice" << endl;
            cout << "7) Consultar Sucessores de um Vértice - DFS" << endl;
            cout << "8) Consultar Predecessores de um Vértice - DFS" << endl;
            cout << "9) Remover Grafo" << endl;
            cout << "10) Imprimir Grafo" << endl;
            cout << "0) - Sair" << endl << endl;

            cout << "Opção: ";
            string linha;
            getline(cin, linha);
            opcao = stoi(linha);

        }
        

};