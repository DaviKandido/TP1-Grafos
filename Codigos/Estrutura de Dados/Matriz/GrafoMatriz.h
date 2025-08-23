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
    ~GrafoMatriz() override = default;

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

    bool removerVertice(int v) override {
        if (!verticeValido(v)) {
            return false;
        }
        for (int i = 0; i < numVertices; ++i) {            
            // Aqui é preciso refazer toda a matriz (implementar no futuro)
        }
        return true;
    }

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

    vector<int> getSucessores(int v) const override {
        vector<int> sucessores;
        // Implementar no futuro
        return sucessores;
    }   
    
    vector<int> getPredecessores(int v) const override {
        vector<int> predecessores;
        // Implementar no futuro
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