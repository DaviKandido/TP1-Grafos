#include <iostream>
#include <string>

#include "../EstruturaDeDados/Matriz/GrafoMatriz.h"
#include "../libs/io.hpp"

using namespace std;

class MenuMatriz {
   public:
    GrafoMatriz* grafo;

    void menu() {
        int opcao = 0;
        do {
            cout << "> Menu > Matriz" << endl << endl;
            cout << "1) Instanciar Grafo (Matriz) " << endl;
            cout << "2) Adicionar Vértice" << endl;
            cout << "3) Adicionar Aresta" << endl;
            cout << "4) Remover Vértice" << endl;
            cout << "5) Remover Aresta" << endl;
            cout << "6) Consultar Vazinhos de um Vértice" << endl;
            cout << "7) Consultar Sucessores de um Vértice - DFS" << endl;
            cout << "8) Consultar Predecessores de um Vértice - DFS" << endl;
            cout << "9) Remover Grafo" << endl;
            cout << "10) Imprimir Grafo" << endl;
            cout << "0) - Sair" << endl << endl;

            cout << "Opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    /* code */
                    break;

                case 2:
                    /* code */
                    break;

                case 3:
                    /* code */
                    break;

                case 4:
                    /* code */
                    break;

                case 5:
                    /* code */
                    break;

                case 6:
                    /* code */
                    break;

                case 7:
                    /* code */
                    break;

                case 8:
                    /* code */
                    break;

                case 9:
                    /* code */
                    break;

                case 10:
                    /* code */
                    break;

                default:  // Vai funcionar para parar a função
                    break;
            }

        } while (opcao != 0);
    }

    void intanciaGrafo() {}

    void adicionaVertice() {}

    void adicionaAresta() {}

    void removeVertice() {}

    void removeAresta() {}

    void consultaVazinhosVertice() {}

    void consultarSucessoresVertice() {}

    void consultarPredecessoresVertice() {}

    void removeGrafo() {}

    void imprimeGrafo() {}
};