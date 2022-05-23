//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#include "menu.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

Menu::Menu(Transporte transporte){
    this->transporte = transporte;

    load();

}

void Menu::load(){
    Autocarro autocarro;
    int capacidade, duracao;
    int vertices, ramos;

    ifstream file("../Tests_B/in01_b.txt");
    string line;

    if(file.is_open()){
        getline(file, line);
        vertices = stoi(line.substr(0,3));
        ramos = stoi(line.substr(4, ))

        while(!file.eof()){
            getline(file, line);


        }
    }
}