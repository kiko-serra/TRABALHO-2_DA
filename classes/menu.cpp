//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#include "menu.h"
#include "transporte.h"
#include<iostream>
#include<string>

using namespace std;

Menu::Menu() = default;

void Menu::load_data(){
    load();
    cout << transporte.get_grafo().get_nos().size() << endl;
}

void Menu::load(){
    int origem, destino, capacidade, duracao, vertices, ramos, numero, contador=0;

    ifstream file("../Tests_B/in01_b.txt");
    string line;
    getline(file, line);
    istringstream iss(line);
    iss >> vertices >>ramos;
    transporte.get_grafo().init_grafo(vertices);

    while(file >> numero){
        switch (contador) {
            case 0:
                origem = numero;
                break;
            case 1:
                destino=numero;
                break;
            case 2:
                capacidade=numero;
                break;
            case 3:
                duracao=numero;
                transporte.get_grafo().addAresta(origem, destino, capacidade, duracao);
                //cout << origem << " " << destino << " " << capacidade << " " << duracao << endl;
                contador=-1;
                break;
            default:
                break;
        }
        contador++;
    }
    cout << "ola"<< endl;
    cout << transporte.get_grafo().get_nos().size() << endl;
    for (int i = 0; i < transporte.get_grafo().get_nos().size(); i++) {
        cout << "asdf" << endl;
        for (int j = 0; j < transporte.get_grafo().get_nos().at(i).adj.size(); j++) {
            cout << transporte.get_grafo().get_nos().at(i).adj.at(j).dest << ' ' << transporte.get_grafo().get_nos().at(i).adj.at(j).capacidade<< ' '<< transporte.get_grafo().get_nos().at(i).adj.at(j).duracao << endl;
        }
    }
}