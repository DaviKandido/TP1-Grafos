#include <iostream>
#include <stdexcept>
#include <vector>

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


};