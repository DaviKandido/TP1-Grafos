#include <iostream>
#include <err.h>
#include <string>
#include <limits>

#include "../EstruturaDeDados/Matriz/GrafoMatriz.cpp"
#include "MyIO.cpp"
#include "../libs/io.hpp"

using namespace std;

class MenuMatriz {
   private:
    GrafoMatriz* grafo;
    private:
        const int limiteMaximo = 100;
        GrafoMatriz* grafo;

    public:
       public:
    /**
     * Menu de op es para manipular o grafo.
     *
     * Pergunta ao usuario qual opção ele deseja fazer, dependendo da escolha,
     * chama a respectiva função para realizar a operação que desejada.
     *
     * @see intanciaGrafo()
     * @see adicionaVertice()
     * @see adicionaAresta()
     * @see removeVertice()
     * @see removeAresta()
     * @see consultaVazinhosVertice()
     * @see consultarSucessoresVertice()
     * @see consultarPredecessoresVertice()
     * @see removeGrafo()
     * @see imprimeGrafo()
     */
    void menu() {
            int opcao = 0;
            do {
                cout << "\n> Menu > Matriz" << endl << endl;
                cout << "1) Instanciar Grafo" << endl;
                cout << "2) Adicionar Vértice" << endl;
                cout << "3) Adicionar Aresta" << endl;
                cout << "4) Remover Vértice" << endl;
                cout << "5) Remover Aresta" << endl;
                cout << "6) Consultar Vizinhos de um Vértice" << endl;
                cout << "7) Consultar Sucessores de um Vértice - DFS" << endl;
                cout << "8) Consultar Predecessores de um Vértice - DFS" << endl;
                cout << "9) Imprimir Grafo" << endl;
                cout << "10) Remover Grafo" << endl;
                cout << "0) Sair" << endl << endl;

                opcao = lerInteiroPositivo("Opção: ", 0, 10);

                switch (opcao) {
                    case 1:
                        intanciaGrafo(); break;
                    case 2:
                        adicionaVertice(); break;
                    case 3:
                        adicionaAresta(); break;
                    case 4:
                        removeVertice(); break;
                    case 5:
                        removeAresta(); break;
                    case 6:
                        consultaVazinhosVertice(); break;
                    case 7:
                        consultarSucessoresVertice(); break;
                    case 8:
                        consultarPredecessoresVertice(); break;
                    case 9:
                        imprimeGrafo(); break;
                    case 10:
                        removeGrafo(); break;
                    case 0:                
                        cout << "Saindo..." << endl; cin.get(); break;
                    default:
                        cout << "Opção inválida!" << endl; break;
                }
                cin.get();
            } while (opcao != 0);
        }

        void intanciaGrafo() {
            cout << "\n> Menu > Matriz > Instanciar Grafo" << endl << endl;

            // Atributo do grafo
            int numVertices;

            // Variáveis de controle
            bool direcionado;
            bool verticePonderado;
            bool arestaPonderada;
            bool verticeRotulado;
            bool arestaRotulada;

            // Ler as informações do usuário
            numVertices = lerInteiroPositivo("Número de vértices: ", 1, limiteMaximo);
            direcionado =      lerBoolean("O grafo é direcionado?      (S/N): ");
            verticePonderado = lerBoolean("Os vértices são ponderados? (S/N): ");
            arestaPonderada =  lerBoolean("As arestas são ponderadas?  (S/N): ");
            verticeRotulado =  lerBoolean("Os vértices são rotulados?  (S/N): ");
            arestaRotulada =   lerBoolean("As arestas são rotuladas?   (S/N): ");
            
            // Criar a instância do grafo
            this->grafo = new GrafoMatriz(numVertices, direcionado, verticePonderado, arestaPonderada, verticeRotulado, arestaRotulada);
        }

        void adicionaVertice() {
            cout << "\n> Menu > Matriz > Adicionar Vértice" << endl << endl;
        }

        void adicionaAresta() {
            cout << "\n> Menu > Matriz > Adicionar Aresta" << endl << endl;
        }

        void removeVertice() {
            cout << "\n> Menu > Matriz > Remover Vértice" << endl << endl;
        }

        void removeAresta() {
            cout << "\n> Menu > Matriz > Remover Aresta" << endl << endl;
        }

        void consultaVazinhosVertice() {
            cout << "\n> Menu > Matriz > Consultar Vizinhos de Vértice" << endl << endl;
        }

        void consultarSucessoresVertice() {
            cout << "\n> Menu > Matriz > Consultar Sucessores de Vértice" << endl << endl;
        }

        void consultarPredecessoresVertice() {
            cout << "\n> Menu > Matriz > Consultar Predecessores de Vértice" << endl << endl;
        }
        
        void imprimeGrafo() {
            cout << "\n> Menu > Matriz > Imprimir Grafo" << endl << endl;
        }

        void removeGrafo() {
            cout << "\n> Menu > Matriz > Remover Grafo" << endl << endl;
        }
};