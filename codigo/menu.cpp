//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#include "menu.h"
#include<iostream>
#include<string>
#include <chrono>
using namespace std;

Menu::Menu() = default;

Grafo Menu::load(string teste){
    int origem, destino, capacidade, duracao, vertices, ramos, numero, contador=0;

    ifstream file(teste);
    string line;
    getline(file, line);
    istringstream iss(line);
    //get first elements in file -> nodes and paths
    iss >> vertices >> ramos;
    Grafo grafo(vertices);

    while(file >> numero){
        switch (contador) {
            case 0:
                origem = numero;
                break;
            case 1:
                destino = numero;
                break;
            case 2:
                capacidade = numero;
                break;
            case 3:
                duracao = numero;
                grafo.addAresta(origem, destino, capacidade, duracao);
                contador=-1;
                break;
            default:
                break;
        }
        contador++;
    }
    return grafo;
}


void Menu::ex1_1(){

    int valor;
    cout << "Qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    auto start = chrono::high_resolution_clock::now();
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int maxGrupo = grafo.maxGrupo(1, grafo.getNumNos()-1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 1.1: " << maxGrupo <<" e a capacidade maxima"<< endl;
    cout << endl << "Duracao:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex1_2(){

    int valor;
    cout << "Qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    auto start = chrono::high_resolution_clock::now();
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int maxGrupo = grafo.minTransbordos(1, grafo.getNumNos()-1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 1.2: " << maxGrupo <<" e a capacidade maxima para o menor numero de tranbordos"<< endl;
    cout << endl << "Duracao:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_1(){

    int valor, grupo;
    cout << "Qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    cout << "Qual a dimensao do grupo que pretende? " << endl;
    cin >> grupo;
    auto start = chrono::high_resolution_clock::now();
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    bool result = grafo.determinaEncam(1, grafo.getNumNos(), grupo);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if(result)
        cout << "Cenario 2.1: O grupo de " << grupo << " pode ser encaminhado" << endl;
    else
        cout << "Cenario 2.1: O grupo de " << grupo << " nao pode ser encaminhado" << endl;
    cout << endl << "Duracao:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_2(){

    int valor, grupo, incremento;
    cout << "Qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    cout << "Qual a dimensao do grupo que pretende? " << endl;
    cin >> grupo;
    cout << "Qual o incremento a este grupo pretende? " << endl;
    cin >> incremento;
    auto start = chrono::high_resolution_clock::now();
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    bool result = grafo.determinaEncam(1, grafo.getNumNos(), (grupo+incremento));
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if(result)
        cout << "Cenario 2.1: O grupo de  " << grupo << " com incremento de " << incremento << " pode ser encaminhado" << endl;
    else
        cout << "Cenario 2.1: O grupo de  " << grupo << " com incremento de " << incremento << " nao pode ser encaminhado" << endl;
    cout << endl << "Duracao:   " << duration.count() << " microsegundos" << endl;
}
void Menu::ex2_3(){

    int valor;
    cout << "Qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    auto start = chrono::high_resolution_clock::now();
    int grupo=0;
    do{
        grupo++;
    }while(grafo.determinaEncamMax(1, grafo.getNumNos()));
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Cenario 2.3: O tamanho maximo para o grupo e " << grupo << endl;
    cout << endl << "Duracao:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_4(){

    int valor;
    cout << "Qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    auto start = chrono::high_resolution_clock::now();
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int es = grafo.earliestStart(0, grafo.getNumNos());
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 2.4: " << es <<" e o tempo que demora ao grupo para se juntar no destino"<< endl;
    cout << endl << "Duracao:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_5(){

    int valor;
    cout << "Qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    auto start = chrono::high_resolution_clock::now();
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int durMin = grafo.earliestStart(0, grafo.getNumNos()-1);
    int lf = grafo.latestFinish(0, grafo.getNumNos()-1, durMin);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 2.5: " << lf <<" e o tempo que demora ao grupo para se juntar no destino"<< endl;
    cout << endl << "Duracao:   " << duration.count() << " microsegundos" << endl;
}   
void Menu::printCenarios(){
    cout << "Cenario 1.1 primir 1: " << endl;
    cout << "Cenario 1.2 primir 2: " << endl;
    cout << "Cenario 2.1 primir 3: " << endl;
    cout << "Cenario 2.2 primir 4: " << endl;
    cout << "Cenario 2.3 primir 5: " << endl;
    cout << "Cenario 2.4 primir 6: " << endl;
    cout << "Cenario 2.5 primir 7: " << endl;
    cout << "Escolher uma das opcoes: " << endl;
    char opcao;
    cin >> opcao;
    escolhaFuncoes(opcao);
}

void Menu::escolhaFuncoes(char opcao){
    switch (opcao) {
        case '1':
            ex1_1();
            break;
        case '2':
            ex1_2();
            break;
        case '3':
            ex2_1();
            break;
        case '4':
            ex2_2();
            break;
        case '5':
            ex2_3();
            break;
        case '6':
            ex2_4();
            break;
        case '7':
            ex2_5();
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
    }
}

string Menu::escolhaFicheiroTeste(int num){
    string teste;
    switch (num) {
        case 1:
            teste = "../input/in01_b.txt";
            break;
        case 2:
            teste = "../input/in02_b.txt";
            break;
        case 3:
            teste = "../input/in03_b.txt";
            break;
        case 4:
            teste = "../input/in04_b.txt";
            break;
        case 5:
            teste = "../input/in05_b.txt";
            break;
        case 6:
            teste = "../input/in06_b.txt";
            break;
        case 7:
            teste = "../input/in07_b.txt";
            break;
        case 8:
            teste = "../input/in08_b.txt";
            break;
        case 9:
            teste = "../input/in09_b.txt";
            break;
        case 10:
            teste = "../input/in10_b.txt";
            break;
        case 11:
            teste = "../input/in11_b.txt";
            break;
        case 12:
            teste = "../input/in12_b.txt";
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
    }
    return teste;
}