#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../IGrafo.cpp"

using namespace std;

// Classe de Vertice genérica

class Vertice {
    int id;  // cada vertice precisa de um identificador único, caso não tenha rotulo
    int peso;
    string rotulo;

   public:
    // Variaveis de controle
    bool rotulado;
    bool ponderado;

    /**
     *   Construtor Vazio de Vertice
     *
     *   @return Vertice com id e peso 0, rotulo vazio e não rotulado e ponderado
     */
    Vertice() : Vertice(0, false, false, 0, "") {
    }

    /**
     *   Construtor de Vértice sem peso e rotulo
     *
     *   @param id Inteiro que define o id do vértice
     *   @param rotulado Boleano que determina se o vértice é rotulado ou não
     *   @param ponderado Boleano que determina se o vértice é ponderado ou não
     */
    Vertice(int id, bool rotulado, bool ponderado) : Vertice(id, rotulado, ponderado, 0, "") {
    }

    /**
     *   Construtor de Vértice com peso e rotulo
     *
     *   @param id Inteiro que define o id do vértice
     *   @param peso Inteiro que define o peso
     *   @param rotulo String que define o rotulo
     */
    Vertice(int id, int peso, string rotulo) : Vertice(id, true, true, peso, rotulo) {
    }

    /**
     *   Construtor de Vértice sem peso e rotulo
     *
     *   @param id Inteiro que define o id do vértice
     *   @param rotulado Boleano que determina se o vértice é rotulado ou não
     *   @param ponderado Boleano que determina se o vértice é ponderado ou não
     *   @param peso Inteiro que define o peso
     *   @param rotulo String que define o rotulo
     */
    Vertice(int id, bool rotulado, bool ponderado, int peso, string rotulo) {
        this->id = id;
        this->peso = peso;
        this->rotulo = rotulo;
        this->rotulado = rotulado;
        this->ponderado = ponderado;
    }

    /**
     *   Construtor de Vértice de cópia
     *
     *   @param v Vertice a ser copiado
     */
    Vertice(Vertice const &v) {
        this->peso = v.peso;
        this->rotulo = v.rotulo;
        this->ponderado = v.ponderado;
        this->rotulado = v.rotulado;
        setId(v.id);
    }

    void setPeso(int p) {
        this->peso = p;
        this->ponderado = true;
    }

    void setRotulo(string r) {
        this->rotulo = r;
        this->rotulado = true;
    }

    void setId(int id) {
        this->id = id;
    }

    int const getId() const {
        return this->id;
    }

    int const getPeso() const {
        return this->peso;
    }

    string getRotulo() const {
        return this->rotulo;
    }

    bool operator==(const Vertice &other) const {
        return this->id == other.id;
    }

    bool operator<(const Vertice &other) const {
        return this->id < other.id;
    }
};

/* A classe NoVertice representa o Vertice da lista principal,
na qual cada posição possui um vertice e a lista de vizinhos (suas arestas)

Representação gráfica:

                        Nó Vértice
+-----------------------------------------------------------+
|          |                                                |
|  Vertice | list<Vertice> arestas -> V1 -> V2 -> ... -> Vn |
|     |    |  |                                             |
+-----|----|--|---------------------------------------------+
      |       +-> Cada Vertice u em aresta tem os atributos da aresta (Vertice - u)
      +-> Vertice com todos os atributos

*/

class NoVertice {
   public:
    Vertice vertice;
    list<Vertice> arestas;

    // Variavéis de controle
    bool direcionado;
    bool verticePonderado;
    bool arestaPonderada;
    bool verticeRotulado;
    bool arestaRotulada;

    /**
     *   Construtor de NoVertice Vazio
     */
    NoVertice() : NoVertice(false, false, false, false, 0) {
    }

    /**
     *   Construtor de NoVértice sem peso e rotulo
     *
     *   @param verticePonderado Boleano que determina se o vértice é ponderado ou não
     *   @param arestaPonderada Boleano que determina se o aresta é ponderada ou não
     *   @param verticeRotulado Boleano que determina se o vértice é rotulado ou não
     *   @param arestaRotulada Boleano que determina se o aresta é rotulada ou não
     *   @param id Inteiro que define o id do vértice
     */
    NoVertice(bool verticePonderado, bool arestaPonderada, bool verticeRotulado,
              bool arestaRotulada, int id) {
        this->verticePonderado = verticePonderado;
        this->arestaPonderada = arestaPonderada;
        this->verticeRotulado = verticeRotulado;
        this->arestaRotulada = arestaRotulada;
        this->vertice = Vertice(id, verticePonderado, verticeRotulado);
        list<Vertice> arestas = {};
    }

    /**
     *   Construtor de NoVértice com peso e rotulo
     *
     *   @param verticePonderado Boleano que determina se o vértice é ponderado ou não
     *   @param arestaPonderada Boleano que determina se o aresta é ponderada ou não
     *   @param verticeRotulado Boleano que determina se o vértice é rotulado ou não
     *   @param arestaRotulada Boleano que determina se o aresta é rotulada ou não
     *   @param id Inteiro que define o id do vértice
     *   @param peso Inteiro que define o peso do vértice
     *   @param rotulo String que define o rotulo do vértice
     */
    NoVertice(bool verticePonderado, bool arestaPonderada, bool verticeRotulado,
              bool arestaRotulada, int id, int peso, string rotulo) {
        this->verticePonderado = verticePonderado;
        this->arestaPonderada = arestaPonderada;
        this->verticeRotulado = verticeRotulado;
        this->arestaRotulada = arestaRotulada;
        this->vertice = Vertice(id, verticePonderado, verticeRotulado, peso, rotulo);
        list<Vertice> arestas = {};
    }

    /**
     *   Construtor de NoVértice copiando um Vértice
     *
     *   @param arestaPonderada Boleano que determina se o aresta é ponderada ou não
     *   @param arestaRotulada Boleano que determina se a aresta é rotulada ou não
     *   @param v Vértice a ser copiado
     */
    NoVertice(bool arestaPonderada, bool arestaRotulada, Vertice v)
        : NoVertice(v.ponderado, arestaPonderada, v.rotulado, arestaRotulada, v.getId(),
                    v.getPeso(), v.getRotulo()) {
    }

    /**
     *   Adiciona uma Aresta conectando o vértice desse Nó com o v
     *
     *   @param v Vertice destino da aresta
     */
    void adicionarAresta(Vertice v) {
        this->arestas.push_back(v);
    }

    /**
     *   Adiciona uma Aresta conectando o vértice desse Nó com o v, adicionado peso na aresta
     *
     *   @param v Vertice destino da aresta
     *   @param peso Inteiro do peso a ser adicionado
     */
    void adicionarAresta(Vertice v, int peso) {
        v.setPeso(peso);
        this->arestas.push_back(v);
    }

    /**
     *   Adiciona uma Aresta conectando o vértice desse Nó com o v, adicionado rotulo na aresta
     *
     *   @param v Vertice destino da aresta
     *   @param rotulo String do rotulo a ser adicionado
     */
    void adicionarAresta(Vertice v, string rotulo) {
        v.setRotulo(rotulo);
        this->arestas.push_back(v);
    }

    /**
     *   Adiciona uma Aresta conectando o vértice desse Nó com o v, adicionado peso e rotulo na
     * aresta
     *
     *   @param v Vertice destino da aresta
     *   @param peso Inteiro do peso a ser adicionado
     *   @param rotulo String do rotulo a ser adicionado
     */
    void adicionarAresta(Vertice v, int peso, string rotulo) {
        v.setPeso(peso);
        v.setRotulo(rotulo);
        this->arestas.push_back(v);
    }

    /**
     *   Remove uma Aresta conectada o vértice desse Nó com v, caso exista
     *
     *   @param v Vertice destino da aresta a ser removida
     */
    void removerAresta(Vertice v) {
        // if(existeAresta(v)) <-- Vale a pena testar aqui?
        this->arestas.remove(v);
    }

    /**
     *   Testa se aresta existe
     *
     *   @param v Vertice destino da aresta
     *   @return Verdadeiro caso exista
     */
    bool existeAresta(Vertice v) {
        bool existe = false;
        for (std::list<Vertice>::iterator it = arestas.begin(); it != arestas.end(); ++it)
            if (*it == v) {
                existe = true;
            }
        return existe;
    }

    list<Vertice> getArestas() {
        return this->arestas;
    }

    int getId() const {
        return vertice.getId();
    }

    /**
     *   Transforma Nó vértice em uma string
     *
     *   @param v Vertice destino da aresta
     *   @return Verdadeiro caso exista
     */
    string toString() {
        string lista = to_string(vertice.getId());
        lista += " |";
        for (std::list<Vertice>::iterator it = arestas.begin(); it != arestas.end(); ++it)
            lista += ' ' + it->getId();
        lista += '\n';
        return lista;
    }
};

/*
O grafo lista é formado por um vector (array contínuo) de Nós vértices.
Esse grafo pode conter as seguintes características:
    + Simples ou Não simples
    + Direcionado ou não direcionado
    + Vértices e/ou arestas ponderados ou não ponderados
    + Vértices e/ou arestas rotulados ou não rotulados

Representação gráfica:

     +-> ListaPrincipal<NoVertice>
     |
+----|------------------------------------------------------+
|    |     |                                                |
|    0     | list<Vertice> arestas -> 1 -> 2 -> ...         |
|          |                                                |
|    1     | list<Vertice> arestas -> 4 -> 0 -> ...         |
|          |                                                |
|    2     | list<Vertice> arestas -> 3 -> 2 -> ...         |
|          |                                                |
|   ...    |                    ...                         |
+----------|------------------------------------------------+

*/

class GrafoLista : public IGrafo<Vertice> {
   private:
    vector<NoVertice> listaPrincipal;

   public:
    int numVertices;
    int numArestas;
    int ultimoId;

    // Variavéis de controle
    bool simples;
    bool direcionado;
    bool verticePonderado;
    bool arestaPonderada;
    bool verticeRotulado;
    bool arestaRotulada;

    /**
     *   Construtor de GrafoLista com n vértices (com peso e rotulos zerados)
     *
     *   @param simples Boleano que determina se o grafo é simples ou não
     *   @param direcionado Boleano que determina se o grafo é direcionado ou não
     *   @param vPonderado Boleano que determina se o vértice é ponderado ou não
     *   @param aPonderada Boleano que determina se a aresta é pondearda ou não
     *   @param vRotulado Boleano que determina se o vértice é rotulado ou não
     *   @param aRotulada Boleano que determina se a aresta é rotulada ou não
     *   @param quantidadeVerticesInicial inteiro
     */
    GrafoLista(bool simples, bool direcionado, bool vPonderado, bool aPonderada, bool vRotulado,
               bool aRotulada, int quantidadeVerticesInicial) {
        this->ultimoId = -1;
        this->numArestas = 0;
        this->numVertices = 0;
        this->simples = simples;
        this->direcionado = direcionado;
        this->verticePonderado = vPonderado;
        this->arestaPonderada = aPonderada;
        this->verticeRotulado = vRotulado;
        this->arestaRotulada = aRotulada;
        NoVertice v1 = NoVertice(this->verticePonderado, this->arestaPonderada,
                                 this->verticeRotulado, this->arestaRotulada, 0);

        for (int i = 0; i < quantidadeVerticesInicial; i++) {
            adicionarVertice(v1.vertice);
        }
    }

    /**
     *   Construtor de Grafo inicializado com 1 único vértice
     *
     *   @param simples Boleano que determina se o grafo é simples ou não
     *   @param direcionado Boleano que determina se o grafo é direcionado ou não
     *   @param vPonderado Boleano que determina se o vértice é ponderado ou não
     *   @param aPonderada Boleano que determina se a aresta é pondearda ou não
     *   @param vRotulado Boleano que determina se o vértice é rotulado ou não
     *   @param aRotulada Boleano que determina se a aresta é rotulada ou não
     *   @param quantidadeVerticesInicial inteiro
     */
    GrafoLista(bool simples, bool direcionado, bool vPonderado, bool aPonderada, bool vRotulado,
               bool aRotulada)
        : GrafoLista(simples, direcionado, vPonderado, aPonderada, vRotulado, aRotulada, 1) {
    }

    // Metodos de manipulação

    /**
     *   Adiciona mais um vértice no Grafo
     *
     *   @param v Vertice a ser adicionado
     *   @return se ação foi concluida ou não
     */
    bool adicionarVertice(Vertice v) override {
        NoVertice vertice =
            NoVertice(this->verticePonderado, this->arestaPonderada, this->verticeRotulado,
                      this->arestaRotulada, ++ultimoId, v.getPeso(), v.getRotulo());
        listaPrincipal.push_back(vertice);
        numVertices++;
        return true;
    }

    /**
     *   Remove um vértice no Grafo, caso o vértice esteja presente, assim como as arestas
     * conectadas
     *
     *   @param v Vertice a ser removido
     *   @return se ação foi concluida ou não
     */
    bool removerVertice(Vertice v) override {
        NoVertice vertice = NoVertice(this->arestaPonderada, this->arestaRotulada, v);
        int pos = procurarVertice(v);
        bool status = true;
        if (pos != -1) {
            // Remover NoVertice da Lista Principal
            listaPrincipal.erase(listaPrincipal.begin() + pos);

            // Remover todas as arestas que conectavam com v
            vector<Vertice> arestasRemover = procurarAresta(v);
            for (int i = 0; i < arestasRemover.size(); i++) {
                removerAresta(arestasRemover.at(i), v);
            }
            numVertices -= 1;
        } else {
            status = false;
            cout << "Vertice " << v.getId() << "não está no grafo";
        }
        return status;
    }

    /**
     *   Adiciona uma aresta no grafo
     *
     *   @param origem Vertice de partida da aresta
     *   @param destino Vertice de destino da aresta
     *   @return se ação foi concluida ou não
     */
    bool adicionarAresta(Vertice origem, Vertice destino) override {
        bool status = false;
        if (validarVertice(destino) && validarVertice(origem)) {
            NoVertice &procura = listaPrincipal.at(origem.getId());
            procura.adicionarAresta(destino);

            if (!direcionado) {
                NoVertice &procuraDestino = listaPrincipal.at(destino.getId());
                procuraDestino.adicionarAresta(origem);
            }

            status = true;
            numArestas++;
        }
        return status;
    }

    /**
     *   Adiciona uma aresta com peso no grafo
     *
     *   @param origem Vertice de partida da aresta
     *   @param destino Vertice de destino da aresta
     *   @param peso Inteiro do peso a ser adicionado
     *   @return se ação foi concluida ou não
     */
    bool adicionarAresta(Vertice origem, Vertice destino, int peso) override {
        return adicionarAresta(origem, destino, peso, "");
    }

    /**
     *   Adiciona uma aresta com rotulo no grafo
     *
     *   @param origem Vertice de partida da aresta
     *   @param destino Vertice de destino da aresta
     *   @param rotulo String do rotulo a ser adicionado
     *   @return se ação foi concluida ou não
     */
    bool adicionarAresta(Vertice origem, Vertice destino, string rotulo) {
        return adicionarAresta(origem, destino, 0, rotulo);
    }

    /**
     *   Adiciona uma aresta com peso e rotulo no grafo
     *
     *   @param origem Vertice de partida da aresta
     *   @param destino Vertice de destino da aresta
     *   @param peso Inteiro do peso a ser adicionado
     *   @param rotulo String do rotulo a ser adicionado
     *   @return se ação foi concluida ou não
     */
    bool adicionarAresta(Vertice origem, Vertice destino, int peso, string rotulo) {
        bool status = false;
        if (validarVertice(destino) && validarVertice(origem)) {
            NoVertice procura = listaPrincipal.at(origem.getId());
            procura.adicionarAresta(destino, peso, rotulo);

            if (!direcionado) {
                procura = listaPrincipal.at(destino.getId());
                procura.adicionarAresta(origem, peso, rotulo);
            }

            status = true;
            numArestas++;
        }
        return status;
    }

    /**
     *   Remove uma aresta do Grafo, caso exista
     *
     *   @param origem Vertice de partida da aresta
     *   @param destino Vertice de destino da aresta
     *   @return se ação foi concluida ou não
     */
    bool removerAresta(Vertice origem, Vertice destino) override {
        bool status = false;
        if (existeAresta(origem, destino)) {
            NoVertice procura = listaPrincipal.at(origem.getId());
            procura.removerAresta(destino);

            if (!direcionado) {
                procura = listaPrincipal.at(destino.getId());
                procura.removerAresta(origem);
            }

            status = true;
            numArestas--;
        }
        return status;
    }

    /**
     *   Coleta os vértices vizinhos de um dado vértice
     *
     *   @param v Vertice a ter seus vizinhos coletados
     *   @return Vector<Vertice> dos vizinhos
     */
    vector<Vertice> getVizinhos(Vertice v) const override {
        if (!direcionado) {
            vector<Vertice> v1 = fechoTransitivoInverso(v);
            vector<Vertice> v2 = fechoTransitivoDireto(v);
            vector<Vertice> resultado;

            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());

            set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(resultado));

            return resultado;
        } else {
            return fechoTransitivoDireto(v);
        }
    }

    /**
     *   Coleta os vértices descendentes de um dado vértice
     *
     *   @param v Vertice a ter seus descendentes coletados
     *   @return Vector<Vertice> dos descendentes
     */
    vector<Vertice> fechoTransitivoDireto(Vertice v) const override {
        NoVertice procura = listaPrincipal.at(v.getId());
        list<Vertice> descendentes_list = procura.getArestas();

        // Conversao de list para vector
        vector<Vertice> descendentes{std::begin(descendentes_list), std::end(descendentes_list)};
        return descendentes;
    }

    /**
     *   Coleta os vértices ancestrais de um dado vértice
     *
     *   @param v Vertice a ter seus ancestrais coletados
     *   @return Vector<Vertice> dos ancestrais
     */
    vector<Vertice> fechoTransitivoInverso(Vertice v) const override {
        vector<Vertice> ancestrais;
        NoVertice procura;
        for (int i = 0; i < listaPrincipal.size(); i++) {
            procura = listaPrincipal.at(i);
            list<Vertice> arestas_list = procura.getArestas();
            for (std::list<Vertice>::iterator it = arestas_list.begin(); it != arestas_list.end();
                 ++it) {
                if (*it == v) {
                    ancestrais.push_back(*it);
                }
            }
        }

        return ancestrais;
    }

    // Metodos de validacao

    /**
     *   Valida um novo vértice. <----- PRECISA DE ALTERAÇÕES
     *
     *   @param v Vertice a ser validado
     *   @return Verdadeiro caso vértice seja válido
     */
    bool validarVertice(Vertice v) const {
        return (0 <= v.getId() && v.getId() < numVertices);
    }

    /**
     *   Determina se certo Vértice existe no grafo
     *
     *   @param v Vertice a ser testado
     *   @return Verdadeiro caso exista
     */
    bool existeVertice(Vertice v) const override {
        Vertice verticeProcurar = Vertice();
        int i = 0;
        bool achou = false;
        while (i != listaPrincipal.size() && !achou) {
            verticeProcurar = listaPrincipal.at(i).vertice;
            if (verticeProcurar == v) {
                achou = true;
            }
            i++;
        }
        return achou;
    }

    /**
     *   Determina se certa Aresta existe no grafo
     *
     *   @param origem Vertice de partida da aresta
     *   @param destino Vertice de destino da aresta
     *   @return Verdadeiro se aresta existir
     */
    bool existeAresta(Vertice origem, Vertice destino) const override {
        bool achou = false;
        if (validarVertice(destino) && validarVertice(origem)) {
            NoVertice procura = listaPrincipal.at(origem.getId());
            achou = procura.existeAresta(destino);
        }
        return achou;
    }

    /**
     *   Procura certo Vértice no grafo
     *
     *   @param v Vertice a ser procurado
     *   @return Inteiro de sua posição no grafo, caso não exista retorna -1
     */
    int procurarVertice(Vertice v) {
        Vertice verticeProcurar = Vertice();
        int i = 0;
        int achou = -1;
        while (i != listaPrincipal.size() && !achou) {
            verticeProcurar = listaPrincipal.at(i).vertice;
            if (verticeProcurar == v) {
                achou = i;
            }
            i++;
        }
        return achou;
    }

    /**
     *   Procura todas as arestas cujo destino é o Vertice destino
     *
     *   @param destino Vertice destino das arestas desejadas
     *   @return Vector<Vertice> de Vertices que possuam alguma aresta com Vertice Destino
     */
    vector<Vertice> procurarAresta(Vertice v) {
        vector<Vertice> listaVerticesComAresta;
        NoVertice noVerticeProcurar = NoVertice();
        int i = 0;
        int achou = -1;
        if (existeVertice(v)) {
            while (i != listaPrincipal.size()) {
                noVerticeProcurar = listaPrincipal.at(i);
                for (std::list<Vertice>::iterator it = noVerticeProcurar.arestas.begin();
                     it != noVerticeProcurar.arestas.end(); ++it) {
                    if (*it == v) {  // Caso há aresta com v
                        listaVerticesComAresta.push_back(noVerticeProcurar.vertice);
                    }
                }
                i++;
            }
        }

        return listaVerticesComAresta;
    }

    // Metodos de capacidade

    int getQuantidadeVertices() const override {
        return numVertices;
    }

    int getQuantidadeArestas() const override {
        return numArestas;
    }

    // Outros metodos

    /**
     *   Imprime o grafo inteiro
     */
    void imprimir() const override {
        string str = "";
        int tam_max = to_string(abs(ultimoId)).size();
        std::ostringstream oss;

        cout << "------- Lista de Adjacências --------" << endl;
        for (int i = 0; i < listaPrincipal.size(); i++) {
            const NoVertice &v = listaPrincipal.at(i);
            if (verticePonderado && verticeRotulado) {
                oss << i << " [" << v.vertice.getId() << ", " << v.vertice.getPeso() << ", "
                    << v.vertice.getRotulo() << "]";
            } else if (verticePonderado) {
                oss << i << " [" << v.vertice.getId() << ", " << v.vertice.getPeso() << "]";
            } else if (verticeRotulado) {
                oss << i << " [" << v.vertice.getId() << ", " << v.vertice.getRotulo() << "]";
            } else {
                oss << i << " [" << v.vertice.getId() << "]";
            }

            str = oss.str();
            // alinhar valores
            for (int i = 0; i < tam_max - to_string(abs(v.getId())).size(); i++) str += " ";
            str += " ->";
            cout << str;

            str = "";
            oss.str("");
            oss.clear();
            for (const auto &aresta : v.arestas) {
                if (arestaPonderada && arestaRotulada) {
                    oss << " [" << aresta.getId() << ", " << aresta.getPeso() << ", "
                        << aresta.getRotulo() << "]";
                } else if (arestaPonderada) {
                    oss << " [" << aresta.getId() << ", " << aresta.getPeso() << "]";
                } else if (arestaRotulada) {
                    oss << " [" << aresta.getId() << ", " << aresta.getRotulo() << "]";
                } else {
                    oss << " [" << aresta.getId() << "]";
                }

                str += oss.str();
                oss.str("");
                oss.clear();
            }
            str += '\n';
            cout << str;
        }
        cout << "-------------------------------------" << endl << endl;
    }
};

int main() {
    GrafoLista g = GrafoLista(false, true, false, false, false, false);
    g.imprimir();
    Vertice v = Vertice(1, false, false);
    for (int i = 0; i < 11; i++) {
        v.setId(i + 1);
        g.adicionarVertice(v);
    }

    for (int i = 0; i < g.numVertices; i++) {
        v.setId(i);
        for (int x = 0; x < g.numVertices; x++) {
            Vertice a = Vertice(v);
            a.setId(x);
            g.adicionarAresta(v, a);
        }
    }
    g.imprimir();

    cout << endl << "Grafo Ponderado" << endl;
    GrafoLista g1 = GrafoLista(false, true, false, true, false, false);
    g1.imprimir();
    Vertice v1 = Vertice(1, false, false);
    for (int i = 0; i < 11; i++) {
        v1.setId(i + 1);
        g1.adicionarVertice(v1);
    }

    for (int i = 0; i < g1.numVertices; i++) {
        v.setId(i);
        for (int x = 0; x < g1.numVertices; x++) {
            Vertice a = Vertice(v1);
            a.setId(x);
            g1.adicionarAresta(v, a, rand());
        }
    }

    g.imprimir();
    return 0;
}