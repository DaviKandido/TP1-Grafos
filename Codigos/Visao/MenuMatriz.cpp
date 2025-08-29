#include <iostream>
#include <string>

#include "../EstruturaDeDados/Matriz/GrafoMatriz.h"
#include "../libs/io.hpp"

using namespace std;

class MenuMatriz {
   public:
    GrafoMatriz* grafo;


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
                    intanciaGrafo();
                    break;

                case 2:
                    adicionaVertice();
                    break;

                case 3:
                    adicionaAresta();
                    break;

                case 4:
                    removeVertice();
                    break;

                case 5:
                    removeAresta();
                    break;

                case 6:
                    consultaVazinhosVertice();
                    break;

                case 7:
                    consultarSucessoresVertice();
                    break;

                case 8:
                    consultarPredecessoresVertice();
                    break;

                case 9:
                    removeGrafo();
                    break;

                case 10:
                    imprimeGrafo();
                    break;

                default:  // Vai funcionar para parar a função
                    cout << "Opção inválida!" << endl;
                    break;
            }

        } while (opcao != 0);
    }


    /**
     * Cria um grafo e o armazena em 'grafo'. O grafo pode ser direcionado (1) ou nao direcionado (2).
     * Solicita ao usuario o numero de vertices e, se solicitado, as arestas do grafo.
     * 
     * @throws invalid_argument Excecao lancada se o numero de vertices for invalido.
     */
    void intanciaGrafo() {
        try{
            int numVertices;
            int opcao = 0;

            do{
                cout << "Deseja contruir um grafo direcionado (1) ou nao direcionado (2)?" << endl;
                cin >> opcao;
                if(opcao != 1 && opcao != 2){
                    cout << "Opcao invalida!" << endl;
                }
            }while (opcao != 1 || opcao != 2);
            
    
            do{
                cout << "Insira o numero de vertices: ";
                cin >> numVertices;
                if(numVertices <= 0){
                    cout << "Opcao invalida!" << endl;
                    continue;
                }
                grafo = new GrafoMatriz(numVertices, opcao == 1);
            }while(numVertices <= 0);
            
            opcao = 0;
            do{
                cout << "Grafo criado com sucesso!" << endl;
                cout << "Deseja Adicionar Arestas (1) SIM ou (2) NAO?" << endl;
                cin >> opcao;
                if (opcao == 1){
                    adicionaAresta();
                }else (opcao != 2){
                    cout << "Opcao invalida!" << endl;
                }
            }while (opcao != 2);
            
        }catch (invalid_argument e){
            cout << e.what() << endl;
        }
    }

    /**
     * Adiciona um novo vértice no grafo, caso o vértice seja válido.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void adicionaVertice() {
        int opcao = 0;
        grafo->getQuantidadeVertices();
        do{
            cout << "Deseja adicionar um vertice (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if(opcao == 1){
                grafo->adicionarVertice(grafo->getQuantidadeVertices());
            }else if(opcao != 2){
                cout << "Opcao invalida!" << endl;
            }
        }while (opcao != 2);
    }

    void adicionaAresta() {}

    void removeVertice() {}

    void removeAresta() {}

    void consultaVazinhosVertice() {}

    void consultarSucessoresVertice() {}

    void consultarPredecessoresVertice() {}

    void removeGrafo() {}

    void imprimeGrafo() {}
};