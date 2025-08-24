#include "../IGrafo.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class GrafoMatriz : public IGrafo<int> {
private:
    // Atributos privados
    vector<vector<int>> matrizAdjacencias;
    int numVertices;
    int numArestas;
    bool direcionado;


    // Validar se um vértice está dentro dos limites
    bool verticeValido(int v) const {
        return (0 <= v && v < numVertices);
    }

public:
    // Construtor: cria um grafo com um número fixo de vértices
    GrafoMatriz(int totalVertices, bool direcionado) {
        // Testar se o número de vértices é válido
        if (totalVertices <= 0) {
            throw invalid_argument("O número de vértices deve ser positivo.");
        }

        // Atribuir valores iniciais
        this->numVertices = totalVertices;
        this->numArestas = 0;
        this->direcionado = direcionado;

        // Inicializa a matriz com tamanho N x N, preenchida com 0 (ou seja, sem arestas)
        matrizAdjacencias.resize(numVertices, vector<int>(numVertices, 0));
    }

    // Destrutor: padrão (implementar no futuro)
    ~GrafoMatriz() override {
        matrizAdjacencias.clear();
        this->numVertices = 0;
        this->numArestas = 0;
        this->direcionado = false;
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
        return verticeValido(v);
    }

    bool adicionarAresta(int origem, int destino) override {
        return adicionarAresta(origem, destino, 1); // Peso padrão é '1'
    }

    bool adicionarAresta(int origem, int destino, int peso) override {
        // Testar se os vértices existem, se o peso não é nulo e se a aresta JÁ NÃO EXISTE
        if (!verticeValido(origem) || !verticeValido(destino) || peso == 0 || matrizAdjacencias[origem][destino] != 0) {
            return false;
        }

        matrizAdjacencias[origem][destino] = peso;
        if (!this->direcionado) {
            matrizAdjacencias[destino][origem] = peso;
        }

        numArestas++;
        return true;
    }


/**
 * @bug Erro na variável 'iNovo' (Declaração Ausente)
 */
/*
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
                novaMatriz[iNovo][jNovo] = matrizAdjacencias[i][j];
                jNovo++;
            }
           iNovo++;
        }
        matrizAdjacencias = novaMatriz;
        numVertices = novoNum;
        return true;
    }
*/

    bool removerAresta(int origem, int destino) override {
        // Testar se os vértices são válidos e se há aresta para remover
        if (!verticeValido(origem) || !verticeValido(destino) || matrizAdjacencias[origem][destino] == 0) {
            return false;
        }

        // Remover a aresta da matriz
        matrizAdjacencias[origem][destino] = 0;
        if (this->direcionado == false) {
            matrizAdjacencias[destino][origem] = 0;
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

    // Fecho transitivo positivo (Todos os alcançados pelo vértice 'v', incluindo ele) - DFS (Busca em Profundidade)
    vector<int> getSucessores(int v) const override {
        vector<int> sucessores;
        vector<bool> visitados(numVertices, false);
        // Implementar no futuro
        return getSucessores(v, visitados);
    }

    vector<int> getSucessores(int v, vector<bool> &visitados) const {
        vector<int> sucessores;
        // Implementar no futuro

        // Marca o vértice como visitado
        visitados[v] = true;

        if(!verticeValido(v)) {
            throw invalid_argument("Vértice inválido.");
        }

        sucessores.push_back(v);

        for(int i = 0; i < numVertices; i++) {
            if(matrizAdjacencias[v][i] != 0 && !visitados[i]) {

                // Chama recursivamente para explorar os sucessores do sucessor - DFS
                vector<int> subSucessores = getSucessores(i, visitados);

                /* Junta os resultado
                    for (int x : subSucessores) 
                       sucessores.push_back(x);
                */
                sucessores.insert(sucessores.end(), subSucessores.begin(), subSucessores.end());

            }
        }
        return sucessores;
    }   
    
    // Fecho transitivo negativo (Todos que poderiam alcançar o vértice 'v', exceto ele) - DFS (Busca em Profundidade)
    vector<int> getPredecessores(int v) const override {
        vector<int> predecessores;
        vector<bool> visitados(numVertices, false);
        // Implementar no futuro
        return getPredecessores(v, visitados);
    }
    vector<int> getPredecessores(int v, vector<bool> &visitados) const {
         vector<int> predecessores;
        // Implementar no futuro

        // Marca o vértice como visitado
        visitados[v] = true;

        if(!verticeValido(v)) {
            throw invalid_argument("Vértice inválido.");
        }

        
        for(int i = 0; i < numVertices; i++) {
            if(matrizAdjacencias[i][v] != 0 && !visitados[i]) {
                
                predecessores.push_back(v);

                // Chama recursivamente para explorar os sucessores do sucessor - DFS
                vector<int> subPredecessores = getPredecessores(i, visitados);

                /* Junta os resultado
                    for (int x : subSucessores) 
                       sucessores.push_back(x);
                */
                predecessores.insert(predecessores.end(), subPredecessores.begin(), subPredecessores.end());

            }
        }
        return predecessores;
    }

    void imprimir() const override {
        cout << "--- Grafo (Matriz de Adjacências) ---" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vértice " << i << ":\t";
            for (int j = 0; j < numVertices; ++j) {
                cout << matrizAdjacencias[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "------------------------------------" << endl;
    }
};