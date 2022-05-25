//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_MENU_H
#define TRABALHO_2_DA_MENU_H

#include "transporte.h"
class Menu {
    Transporte transporte_;

    /**
     * Reach files for test and fill graph
     */



public:
    Grafo load();
    Transporte get_transporte() const;
    void load_data();
    //Constructor
    Menu();
};


#endif //TRABALHO_2_DA_MENU_H
