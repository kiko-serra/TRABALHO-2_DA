//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"

#define INF (INT_MAX/2)

Grafo::Grafo(int num) : num_nos_(num), nos_(num + 1) {}

Grafo::Grafo() = default;


void Grafo::addAresta(int origem,int destino, int capacidade, int duracao) {
    if (origem<1 || origem>num_nos_ || destino<1 || destino>num_nos_){
        return;
    }
    nos_[origem].adj.push_back({destino, capacidade, duracao});

}

void Grafo::init_grafo(int num) {
    cout << "numero de vertices verdadeiro "<< num << endl;
    nos_.clear();
    No aux{{}, 1, 0, 0};
    for (int i = 0; i <= num; i++) {
        nos_.push_back(aux);
    }
    num_nos_=(int)nos_.size();
    cout << "no qualquer " << nos_[num].anterior_ << endl;
    cout << "quantos nos existem " << nos_.size() << " " << num_nos_<< endl;
}

vector<Grafo::No> Grafo::get_nos() const {
    return nos_;
}

int Grafo::get_num_nos() const{
    return num_nos_;
};