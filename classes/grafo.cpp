//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"

#define INF (INT_MAX/2)

Grafo::Grafo(int num) : num_nos_(num), nos_(num + 1) {}

Grafo::Grafo() = default;

/**
 * @brief adiciona uma aresta que liga o no de origem ao de destino com uma capacidade e duracao
 * @param origem o no de origem
 * @param destino o no de destino
 * @param capacidade a capacidade que a aresta tem para transporte
 * @param duracao a duracao de transporte por esta aresta
 */
void Grafo::addAresta(int origem,int destino, int capacidade, int duracao) {
    if (origem<1 || origem>num_nos_ || destino<1 || destino>num_nos_){
        return;
    }
    nos_[origem].adj.push_back({destino, capacidade, duracao});

}
/**
 * @brief inicializa o grafo com um certo valor de nos
 * @param num numero de nos lido do ficheiro
 */

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

/**
 * @brief Getter para facil acesso ao vetor de nos do grafo
 * @return vetor de nos do grafo
 */
vector<Grafo::No> Grafo::get_nos() const {
    return nos_;
}

/**
 * @brief facil acesso ao numero de nos do grafo
 * @return inteiro com o numero de nos do grafo
 */
int Grafo::get_num_nos() const{
    return num_nos_;
};