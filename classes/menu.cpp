//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#include "menu.h"
#include "transporte.h"
#include<iostream>
#include<string>

using namespace std;

Menu::Menu() = default;


Grafo Menu::load(){
    int origem, destino, capacidade, duracao, vertices, ramos, numero, contador=0;

    ifstream file("../Tests_B/in01_b.txt");
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


void Menu::program(){
    Grafo grafo = load();

    cout <<"Cenario 1.1: " << grafo.maxGrupo() << endl;
    cout << "nos finais "<<grafo.get_nos().size() << " " <<grafo.get_num_nos()<<endl;
}



