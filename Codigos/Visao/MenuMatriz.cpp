#include <iostream>
#include <limits>
#include <string>

#include "../EstruturaDeDados/Matriz/GrafoMatriz.cpp"
#include "../libs/io.hpp"
#include "MyIO.cpp"

using namespace std;

class MenuMatriz {
   private:
    GrafoMatriz* grafo;

   private:
    const int limiteVertice = 100;
    const int limitePeso = 100;

   public:
    /**
     * Menu de op es para manipular o grafo.
     *
     * Pergunta ao usuario qual opção ele deseja fazer, dependendo da escolha,
     * chama a respectiva função para realizar a operação que desejada.
     *
     * @see intanciaGrafo()
     * @see criaGrafoTeste()
     * @see adicionaVertice()
     * @see adicionaAresta()
     * @see removeVertice()
     * @see removeAresta()
     * @see consultaVizinhosVertice()
     * @see consultarFechoTransitivoDireto()
     * @see consultarFechoTransitivoInverso()
     * @see buscaProfundidade()
     * @see removeGrafo()
     * @see imprimeGrafo()
     */
    void menu() {
        int opcao = 0;
        do {
            cout << "\n> Menu > Matriz" << endl << endl;
            cout << "1) Instanciar Grafo" << endl;
            cout << "2) Criar grafo de teste" << endl;
            cout << "3) Adicionar Vértice" << endl;
            cout << "4) Adicionar Aresta" << endl;
            cout << "5) Remover Vértice" << endl;
            cout << "6) Remover Aresta" << endl;
            cout << "7) Consultar Vizinhos de um Vértice" << endl;
            cout << "8) Fecho Transitivo Direto de um Vértice" << endl;
            cout << "9) Fecho Transitivo Inverso de um Vértice" << endl;
            cout << "10) Busca em Profundidade - DFS" << endl;
            cout << "11) Imprimir Grafo" << endl;
            cout << "12) Remover Grafo" << endl;
            cout << "0) Sair" << endl << endl;

            opcao = lerInteiro("Opção: ", 0, 12);

            switch (opcao) {
                case 1:
                    intanciaGrafo();
                    break;
                case 2:
                    criarGrafoPadrao();
                    break;
                case 3:
                    if (grafoInstanciado()) adicionaVertice();
                    break;
                case 4:
                    if (grafoInstanciado()) adicionaAresta();
                    break;
                case 5:
                    if (grafoInstanciado()) removeVertice();
                    break;
                case 6:
                    if (grafoInstanciado()) removeAresta();
                    break;
                case 7:
                    if (grafoInstanciado()) consultaVizinhosVertice();
                    break;
                case 8:
                    if (grafoInstanciado()) consultarFechoTransitivoDireto();
                    break;
                case 9:
                    if (grafoInstanciado()) consultarFechoTransitivoInverso();
                    break;
                case 10:
                    if (grafoInstanciado()) buscaProfundidade();
                    break;
                case 11:
                    if (grafoInstanciado()) imprimeGrafo();
                    break;
                case 12:
                    if (grafoInstanciado()) removeGrafo();
                    break;
                case 0:
                    cout << "\nSaindo..." << endl << endl;
                    break;
                default:
                    cout << "\nOpção inválida!" << endl;
                    break;
            }
        } while (opcao != 0);
    }

    bool grafoInstanciado() {
        if (grafo == null) cout << "\n[ERRO]: O grafo não está instanciado." << endl;
        return grafo != null;
    }

    /**
     * Cria um grafo e o armazena em 'grafo'. O grafo pode ser direcionado ou não-direcionado,
     * ponderado ou não ponderado e rotulado ou não rotulado.
     */
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
        numVertices = lerInteiro("Número de vértices: ", 1, limiteVertice);

        direcionado = lerBoolean("O grafo é direcionado?      (S/N): ");
        verticePonderado = lerBoolean("Os vértices são ponderados? (S/N): ");
        arestaPonderada = lerBoolean("As arestas são ponderadas?  (S/N): ");
        verticeRotulado = lerBoolean("Os vértices são rotulados?  (S/N): ");
        arestaRotulada = lerBoolean("As arestas são rotuladas?   (S/N): ");

        // Criar a instância do grafo
        this->grafo = new GrafoMatriz(numVertices, direcionado, verticePonderado, arestaPonderada,
                                      verticeRotulado, arestaRotulada);
    }

    /**
     * Adiciona um novo vértice no grafo, caso o vértice seja válido.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void adicionaVertice() {
        cout << "\n> Menu > Matriz > Adicionar Vértice" << endl << endl;

        // Imprimir o grafo
        grafo->imprimir();

        // Informações do vértice
        int numero = grafo->getQuantidadeVertices() + 1;
        int peso = 1;       // Peso padrão é 1
        string label = "";  // Rótulo padrão é string vazia

        // Ler o peso do vértice
        if (grafo->verticePonderado) {
            peso = lerInteiro("Peso do vértice: ", (0 - limitePeso), limitePeso);
        }

        // Ler o rótulo do vértice
        if (grafo->verticeRotulado) {
            label = lerRotulo("Rótulo do vértice: ");
        }

        // Inserir o vértice
        if (!grafo->adicionarVertice(numero, peso, label))
            cout << "\n[ERRO]: Não foi possível inserir o vértice. Tente novamente." << endl;
        else if (!grafo->verticePonderado && !grafo->verticeRotulado)
            cout << "\nO vértice " << numero << " foi criado com sucesso!" << endl;
        else if (grafo->verticePonderado && !grafo->verticeRotulado)
            cout << "\nO vértice " << numero << ", com peso " << peso << ", foi criado com sucesso!"
                 << endl;
        else if (!grafo->verticePonderado && grafo->verticeRotulado)
            cout << "\nO vértice " << numero << ", com rótulo '" << label
                 << "', foi criado com sucesso!" << endl;
        else
            cout << "\nO vértice " << numero << ", com peso " << peso << " e rótulo '" << label
                 << "', foi criado com sucesso!" << endl;
    }

    /**
     * Adiciona uma nova aresta no grafo, caso os vértices sejam válidos.
     *
     * @note Os vértices são considerados válidos se estiverem no intervalo [0, numVertices).
     */
    void adicionaAresta() {
        cout << "\n> Menu > Matriz > Adicionar Aresta" << endl << endl;

        // Imprimir o grafo
        grafo->imprimir();

        // Informações da aresta
        int peso = 1;       // Peso padrão é 1
        string label = "";  // Rótulo padrão é string vazia
        int origem, destino;

        // Ler os vértices de origem e de destino
        origem =
            lerInteiro("Digite o número do vértice de origem: ", 0, grafo->getQuantidadeVertices());
        destino = lerInteiro("Digite o número do vértice de destino: ", 0,
                             grafo->getQuantidadeVertices());

        // Ler o peso da aresta
        if (grafo->arestaPonderada) {
            peso = lerInteiro("Peso da aresta: ", (0 - limitePeso), limitePeso);
        }

        // Ler o rótulo da aresta
        if (grafo->verticeRotulado) {
            label = lerRotulo("Rótulo da aresta: ");
        }

        // Inserir a aresta
        if (!grafo->adicionarAresta(origem, destino, peso, label))
            cout << "\n[ERRO]: Não foi possível adicionar a aresta. Tente novamente." << endl;
        else if (!grafo->arestaPonderada && !grafo->arestaRotulada)
            cout << "\nA aresta foi criada com sucesso!" << endl;
        else if (grafo->arestaPonderada && !grafo->arestaRotulada)
            cout << "\nA aresta, com peso " << peso << ", foi criada com sucesso!" << endl;
        else if (!grafo->arestaPonderada && grafo->arestaRotulada)
            cout << "\nA aresta, com rótulo '" << label << "', foi criada com sucesso!" << endl;
        else
            cout << "\nA aresta, com peso " << peso << " e rótulo '" << label
                 << "', foi criada com sucesso!" << endl;
    }

    /**
     * Remove um vértice do grafo.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void removeVertice() {
        cout << "\n> Menu > Matriz > Remover Vértice" << endl << endl;
    }

    /**
     * Remove uma aresta do grafo.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void removeAresta() {
        cout << "\n> Menu > Matriz > Remover Aresta" << endl << endl;

        // Imprimir o grafo
        grafo->imprimir();

        // Informações da aresta
        int origem, destino;

        // Ler os vértices de origem e de destino
        origem =
            lerInteiro("Digite o número do vértice de origem: ", 0, grafo->getQuantidadeVertices());
        destino = lerInteiro("Digite o número do vértice de destino: ", 0,
                             grafo->getQuantidadeVertices());

        // Remover a aresta
        if (!grafo->removerAresta(origem, destino))
            cout << "\n[ERRO]: Não foi possível remover a aresta. Tente novamente" << endl;
        else
            cout << "\nA aresta entre " << origem << " e " << destino
                 << " foi removida com sucesso." << endl;
    }

    /**
     * Consulta os vértices adjacentes de um dado vértice.
     *
     * O usuário é questionado sobre qual vértice ele deseja consultar.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void consultaVizinhosVertice() {
        cout << "\n> Menu > Matriz > Consultar Vizinhos de Vértice" << endl << endl;

        grafo->imprimir();

        int opcao = lerInteiro("Deseja ver os vértice adjacentes a qual vértice? ", 0,
                               (grafo->getQuantidadeVertices() - 1));

        vector<int> vizinhos = grafo->getVizinhos(opcao);

        cout << "\nVizinhos: { ";
        for (int vizinho : vizinhos) {
            cout << vizinho << " ";
        }
        cout << "}" << endl;
    }

    /**
     * Consulta os vértices descendentes de um dado vértice.
     *
     * O usuário é questionado sobre qual vértice ele deseja consultar.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void consultarFechoTransitivoDireto() {
        cout << "\n> Menu > Matriz > Consultar Fecho Transitivo Direto de Vértice" << endl << endl;

        grafo->imprimir();

        int opcao = lerInteiro("Deseja ver o Fecho Transitivo Direto de qual vértice? ", 0,
                               (grafo->getQuantidadeVertices() - 1));

        vector<int> descendentes = grafo->fechoTransitivoDireto(opcao);

        cout << "\n{ ";
        for (int descendente : descendentes) {
            cout << descendente << " ";
        }
        cout << "}" << endl;
    }

    /**
     * Consulta os vértices ancestrais de um dado vértice.
     *
     * O usuário é questionado sobre qual vértice ele deseja consultar.
     *
     * @note O vértice é considerado válido se estiver no intervalo [0, numVertices).
     */
    void consultarFechoTransitivoInverso() {
        cout << "\n> Menu > Matriz > Consultar Fecho Transitivo Inverso de Vértice" << endl << endl;

        grafo->imprimir();

        int opcao = lerInteiro("Deseja ver o Fecho Transitivo Inverso de qual vértice? ", 0,
                               (grafo->getQuantidadeVertices() - 1));

        vector<int> ancestrais = grafo->fechoTransitivoInverso(opcao);

        cout << "\n{ ";
        for (int ancestral : ancestrais) {
            cout << ancestral << " ";
        }
        cout << "}" << endl;
    }

    void buscaProfundidade() {
        cout << "\n> Menu > Matriz > Busca em Profundidade" << endl << endl;

        grafo->imprimir();

        int opcao = lerInteiro("Deseja Fazer uma busca em profundidade a partir de qual vértice? ",
                               0, (grafo->getQuantidadeVertices() - 1));

        vector<vector<int>> tempos = grafo->buscaEmProfundidade(opcao);

        cout << "Tempos: { ";
        for (int i = 0; i < grafo->getQuantidadeVertices(); i++) {
            cout << "\n Vertice[" << i << "] = " << tempos[i][0] << " - " << tempos[i][1] << " ";
        }

        cout << "\n}" << endl;
    }
    /**
     * Imprime o grafo.
     *
     *@note  Chama a função imprimir do objeto do tipo GrafoMatriz que é armazenado no atributo
     *grafo.
     */
    void imprimeGrafo() {
        cout << "\n> Menu > Matriz > Imprimir Grafo" << endl << endl;

        grafo->imprimir();
    }

    /**
     * Remove o grafo.
     *
     * O usuário é questionado sobre se ele realmente deseja remover o grafo.
     *
     * @note Se o grafo for removido, o objeto que o contém (este) também será removido.
     */
    void removeGrafo() {
        cout << "\n> Menu > Matriz > Remover Grafo" << endl << endl;

        bool controle = lerBoolean("Você confirma e exclusão do grafo? (S/N): ");

        if (controle) {
            delete grafo;
            grafo = null;
            cout << "\nGrafo removido com sucesso." << endl;
        }
    }

    /*
     * Cria um grafo padrão para facilitar os testes.
     */
    void criarGrafoPadrao() {
        // Testar se já existe um grafo instanciado
        if (this->grafo != null) {
            cout << "\n Já existe um grafo instanciado!" << endl;
            return;
        }

        // Atributos do grafo
        int numVertices = 4;

        // Variáveis de controle
        bool direcionado = true;
        bool verticePonderado = false;
        bool arestaPonderada = false;
        bool verticeRotulado = true;
        bool arestaRotulada = true;

        // Criar o grafo
        this->grafo = new GrafoMatriz(numVertices, direcionado, verticePonderado, arestaPonderada,
                                      verticeRotulado, arestaRotulada);

        // Adiciona rótulos aos vértices
        this->grafo->adicionarVertice(0, "A");
        this->grafo->adicionarVertice(1, "B");
        this->grafo->adicionarVertice(2, "C");
        this->grafo->adicionarVertice(3, "D");

        // Adiciona arestas com rótulos
        this->grafo->adicionarAresta(0, 1, 1, "Rua 1");
        this->grafo->adicionarAresta(0, 2, 1, "Rua 2");
        this->grafo->adicionarAresta(1, 2, 1, "Avenida Principal");
        this->grafo->adicionarAresta(2, 3, 1, "Ponte");

        cout << "\nGrafo padrão criado com sucesso!" << endl;
        this->imprimeGrafo();
    }
};