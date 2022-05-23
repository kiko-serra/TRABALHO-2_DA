//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_TRANSPORTE_H
#define TRABALHO_2_DA_TRANSPORTE_H

#include "autocarro.h"
#include "pessoa.h"
#include <map>
#include<vector>

using namespace std;

class Transporte {
    vector<Autocarro> autocarros; //autocarros disponiveis
    vector<Pessoa> pessoas //pessoas a transportar
    map<Autocarro, vector<Pessoa>> distribuicao; //quem cada autocarro leva

public:
    Transporte();
    Transporte(vector<Autocarro> autocarros, vector<Pessoa> pessoas);

    //Getters
    vector<Autocarro> get_autocarros() const;
    vector<Pessoa> get_pessoas() const;
    map<Autocarro, vector<Pessoa> pessoas> get_distribuicao() const;

    //Setters
    void set_autocarros(vector<Autocarro> autocarros);
    void set_pessoas(vector<Pessoa> pessoas);
    void set_distribuicao(map<Autocarro, vector<Pessoa>> distri);
};


#endif //TRABALHO_2_DA_TRANSPORTE_H
