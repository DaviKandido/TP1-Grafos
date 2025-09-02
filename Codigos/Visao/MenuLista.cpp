#include <iostream>
#include <string>
#include "MyIO.cpp"

#include "../EstruturaDeDados/Lista/GrafoLista.cpp"

using namespace std;
#define maxVertice 2147483647


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
     * Cria um grafo e o armazena em 'grafo'. O grafo pode ser direcionado ou não-direcionado, ponderado ou não ponderado e rotulado ou não rotulado.
     */
    void intanciaGrafo() {
        cout << "\n> Menu > Lista > Instanciar Grafo" << endl << endl;

        // Atributo do grafo
        int numVertices;

        // Variáveis de controle
        bool direcionado;
        bool verticePonderado;
        bool arestaPonderada;
        bool verticeRotulado;
        bool arestaRotulada;

        // Ler as informações do usuário
        numVertices = lerInteiro("Número de vértices: ", 1, maxVertice);

        direcionado      = lerBoolean("O grafo é direcionado?      (S/N): ");
        verticePonderado = lerBoolean("Os vértices são ponderados? (S/N): ");
        arestaPonderada  = lerBoolean("As arestas são ponderadas?  (S/N): ");
        verticeRotulado  = lerBoolean("Os vértices são rotulados?  (S/N): ");
        arestaRotulada   = lerBoolean("As arestas são rotuladas?   (S/N): ");
        // Aqui ainda ta faltando implementar o GrafoLista
}

void adicionaVertice(){
    cout << "\n> Menu > Lista > Adicionar Vértice" << endl << endl;

    //Variaveis nas suas formas padrão caso seja não rotulado e não ponderado
    string rotulo = "";
    int peso = 1;
    //teste de ponderado e de rotulo
    if(grafo->verticeRotulado == 1){
        rotulo = lerRotulo("Rótulo do vértice: ");
    }

    if(grafo->verticePonderado == 1){
        rotulo = lerInteiro("Rótulo do vértice: ");
    }

    //Agora tem que chamar uma função de GrafoLista que ainda não foi feito
}

void adicionaAresta(){
    cout << "\n> Menu > Lista > Adicionar Aresta" << endl << endl;

    //Variaveis nas suas formas padrão caso seja não rotulado e não ponderado
    string rotulo = "";
    int peso = 1;
    //teste de ponderado e de rotulo
    if(grafo->arestaRotulado == 1){
        rotulo = lerRotulo("Rótulo da aresta: ");
    }

    if(grafo->arestaPonderado == 1){
        rotulo = lerInteiro("Rótulo da aresta: ");
    }

    //Agora tem que chamar uma função de GrafoLista que ainda não foi feito
}

void removeVertice(){

}

void removeAresta(){

}

void consultaVizinhosVertice(){

}

void consultarSucessoresVertice(){

}

void consultarPredecessoresVertice(){

}

void removeGrafo(){

}

void imprimeGrafo(){

}
