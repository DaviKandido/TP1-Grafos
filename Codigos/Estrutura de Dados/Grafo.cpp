#include <string>
using namespace std;

class Grafo {
    public: 
        virtual bool setVertice(int v) = 0;
        virtual bool setAresta(int v, int u, int peso) = 0;
        virtual bool setAresta(int v, int u ) = 0;
        virtual bool removeVertice(int v) = 0;
        virtual bool removeAresta(int v, int u) = 0;
        
        virtual bool existeAresta(int v, int u) = 0;
        virtual bool rotularVertice(int v, string rotulo) = 0;
        virtual int getQuantidadeVertices( ) = 0;
        virtual int getQuantidadeArestas( ) = 0;
        virtual void print( ) = 0; // Printa o grafo

    /*
        // Funcionalidades extras para Lista de Adjacencia
        virtual Vertice[] getVizinhos(Vertice v) = 0;
        virtual Vertice[] getAlcancados(Vertice v) = 0;
        virtual Vertice[] getAlcanca(Vertice v) = 0;
        virtual Vertice[] BFS(Vertice v) = 0;
        virtual Vertice[] DFS(Vertice v) = 0;

    */

    private: 
        int quantidadeVertices;
        int quantidadeArestas;
        bool direcionado;
};