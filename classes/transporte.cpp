//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#include "transporte.h"

Transporte::Transporte() {}
Grafo Transporte::get_grafo() {
    return graph_;
}
int Transporte::get_pessoas() const{
    return pessoas_;
}
