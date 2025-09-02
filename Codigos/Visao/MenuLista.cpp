#include <iostream>
#include <string>

#include "../EstruturaDeDados/Lista/GrafoLista.cpp"

using namespace std;


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

void intanciaGrafo(){
    int direcional = 0;
    int quantidadeV = 0;
    while(direcional == 1 || direcional == 2){
        cout << "Você vai contruir um grafo direcional ou não direcional" << endl;
        cout << "digite o numero referente a sua resposta" << endl;
        cout << "1 - direcional" << endl;
        cout << "2 - nao direcional" << endl;
        cout << "Digitou :";
        cin >> direcional;
        if(direcional != 1 || direcional != 2){
            cout << "Opcao invalida pofavor selecione uma das opções" << endl;
        }
    }
    cout << "Insira quantos vertices possui seu grafo:";
    cin >> quantidadeV;
    //Agora tem que chamar uma função de GrafoLista que ainda não foi feito
}

void adicionaVertice(){
    string rotulo;
    int peso = 1;
    bool respostas = false;
    cout << "Deseja colocar rotulo no seu vertice?" << endl;
    cout << "0 - não" << endl << "1 - sim" << endl;
    cin >> respostas;
    if (respostas){
       cout << "Digite o rotulo que queira adicionar ao vertice" << endl;
       cin >> rotulo;
    }
    cout << "Deseja alterar o peso do seu vertice?" << endl;
    cout << "0 - não" << endl << "1 - sim" << endl;
    cin >> respostas;
    if (respostas){
       cout << "Digite o peso que queira atribuir ao vertice" << endl;
       cin >> peso;
    }
    //Agora tem que chamar uma função de GrafoLista que ainda não foi feito
}

void adicionaAresta(){
    string rotulo;
    int peso = 1;
    bool respostas = false;
    cout << "Deseja colocar rotulo na seu aresta" << endl;
    cout << "0 - não" << endl << "1 - sim" << endl;
    cin >> respostas;
    if (respostas){
       cout << "Digite o rotulo que queira adicionar á aresta" << endl;
       cin >> rotulo;
    }
    cout << "Deseja alterar o peso da sua aresta?" << endl;
    cout << "0 - não" << endl << "1 - sim" << endl;
    cin >> respostas;
    if (respostas){
       cout << "Digite o peso que queira atribuir á aresta" << endl;
       cin >> peso;
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
