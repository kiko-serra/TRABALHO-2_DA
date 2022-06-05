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
    auto start = chrono::high_resolution_clock::now();
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int maxGrupo = grafo.maxGrupo(1, grafo.getNumNos()-1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 1.1: " << maxGrupo <<" é a capacidade máxima"<< endl;
    cout << endl << "Duração:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex1_2(){
    auto start = chrono::high_resolution_clock::now();
    int valor, maxGrupo;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    //int maxGrupo = grafo.unweightedShortestPathGrafo();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 1.2: " << maxGrupo <<" é a capacidade máxima para o menor número de tranbordos"<< endl;
    cout << endl << "Duração:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_1(){
    auto start = chrono::high_resolution_clock::now();
    int valor, grupo;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    cout << "Qual a dimensao do grupo que pretende? " << endl;
    cin >> grupo;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    bool result = grafo.determinaEncam(1, grafo.getNumNos(), grupo);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if(result)
        cout << "Cenario 2.1: O grupo de " << grupo << " pode ser encaminhado" << endl;
    else
        cout << "Cenario 2.1: O grupo de " << grupo << " não pode ser encaminhado" << endl;
    cout << endl << "Duração:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_2(){
    auto start = chrono::high_resolution_clock::now();
    int valor, grupo, incremento;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    cout << "Qual a dimensao do grupo que pretende? " << endl;
    cin >> grupo;
    cout << "Qual o incremento a este grupo pretende? " << endl;
    cin >> incremento;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    bool result = grafo.determinaEncam(1, grafo.getNumNos(), (grupo+incremento));
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if(result)
        cout << "Cenario 2.1: O grupo de  " << grupo << " com incremento de " << incremento << " pode ser encaminhado" << endl;
    else
        cout << "Cenario 2.1: O grupo de  " << grupo << " com incremento de " << incremento << " não pode ser encaminhado" << endl;
    cout << endl << "Duração:   " << duration.count() << " microsegundos" << endl;
}
void Menu::ex2_3(){
    auto start = chrono::high_resolution_clock::now();
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << endl << "Duração:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_4(){
    auto start = chrono::high_resolution_clock::now();
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int es = grafo.earliestStart(0, grafo.getNumNos());
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 2.4: " << es <<" é o tempo que demora ao grupo para se juntar no destino"<< endl;
    cout << endl << "Duração:   " << duration.count() << " microsegundos" << endl;
}

void Menu::ex2_5(){
    auto start = chrono::high_resolution_clock::now();
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int durMin = grafo.earliestStart(0, grafo.getNumNos()-1);
    int lf = grafo.latestFinish(0, grafo.getNumNos()-1, durMin);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout <<"Cenario 2.5: " << lf <<" é o tempo que demora ao grupo para se juntar no destino"<< endl;
     cout << endl << "Duração:   " << duration.count() << " microsegundos" << endl;
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
            teste = "../Tests_B/in07_b.txt";
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