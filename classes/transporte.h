//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_TRANSPORTE_H
#define TRABALHO_2_DA_TRANSPORTE_H

#include <map>
#include <vector>
#include "grafo.h"

using namespace std;

class Transporte {
    int pessoas_=0;
    Grafo graph_;
public:
    Transporte();

    //Getters
    Grafo get_grafo();
    int get_pessoas() const;
};


#endif //TRABALHO_2_DA_TRANSPORTE_H
