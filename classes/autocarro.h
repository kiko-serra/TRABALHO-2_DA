//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_AUTOCARRO_H
#define TRABALHO_2_DA_AUTOCARRO_H
#include <string>

class Autocarro {
public:
    Autocarro();
    Autocarro(vector<Pessoa> pessoas);
    //Setters
    void set_capacidade(int x);
    void set_duracao(int y);
    void set_custo_pessoa(int z);
    void set_destino(string t);

    //Getters
    int get_capacidade() const;
    int get_duracao() const;
    int get_custo_pessoa() const;
    string get_

private:
    int capacidade;
    int duracao;
    int custo_pessoa;
    string origem;
    string destino;


};


#endif //TRABALHO_2_DA_AUTOCARRO_H
