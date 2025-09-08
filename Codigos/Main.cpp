#include <iostream>
#include <string>

#include "./Visao/MenuLista.cpp"
#include "./Visao/MenuMatriz.cpp"
#include "./libs/io.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    try {
        int opcao = 0;

        cout << "---------------------------------------------" << endl;
        cout << "--- Bem vindo ao TP1 de Teoria dos Grafos ---" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "--------------- Integrantes: ----------------" << endl
             << "---------- Augusto Stambassi Duarte ---------" << endl
             << "---------- Davi Cândido de Almeida ----------" << endl;
        cout << "-------  Gabriela de Assis dos Reis ---------" << endl
             << "-------- Lucas Carneiro Nassau Malta --------" << endl
             << "------------- João Pedro Torres -------------" << endl;
            << "------------- Vitor Leite Setragni -------------" << endl;
        cout << "---------------------------------------------" << endl;

        cout << "\n> Menu " << endl << endl;
        cout << "Escolha uma implementação:" << endl << endl;
        cout << "1) Matriz de Adjacências" << endl;
        cout << "2) Lista de Adjacências" << endl;
        cout << "0) Sair" << endl << endl;

        do {
            opcao = lerInteiro("Opção: ", 0, 2);

            switch (opcao) {
                case 1:
                    (new MenuMatriz())->menu();
                    break;
                case 2:
                    (new MenuLista())->menu();
                    break;
                case 0:
                    cout << "\nSaindo..." << endl;
                    break;
                default:
                    cout << "\nOpção inválida. Tente novamente." << endl;
                    break;
            }
        } while (opcao != 0);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
