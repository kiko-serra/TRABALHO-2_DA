//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_MENU_H
#define TRABALHO_2_DA_MENU_H

#include "transporte.h"
class Menu {
    Transporte transporte;

    /**
     * Reach files for test and fill graph
     */
     void load();

public:
    //Constructor
    Menu(Transporte transporte);
};


#endif //TRABALHO_2_DA_MENU_H
