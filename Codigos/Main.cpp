#include "./libs/io.hpp"
#include "./Visao/MenuMatriz.cpp"
#include <iostream>
#include <string> 

using namespace std;

int main(int argc, char* argv[] ) {

    try{
        int opcao = 0;

        do{
            cout << "--------------------------------------------" << endl;
            cout << "--- Bem vindo ao TP1 de Teoria dos Grafos ---" << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Integrantes: " << endl << " - Augusto Stambassi Duarte" << endl << " - Davi Cândido de Almeida" << endl;
            cout << " - Gabriela de Assis dos Reis" << endl << " - Lucas Carneiro Nassau Malta" << endl << " - João Pedro Torres" << endl;
            cout << "--------------------------------------------" << endl;

            cout << "> Menu " << endl << endl;
            cout << "Escolha uma opção de Instancia:" << endl;
            cout << "1 - Grafo - Matriz de Adjacência" << endl;
            cout << "2 - Grafo - Lista de Adjacência" << endl;
            cout << "0 - Sair" << endl << endl;

            cout << "Opação: ";
            string linha;
            getline(cin, linha);
            opcao = stoi(linha);

            switch(opcao){
                case 1:
                    (new MenuMatriz())->menu();
                    break;
                case 2:
                    cout << "Instancia Lista de Adjacência" << endl;
                    break;
                case 0:
                    cout << "Saindo..." << endl;
                    break;
                default:
                    cout << "Opção inválida. Tente novamente." << endl;
                    break;
            }

            cout << endl <<"Pressione Enter para continuar...";
            // cin.ignore();   // limpa o Enter do buffer
            cin.get();      // espera o Enter

        } while(opcao != 0);

    } catch(exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}