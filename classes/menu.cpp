//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#include "menu.h"
#include<iostream>
#include<string>

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
    Grafo grafo;
    grafo.init_grafo(vertices);

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
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int maxGrupo = grafo.maxGrupo();
    cout <<"Cenario 1.1: " << maxGrupo <<" é a capacidade máxima"<< endl;
}

void Menu::ex1_2(){
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int maxGrupo = grafo.unweighted_shortest_path();
    cout <<"Cenario 1.2: " << maxGrupo <<" é a capacidade máxima para o menor número de tranbordos"<< endl;
}

void Menu::ex2_1(){
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    grafo.edmunds_karp(0, grafo.get_num_nos()-1);
    grafo.get_caminho(0, grafo.get_num_nos()-1);
}

void Menu::ex2_2(){
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    grafo.inicializa_nos();
    grafo.unweighted_shortest_path();
    grafo.get_caminho(0, grafo.get_num_nos()-1);
}

void Menu::ex2_3(){
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    grafo.inicializa_nos();
    grafo.unweighted_shortest_path();
    grafo.get_caminho(0, grafo.get_num_nos()-1);
}

void Menu::ex2_4(){
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    grafo.inicializa_nos();
    grafo.unweighted_shortest_path();
    grafo.get_caminho(0, grafo.get_num_nos()-1);
}

void Menu::ex2_5(){
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    grafo.inicializa_nos();
    grafo.unweighted_shortest_path();
    grafo.get_caminho(0, grafo.get_num_nos()-1);
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
            teste = "../Tests_B/in01_b.txt";
            break;
        case 2:
            teste = "../Tests_B/in02_b.txt";
            break;
        case 3:
            teste = "../Tests_B/in03_b.txt";
            break;
        case 4:
            teste = "../Tests_B/in04_b.txt";
            break;
        case 5:
            teste = "../Tests_B/in05_b.txt";
            break;
        case 6:
            teste = "../Tests_B/in06_b.txt";
            break;
        case 7:
            teste = "../Tests_B/in07_b.txt";
            break;
        case 8:
            teste = "../Tests_B/in08_b.txt";
            break;
        case 9:
            teste = "../Tests_B/in09_b.txt";
            break;
        case 10:
            teste = "../Tests_B/in10_b.txt";
            break;
        case 11:
            teste = "../Tests_B/in11_b.txt";
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
    }
    return teste;
}