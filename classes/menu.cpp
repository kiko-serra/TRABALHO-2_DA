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

    cout << grafo.get_num_nos() << " isto é o numero de nos " << endl;
    //tests
    /*cout << " vertices " << vertices << endl;
    cout << "ramos " << ramos << endl;
    cout << "size " <<grafo.get_nos().size() << endl;
    */

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
                //cout << origem << " " << destino << " " << capacidade << " " << duracao << endl;
                contador=-1;
                break;
            default:
                break;
        }
        contador++;
    }
    //imprime as arestas do grafo
    for (int i = 0; i < grafo.get_nos().size(); i++) {
        for (int j = 0; j < grafo.get_nos()[i].adj.size(); j++) {
            //cout << "entrou segundo for " << endl;
            //cout << i << " "<<grafo.get_nos()[i].adj[j].destino_ << ' ' << grafo.get_nos()[i].adj[j].capacidade_<< ' '<< grafo.get_nos()[i].adj[j].duracao_ << endl;
        }
    }
    return grafo;
}


void Menu::ex1_1(){
    int valor;
    cout << "qual o ficheiro de teste? 1-10" << endl;
    cin >> valor;
    Grafo grafo = load(escolhaFicheiroTeste(valor));
    int maxGrupo = grafo.maxGrupo();
    cout <<"Cenario 1.1: " << maxGrupo << endl;
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
            
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
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
        default:
            cout << "Opcao invalida" << endl;
            break;
    }
    return teste;
}