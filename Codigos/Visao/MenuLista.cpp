#include <iostream>

#include "../EstruturaDeDados/Lista/GrafoLista.h"

using namespace std;

void menu() {
    int opcao = 0;
    int continuar = 1;
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


    /**
     * @attention Acredito que um do while seja uma forma melhor de trabalhar a repetição, veja menuMatriz
     * 
     */
    while (continuar == 1) {
        switch (opcao) {
            case 1:
                /* code */
                break;

            case 2:
                /* code */
                break;

            case 3:
                /* code */
                break;

            case 4:
                /* code */
                break;

            case 5:
                /* code */
                break;

            case 6:
                /* code */
                break;

            case 7:
                /* code */
                break;

            case 8:
                /* code */
                break;

            case 9:
                /* code */
                break;

            case 10:
                /* code */
                break;

            default:  // Vai funcionar para parar a função
                cout << "Opção inválida!" << endl;
                break;
        }

        cout << "Desejar continuar a fazer operacoes?" << endl;
        cout << "1 - SIM" << endl;
        cout << "2 - NAO" << endl;
        cout << "opcao : ";
        cin >> continuar;
    }
}
