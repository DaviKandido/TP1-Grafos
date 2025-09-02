#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>

#include "../IGrafo.cpp"

using namespace std;

enum cores {
    BRANCO,
    VERMELHO,
    PRETO
};
int tempo = 0;


class GrafoMatriz : public IGrafo<int> {
    private:
        // Estruturas de dados
        vector<vector<int>> matrizAdjacencias;
        unordered_map<int, string> verticesRotulos;
        vector<vector<string>> arestasRotulos;

        // Atributos do grafo
        int numVertices;
        int numArestas;
        

        // Validar se um vértice está dentro dos limites
        bool verticeValido(int v) const {
            return (0 <= v && v < numVertices);
        }

   public:
        // Variáveis de controle
        bool direcionado;
        bool verticePonderado;
        bool arestaPonderada;
        bool verticeRotulado;
        bool arestaRotulada;
        
        // Construtor: cria um grafo com um número fixo de vértices
        GrafoMatriz(int totalVertices, bool direcionado, bool verticePonderado, bool arestaPonderada, bool verticeRotulado, bool arestaRotulada) {
            // Testar se o número de vértices é válido
            if (totalVertices <= 0) {
                throw invalid_argument("O número de vértices deve ser positivo.");
            }

            // Atribuir valores iniciais
            this->numVertices = totalVertices;
            this->numArestas = 0;

            // Atribuir variáveis de controle
            this->direcionado = direcionado;
            this->verticePonderado = verticePonderado;
            this->arestaPonderada = arestaPonderada;
            this->verticeRotulado = verticeRotulado;
            this->arestaRotulada = arestaRotulada;

            // Inicializa a matriz com tamanho N x N preenchida com 0 (ou seja, sem arestas)
            matrizAdjacencias.resize(numVertices, vector<int>(numVertices, 0));

            // Se os vértices do grafo forem rotulados, criar o Hash Map com strings vazias
            if (this->verticeRotulado) {
                for (int i = 0; i < numVertices; i++) {
                    verticesRotulos[i] = "";
                }
            }

            // Se as arestas do grafo forem rotuladas, criar a matriz dos rótulos preenchida com strings vazias
            if (this->arestaRotulada) {
                arestasRotulos.resize(numVertices, vector<string>(numVertices, ""));
            }
        }

        // Destrutor: padrão
        ~GrafoMatriz() override {
            matrizAdjacencias.clear();
            verticesRotulos.clear();
            arestasRotulos.clear();
            this->numVertices = 0;
            this->numArestas = 0;
            this->direcionado = false;
            this->verticePonderado = false;
            this->arestaPonderada = false;
            this->verticeRotulado = false;
            this->arestaRotulada = false;
        };

        // --- Implementar as funções da interface ---

        int getQuantidadeVertices() const override {
            return numVertices;
        }

        int getQuantidadeArestas() const override {
            return numArestas;
        }

        bool adicionarVertice(int v) override {
            // Aqui é preciso refazer toda a matriz (implementar no futuro)
            return v == numVertices + 1;
        }

        bool adicionarVertice(int v, int peso) {
            // Aqui é preciso refazer toda a matriz (implementar no futuro)
            return adicionarVertice(v, peso, ""); // Rótulo padrão é string vazia        
        }

        bool adicionarVertice(int v, string label) {
            // Aqui é preciso refazer toda a matriz (implementar no futuro)
            return adicionarVertice(v, 1, label); // Peso padrão é 1
        }

        bool adicionarVertice(int v, int peso, string label) {
            // Aqui é preciso refazer toda a matriz (implementar no futuro)
            // Obs: alterar o peso e o rótulo apenas se o grafo for ponderado e rotulado

            // Alterar o rótulo do vértice
            if (this->verticeRotulado) {
                verticesRotulos[v] = label;
            }
            return verticeValido(v);        
        }

        bool adicionarAresta(int origem, int destino) override {
            return adicionarAresta(origem, destino, 1);  // Peso padrão é 1
        }

        bool adicionarAresta(int origem, int destino, int peso) {
            return adicionarAresta(origem, destino, peso, ""); // Rótulo padrão é string vazia
        }

        bool adicionarAresta(int origem, int destino, string label) {
            return adicionarAresta(origem, destino, 1, label); // Peso padrão é 1
        }

        bool adicionarAresta(int origem, int destino, int peso, string label) {
            // Testar se os vértices existem, se o peso não é nulo e se a aresta JÁ NÃO EXISTE
            if (!verticeValido(origem) || !verticeValido(destino) || peso == 0 || matrizAdjacencias[origem][destino] != 0) {
                return false;
            }

            // Adicionar a aresta com o seu peso (caso o grafo não seja ponderado, o seu peso será 1 por padrão)
            matrizAdjacencias[origem][destino] = peso;

            // Se o grafo for não-direcionado, inserir a aresta no sentido inverso também
            if (!this->direcionado) {
                matrizAdjacencias[destino][origem] = peso;
            }

            // Se o grafo for ponderado, alterar o nome da aresta na matriz já construída anteriormente
            if (this->arestaRotulada) {
                arestasRotulos[origem][destino] = label;
            }

            // Incrementar o número de arestas
            numArestas++;

            // Retornar status de sucesso
            return true;
        }

        //bool removerVertice(int v) override {
        //    return verticeValido(v);
        //}
        
        /**
         * @bug Erro na variável 'iNovo' (Declaração Ausente)
         */
        
        bool removerVertice(int v) override {
            if (!verticeValido(v)) {
                return false;
            }
            int novoNum = numVertices - 1;
            vector<vector<int>> novaMatriz(
            novoNum, vector<int>(novoNum, 0));

            for (int i = 0; i < numVertices; ++i) {
                if (i == v) continue; // pula a linha do vértice removido
                int jNovo = 0;
                for (int j = 0; j < numVertices; j++) {
                    if (j == v) continue; // pula a coluna do vértice removido
                    novaMatriz[novoNum][jNovo] = matrizAdjacencias[i][j];
                    jNovo++;
                }
            novoNum++;
            }
            matrizAdjacencias = novaMatriz;
            numVertices = novoNum;
            return true;
        }
        

        bool removerAresta(int origem, int destino) override {
            // Testar se os vértices são válidos e se há aresta para remover
            if (!verticeValido(origem) || !verticeValido(destino) ||
                matrizAdjacencias[origem][destino] == 0) {
                return false;
            }

            // Remover a aresta da matriz
            matrizAdjacencias[origem][destino] = 0;

            if (this->direcionado == false) {
                matrizAdjacencias[destino][origem] = 0;
            }

            if (this->arestaRotulada) {
                arestasRotulos[origem][destino] = "";
                if (this->direcionado) {
                    arestasRotulos[destino][origem] = "";
                }
            }

            numArestas--;
            return true;
        }

        bool existeVertice(int v) const override {
            return verticeValido(v);
        }

        bool existeAresta(int origem, int destino) const override {
            if (!verticeValido(origem) || !verticeValido(destino)) {
                return false;
            }
            return matrizAdjacencias[origem][destino] != 0;
        }

        vector<int> getVizinhos(int v) const override {
            // Definir vector com todos os vizinhos do vértice
            vector<int> vizinhos;

            // Se o vértice não existe, retorna um vector vazio
            if (!verticeValido(v)) {
                return vizinhos;
            }

            // Percorrer a linha da matriz correspondente ao vértice 'v'
            for (int j = 0; j < numVertices; ++j) {
                if (matrizAdjacencias[v][j] != 0) {
                    vizinhos.push_back(j);
                }
            }

            return vizinhos;
        }

        // Fecho transitivo direto (Todos os alcançados pelo vértice 'v', incluindo ele) - DFS (Busca
        // em Profundidade)
        vector<int> getDescendentes(int v) const override {
            vector<int> sucessores;
            vector<bool> visitados(numVertices, false);
            // Implementar no futuro
            return getDescendentes(v, visitados);
        }

        vector<int> getDescendentes(int v, vector<bool> &visitados) const {
            vector<int> sucessores;
            // Implementar no futuro

            // Marca o vértice como visitado
            visitados[v] = true;

            if (!verticeValido(v)) {
                throw invalid_argument("Vértice inválido.");
            }

            sucessores.push_back(v);

            for (int i = 0; i < numVertices; i++) {
                if (matrizAdjacencias[v][i] != 0 && !visitados[i]) {
                    // Chama recursivamente para explorar os sucessores do sucessor - DFS
                    vector<int> subSucessores = getDescendentes(i, visitados);

                    /* Junta os resultado
                        for (int x : subSucessores)
                        sucessores.push_back(x);
                    */
                    sucessores.insert(sucessores.end(), subSucessores.begin(), subSucessores.end());
                }
            }
            return sucessores;
        }

        // Fecho transitivo negativo (Todos que poderiam alcançar o vértice 'v', exceto ele) - DFS
        // (Busca em Profundidade)
        vector<int> getAncestrais(int v) const override {
            vector<int> predecessores;
            vector<bool> visitados(numVertices, false);
            // Implementar no futuro
            return getAncestrais(v, visitados);
        }
        
        vector<int> getAncestrais(int v, vector<bool> &visitados) const {
            vector<int> predecessores;
            // Implementar no futuro

            // Marca o vértice como visitado
            visitados[v] = true;

            if (!verticeValido(v)) {
                throw invalid_argument("Vértice inválido.");
            }

            for (int i = 0; i < numVertices; i++) {
                if (matrizAdjacencias[i][v] != 0 && !visitados[i]) {
                    predecessores.push_back(v);

                    // Chama recursivamente para explorar os sucessores do sucessor - DFS
                    vector<int> subPredecessores = getAncestrais(i, visitados);

                    /* Junta os resultado
                        for (int x : subSucessores)
                        sucessores.push_back(x);
                    */
                    predecessores.insert(predecessores.end(), subPredecessores.begin(),
                                        subPredecessores.end());
                }
            }
            return predecessores;
        }

        /**
         * Busca em profundidade (DFS) do grafo.
         *
         * O vetor de cores é utilizado para marcar os vértices como branco (não visitado),
         * vermelho (visitado) ou preto (visitado e finalizado).O vetor de tempos é utilizado para armazenar 
         * os tempos de início e fim de cada vértice.
         *
         * @return Vetor com os tempos de início e fim de cada vértice.
         */

        vector<vector<int>> buscaEmProfundidade() const {

            // Definir vector com todos os vizinhos do grafo como branco
            vector<cores> coresVertices(numVertices, cores::BRANCO);
            vector<vector<int>> temposVertices(numVertices, vector<int>(2, 0));

            for(int i = 0; i < numVertices; i++){
                if(coresVertices[i] == cores::BRANCO){
                    buscaEmProfundidade(i, coresVertices, temposVertices);
                }
            }

            return temposVertices;
        }

        vector<vector<int>> buscaEmProfundidade(int i, vector<cores> &coresVertices, vector<vector<int>> &temposVertices) const {
            coresVertices[i] = cores::VERMELHO;
            temposVertices[i][0] = ++tempo;
            for(int j = 0; j < numVertices; j++){
                if(matrizAdjacencias[i][j] != 0 && coresVertices[j] == cores::BRANCO){
                    buscaEmProfundidade(j, coresVertices, temposVertices);
                }
            }

            coresVertices[i] = cores::PRETO;
            temposVertices[i][1] = ++tempo;
            return temposVertices;
        }

        

        void imprimir() const override {
            cout << "------- Matriz de Adjacências -------" << endl;
            for (int i = 0; i < numVertices; ++i) {
                cout << "Vértice " << i << ":\t";
                for (int j = 0; j < numVertices; ++j) {
                    cout << matrizAdjacencias[i][j] << "\t";
                }
                cout << endl;
            }
            cout << "-------------------------------------" << endl << endl;
        }
};