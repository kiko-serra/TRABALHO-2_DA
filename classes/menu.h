//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_MENU_H
#define TRABALHO_2_DA_MENU_H

#include "transporte.h"
class Menu {

    /**
     * Reach files for test and fill graph
     */



public:

    /**
    * @brief carrega e cria um grafo consuante um ficheiro lido
    * @return grafo populado
    */
    Grafo load();

    /**
    * @brief chama a funcao e guarda o grafo
    */

    void program();

    //Constructor
    Menu();
};


#endif //TRABALHO_2_DA_MENU_H
