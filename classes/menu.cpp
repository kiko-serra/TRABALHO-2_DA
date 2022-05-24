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
}

void Menu::load(){
    int origem, destino, capacidade, duracao, vertices;

    ifstream file("../Tests_B/in01_b.txt");
    string line;
    int contador=0;
    while(!file.eof()) {
        getline(file, line);

        string str = "";
        vector<int> aux;

        for(int i = 0; i <= line.size(); i++) {
            if(line[i] == ' ' || i == line.size()) {
                aux.push_back(stoi(str));
                str = "";
            }
            else {
                str += line[i];
            }
        }
        if (!contador){
            vertices=aux[0];
            transporte.get_grafo().init_grafo(vertices);
        }
        else{
            origem = aux[0];
            destino = aux[1];
            capacidade = aux[2];
            duracao = aux[3];
            transporte.get_grafo().addAresta(origem, destino, capacidade, duracao);
        }
        contador++;


    }
}