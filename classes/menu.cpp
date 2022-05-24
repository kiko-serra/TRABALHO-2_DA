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
    int origem, destino, capacidade, duracao, vertices, ramos;

    ifstream file("../Tests_B/in01_b.txt");
    int numero;
    istringstream iss= getline(file);
    int contador=0;
    while(file >> numero){
        if (!contador)
            transporte.get_grafo().init_grafo(vertices);
        else if(contador == 1){
            ramos = numero;
        }
        else
            origem=numero;
        cout << contador << " "<< numero << endl;
        contador++;
    }
/*
        else{
            origem = aux[0];
            destino = aux[1];
            capacidade = aux[2];
            duracao = aux[3];
            transporte.get_grafo().addAresta(origem, destino, capacidade, duracao);
        }
        contador++;
*/
}