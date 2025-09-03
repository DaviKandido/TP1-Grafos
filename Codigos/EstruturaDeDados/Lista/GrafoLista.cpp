#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "../IGrafo.cpp"

using namespace std;

class GrafoLista : public IGrafo<int> {

   public:

    struct Vertice{
      int peso;
      string rotulo;
      Vertice* next;
    };
    int numVertices;
    int numArestas;
    vector<Vertice> arr;
    bool direcionado;
    bool verticePonderado;
    bool arestaPonderada;
    bool verticeRotulado;
    bool arestaRotulada;

    GrafoLista(int totalVertices, bool direcionado, bool verticePonderado, bool arestaPonderada, bool verticeRotulado, bool arestaRotulada) {
      
      // Atribuir valores iniciais
      this->numVertices = totalVertices;
      this->numArestas = 0;

      // Atribuir variáveis de controle
      this->direcionado = direcionado;
      this->verticePonderado = verticePonderado;
      this->arestaPonderada = arestaPonderada;
      this->verticeRotulado = verticeRotulado;
      this->arestaRotulada = arestaRotulada;

    }

    bool verticeValido(int v) const {
      return (0 <= v && v < numVertices);
    }

    int getQuantidadeVertices() const override {
       return numVertices;
    }

    int getQuantidadeArestas() const override {
      return numArestas;
    }

    bool existeVertice(int v) const override {
      return verticeValido(v);
    }

    
};