#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "../IGrafo.h"

using namespace std;

class GrafoLista : public IGrafo<int> {

   public:

      struct Vertice
      {
         int peso;
         string rotulo;
         Vertice* next;
      };
      int numVertices;
      int numArestas;
      bool direcionado;
      vector<Vertice> arr;

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