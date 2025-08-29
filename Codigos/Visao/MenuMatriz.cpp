#include <iostream>
#include <err.h>
#include <string>

#include "../EstruturaDeDados/Matriz/GrafoMatriz.h"
#include "../libs/io.hpp"

using namespace std;

class MenuMatriz {
   private:
    GrafoMatriz* grafo;

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
     * Cria um grafo e o armazena em 'grafo'. O grafo pode ser direcionado (1) ou nao direcionado
     * (2). Solicita ao usuario o numero de vertices e, se solicitado, as arestas do grafo.
     *
     * @throws invalid_argument Excecao lancada se o numero de vertices for invalido.
     */
    void intanciaGrafo() {
        try {
            int numVertices;
            int opcao = 0;

            do {
                cout << "Deseja contruir um grafo direcionado (1) ou nao direcionado (2)?" << endl;
                cin >> opcao;
                if (opcao != 1 && opcao != 2) {
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao != 1 || opcao != 2);

            do {
                cout << "Insira o numero de vertices: ";
                cin >> numVertices;
                if (numVertices <= 0) {
                    cout << "Opcao invalida!" << endl;
                    continue;
                }
                grafo = new GrafoMatriz(numVertices, opcao == 1);
            } while (numVertices <= 0);

            opcao = 0;
            do {
                cout << "Grafo criado com sucesso!" << endl;
                cout << "Deseja Adicionar Arestas (1) SIM ou (2) NAO?" << endl;
                cin >> opcao;
                if (opcao == 1) {
                    adicionaAresta();
                } else if (opcao != 2) {
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao != 2);

        } catch (exception& e) {
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
        do {
            cout << "Deseja adicionar um vertice (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao == 1) {
                grafo->adicionarVertice(grafo->getQuantidadeVertices());
            } else if (opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }

    /**
     * Adiciona uma nova aresta no grafo, caso os vértices sejam válidos.
     *
     * @note Os vértices são considerados válidos se estiverem no intervalo [0, numVertices).
     */
    void adicionaAresta() {
        int opcao = 0;
        do {
            cout << "Seu grafo possui as arestas: " << endl;
            grafo->imprimir();
            cout << "Deseja adicionar uma aresta entre quais vertices ?" << endl;
            int vertice1 = 0, vertice2 = 0;
            do {
                cout << "Do Vertice: ";
                cin >> vertice1;
                cout << "Para o Vertice: ";
                cin >> vertice1;
                if (vertice1 < 0 || vertice2 < 0 || vertice1 >= grafo->getQuantidadeVertices() ||
                    vertice2 >= grafo->getQuantidadeVertices()) {
                    cout << "Opcao invalida!" << endl;
                } else {
                    grafo->adicionarAresta(vertice1, vertice2);
                }
            } while (vertice1 < 0 || vertice2 < 0 || vertice1 >= grafo->getQuantidadeVertices() ||
                     vertice2 >= grafo->getQuantidadeVertices());

            cout << "De deseja adicionar outra aresta (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao != 1 && opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }

    /**
     * Remove um vértice do grafo.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void removeVertice() {
        int opcao = 0;
        cout << "Seu grafo possui os vertices: " << endl;
        grafo->imprimir();
        do {
            cout << "Deseja remover qual vertice?" << endl;
            int vertice1 = 0, vertice2 = 0;
            do {
                cout << "Do Vertice: ";
                cin >> vertice1;
                cout << "Para o Vertice: ";
                cin >> vertice1;
                if (vertice1 < 0 || vertice2 < 0 || vertice1 >= grafo->getQuantidadeVertices() ||
                    vertice2 >= grafo->getQuantidadeVertices()) {
                    cout << "Opcao invalida!" << endl;
                } else {
                    grafo->removerAresta(vertice1, vertice2);
                }
            } while (vertice1 < 0 || vertice2 < 0 || vertice1 >= grafo->getQuantidadeVertices() ||
                     vertice2 >= grafo->getQuantidadeVertices());
                     
            cout << "Deseja remover outra aresta (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao != 1 && opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }

    /**
     * Remove uma aresta do grafo.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void removeAresta() {
        int opcao = 0;
        cout << "Seu grafo possui as arestas: " << endl;
        grafo->imprimir();
        do {
            cout << "Deseja remover qual aresta?" << endl;
            cin >> opcao;
            if (opcao >= 0 && opcao < grafo->getQuantidadeVertices()) {
                grafo->removerVertice(opcao);
            } else {
                cout << "Opcao invalida!" << endl;
            }
            cout << "Deseja remover outro vertice (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao != 1 && opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }

    /**
     * Consulta os vértices adjacentes a um dado vértice.
     *
     * O usuário é questionado sobre qual vértice ele deseja consultar.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void consultaVazinhosVertice() {
        cout << "Seu grafo possui os vertices: " << endl;
        grafo->imprimir();
        int opcao = 0;
        do {
            cout << "Deseja ver os vertices adjacentes a qual vertice?" << endl;
            cin >> opcao;
            if (opcao >= 0 && opcao < grafo->getQuantidadeVertices()) {
                vector<int> vizinhos = grafo->getVizinhos(opcao);

                cout << "Os visinhos do vertice " << opcao << " sao: " << endl;
                cout << "Vizinhos: { ";
                for (int vizinho: vizinhos) {
                    cout << vizinho << ", ";
                }
                cout << "}" <<endl;
            } else {
                cout << "Opcao invalida!" << endl;
            }
            cout << "Deseja ver os vertices adjacentes a outro vertice (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao != 1 && opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }


    /**
     * Consulta os vértices sucessores a um dado vértice.
     *
     * O usuário é questionado sobre qual vértice ele deseja consultar.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void consultarSucessoresVertice() {
        cout << "Seu grafo possui os vertices: " << endl;
        grafo->imprimir();
        int opcao = 0;
        do {
            cout << "Deseja ver o fecho transitivo positivo de qual vertice?" << endl;
            cin >> opcao;
            if (opcao >= 0 && opcao < grafo->getQuantidadeVertices()) {
                vector<int> vizinhos = grafo->getSucessores(opcao);

                cout << "Os sucessores do vertice " << opcao << " sao: " << endl;
                cout << "sucessores: { ";
                for (int vizinho: vizinhos) {
                    cout << vizinho << ", ";
                }
                cout << "}" <<endl;
            } else {
                cout << "Opcao invalida!" << endl;
            }
            cout << "Deseja ver os vertices sucessores a outro vertice (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao != 1 && opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }

    /**
     * Consulta os vértices predecessores a um dado vértice.
     *
     * O usuário é questionado sobre qual vértice ele deseja consultar.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void consultarPredecessoresVertice() {
        cout << "Seu grafo possui os vertices: " << endl;
        grafo->imprimir();
        int opcao = 0;
        do {
            cout << "Deseja ver o fecho transitivo negativo de qual vertice?" << endl;
            cin >> opcao;
            if (opcao >= 0 && opcao < grafo->getQuantidadeVertices()) {
                vector<int> vizinhos = grafo->getPredecessores(opcao);

                cout << "Os predecessores do vertice " << opcao << " sao: " << endl;
                cout << "Predecessores: { ";
                for (int vizinho: vizinhos) {
                    cout << vizinho << ", ";
                }
                cout << "}" <<endl;
            } else {
                cout << "Opcao invalida!" << endl;
            }
            cout << "Deseja ver os vertices predecessores a outro vertice (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao != 1 && opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }




    /**
     * Remove o grafo.
     *
     * O usuário é questionado sobre se ele realmente deseja remover o grafo.
     *
     * @note Se o grafo for removido, o objeto que o contém (este) também
     *       será removido.
     */
    void removeGrafo() {
        int opcao = 0;
        do {
            cout << "Deseja realmente remiver o grafo (1) SIM ou (2) NAO ?" << endl;
            cin >> opcao;
            if (opcao == 1) {
                delete grafo;
            } else if (opcao != 2) {
                cout << "Opcao invalida!" << endl;
            }
        } while (opcao != 2);
    }

    
    /**
     * Imprime o grafo.
     *
     *@note  Chama a função imprimir do objeto do tipo GrafoMatriz que é
     * armazenado no atributo grafo.
     */
    void imprimeGrafo() {
        grafo->imprimir();
    }
};