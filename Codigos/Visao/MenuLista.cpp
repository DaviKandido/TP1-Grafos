#include <iostream>
#include <string>

#include "../EstruturaDeDados/Lista/GrafoLista.cpp"
#include "MyIO.cpp"

using namespace std;
#define maxVertice 2147483647

class MenuLista {
   public:
    GrafoLista* grafo;

    /**
     * Menu de operações para manipular o grafo.
     *
     * Pergunta ao usuario qual opção ele deseja fazer, dependendo da escolha,
     * chama a respectiva função para realizar a operação que desejada.
     *
     * @see intanciaGrafo()
     * @see adicionaVertice()
     * @see adicionaAresta()
     * @see removeVertice()
     * @see removeAresta()
     * @see consultaVizinhosVertice()
     * @see consultarSucessoresVertice()
     * @see consultarPredecessoresVertice()
     * @see removeGrafo()
     * @see imprimeGrafo()
     */

    void menu() {
        int opcao = -1;
        while (opcao != 0) {
            cout << "> Menu > Lista" << endl << endl;
            cout << "1) Instanciar Grafo" << endl;
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
                    consultaVizinhosVertice();
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
                case 0:
                    cout << "Obrigado pela preferencia!";
                    break;
                default:
                    cout << "Opção inválida!" << endl;
                    cout << "Porfavor escolha uma das opções a baixo" << endl;
                    break;
            }
        }
    }

    /**
     * Cria um grafo e o armazena em 'grafo'. O grafo pode ser direcionado ou não-direcionado,
     * ponderado ou não ponderado e rotulado ou não rotulado.
     */
    void intanciaGrafo() {
        cout << "\n> Menu > Lista > Instanciar Grafo" << endl << endl;

        // Atributo do grafo
        int numVertices;

        // Variáveis de controle
        bool simples;
        bool direcionado;
        bool verticePonderado;
        bool arestaPonderada;
        bool verticeRotulado;
        bool arestaRotulada;

        // Ler as informações do usuário
        numVertices = lerInteiro("Número de vértices: ", 1, maxVertice);

        simples = lerBoolean("O grafo é simples?      (S/N): ");
        direcionado = lerBoolean("O grafo é direcionado?      (S/N): ");
        verticePonderado = lerBoolean("Os vértices são ponderados? (S/N): ");
        arestaPonderada = lerBoolean("As arestas são ponderadas?  (S/N): ");
        verticeRotulado = lerBoolean("Os vértices são rotulados?  (S/N): ");
        arestaRotulada = lerBoolean("As arestas são rotuladas?   (S/N): ");
        // Aqui ainda ta faltando implementar o GrafoLista
        this->grafo = new GrafoLista(simples, direcionado, verticePonderado, arestaPonderada,
                                     verticeRotulado, arestaRotulada, numVertices);
    }

    void adicionaVertice() {
        cout << "\n> Menu > Lista > Adicionar Vértice" << endl << endl;

        // Variaveis nas suas formas padrão caso seja não rotulado e não ponderado
        string rotulo = "";
        int peso = 1;
        // teste de ponderado e de rotulo
        if (grafo->verticeRotulado == 1) {
            rotulo = lerRotulo("Rótulo do vértice: ");
        }

        if (grafo->verticePonderado == 1) {
            rotulo = lerInteiro("Peso do vértice: ", (0 - maxVertice), maxVertice);
        }

        Vertice novo(grafo->numVertices, peso, rotulo);
        if (grafo->adicionarVertice(novo)) {
            cout << "vertice removido com sucesso" << endl;
        } else
            cout << "Houve um erro" << endl;
    }

    void adicionaAresta() {
        cout << "\n> Menu > Lista > Adicionar Aresta" << endl << endl;

        // Variaveis nas suas formas padrão caso seja não rotulado e não ponderado
        string rotulo = "";
        int peso = 1;
        // Variaveis para indicar qual vertice o usario deseja
        int inicio;
        int fim;
        grafo->imprimir();
        // pegando a posição dos vertices na Lista
        cout << "Digite o numero que aparece na frente da linha";
        inicio =
            lerInteiro("Digite o número do vértice de saida: ", 0, grafo->getQuantidadeVertices());
        fim = lerInteiro("Digite o número do vértice de chegada: ", 0,
                         grafo->getQuantidadeVertices());

        // teste de ponderado e de rotulo
        if (grafo->arestaRotulada == 1) {
            rotulo = lerRotulo("Rótulo da aresta: ");
        }

        if (grafo->arestaPonderada == 1) {
            peso = lerInteiro("Peso da aresta: ", (0 - maxVertice), maxVertice);
        }
        // O vertice esta dentro da listaPrincipal que é feita de NoVertice e dentro do Novertice
        // que esta o vertice
        Vertice inicioV = grafo->listaPrincipal[inicio].vertice;
        Vertice fimV = grafo->listaPrincipal[fim].vertice;
        if (grafo->adicionarAresta(inicioV, fimV, peso, rotulo)) {
            cout << "aresta adicionada com sucesso" << endl;
        } else
            cout << "Houve um erro" << endl;
    }

    void removeVertice() {
        cout << "\n> Menu > Lista > Remover Vértice" << endl << endl;
        // Variavel para indicar a posição do vertice no array
        int vertice;

        grafo->imprimir();
        // pegando a posição dos vertices na Lista
        vertice = lerInteiro("Digite o número do vértice que deseja remover", 0,
                             grafo->getQuantidadeVertices());
        // O vertice esta dentro da listaPrincipal que é feita de NoVertice e dentro do Novertice
        // que esta o vertice
        Vertice inicioV = grafo->listaPrincipal[vertice].vertice;
        if (grafo->removerVertice(inicioV)) {
            cout << "vertice removido com sucesso" << endl;
        } else
            cout << "Houve um erro" << endl;
    }

    void removeAresta() {
        cout << "\n> Menu > Lista > Remover Aresta" << endl << endl;
        // Variaveis para indicar qual vertice o usario deseja
        int inicio;
        int fim;
        grafo->imprimir();
        // pegando a posição dos vertices na Lista
        cout << "Digite o numero que aparece na frente da linha";
        inicio =
            lerInteiro("Digite o número do vértice de saida: ", 0, grafo->getQuantidadeVertices());
        fim = lerInteiro("Digite o número do vértice de chegada: ", 0,
                         grafo->getQuantidadeVertices());

        // O vertice esta dentro da listaPrincipal que é feita de NoVertice e dentro do Novertice
        // que esta o vertice
        Vertice inicioV = grafo->listaPrincipal[inicio].vertice;
        Vertice fimV = grafo->listaPrincipal[fim].vertice;
        if (grafo->removerAresta(inicioV, fimV)) {
            cout << "aresta removida com sucesso" << endl;
        } else
            cout << "Houve um erro" << endl;
    }

    void consultaVizinhosVertice() {
        cout << "\n> Menu > Lista > Consultar Vizinhos de Vértice" << endl << endl;

        // Variavel para indicar a posição do vertice no array
        int verticei;

        grafo->imprimir();

        // pegando a posição dos vertices na Lista
        verticei = lerInteiro("Digite o número do vértice que deseja remover", 0,
                              grafo->getQuantidadeVertices());

        // O vertice esta dentro da listaPrincipal que é feita de NoVertice e dentro do Novertice
        // que esta o vertice
        Vertice inicioV = grafo->listaPrincipal[verticei].vertice;

        vector<Vertice> vizinho = grafo->getVizinhos(inicioV);
        if (vizinho.empty()) {
            cout << "Sem vizinhos\n";
        } else {
            for (const Vertice& v : vizinho) {
                cout << "ID=" << v.getId() << " | Peso=" << v.getPeso()
                     << " | Rotulo=" << v.getRotulo() << '\n';
            }
        }
    }

    void consultarSucessoresVertice() {
        cout << "\n> Menu > Lista > Consultar Fecho Transitivo Direto de Vértice" << endl << endl;
           // Variavel para indicar a posição do vertice no array
        int verticei;

        grafo->imprimir();

        //pegando a posição dos vertices na Lista
        verticei = lerInteiro("Digite o número do vértice que deseja remover", 0,grafo->getQuantidadeVertices());

        //O vertice esta dentro da listaPrincipal que é feita de NoVertice e dentro do Novertice que esta o vertice
        Vertice inicioV = grafo->listaPrincipal[verticei].vertice;
        
        vector<Vertice> vizinho = grafo->fechoTransitivoDireto(inicioV);
        if (vizinho.empty()) {
            cout << "Sem vizinhos\n";
        } else {
            for (const Vertice& v : vizinho) {
                cout << "ID=" << v.getId() << " | Peso=" << v.getPeso() << " | Rotulo=" << v.getRotulo() << '\n';
            }
        }
    }

    void consultarPredecessoresVertice() {
        cout << "\n> Menu > Lista > Consultar Fecho Transitivo Inverso de Vértice" << endl << endl;
           // Variavel para indicar a posição do vertice no array
        int verticei;

        grafo->imprimir();

        //pegando a posição dos vertices na Lista
        verticei = lerInteiro("Digite o número do vértice que deseja remover", 0,grafo->getQuantidadeVertices());

        //O vertice esta dentro da listaPrincipal que é feita de NoVertice e dentro do Novertice que esta o vertice
        Vertice inicioV = grafo->listaPrincipal[verticei].vertice;
        
        vector<Vertice> vizinho = grafo->fechoTransitivoInverso(inicioV);
        if (vizinho.empty()) {
            cout << "Sem vizinhos\n";
        } else {
            for (const Vertice& v : vizinho) {
                cout << "ID=" << v.getId() << " | Peso=" << v.getPeso() << " | Rotulo=" << v.getRotulo() << '\n';
    
            }
        }
    }

    void removeGrafo() {
        cout << "\n> Menu > Lista > Remover Grafo" << endl << endl;

        bool controle = lerBoolean("Você confirma a exclusão do grafo? (S/N): ");

        if (controle) {
            delete grafo;
            grafo = NULL;
            cout << "\nGrafo removido com sucesso." << endl;
        }
    }

    void imprimeGrafo() {
        grafo->imprimir();
    }
};
