//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_MENU_H
#define TRABALHO_2_DA_MENU_H

#include "grafo.h"
class Menu {
public:

    /**
    * @brief carrega e cria um grafo consuante um ficheiro lido
    * @return grafo populado
    */
    Grafo load(string teste);

    /**
    * @brief chama a funcao e guarda o grafo
    */

    void ex1_1();

    void ex1_2();

    void ex2_1();

    void ex2_2();

    void ex2_3();

    void ex2_4();

    void ex2_5();

    string escolhaFicheiroTeste(int num);

    void escolhaFuncoes(char opcoes);

    void escolhaFicheiro();

    void printCenarios();

    //Constructor
    Menu();
};


#endif //TRABALHO_2_DA_MENU_H
