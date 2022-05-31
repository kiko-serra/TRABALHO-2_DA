//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"
#include "maxHeap.h"

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
    No aux{{}, -1, 0, 0};
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

int Grafo::maxGrupo() {
    int res;

    for(auto &n: nos_) {
        n.visitado_ = false;
        n.anterior_ = -1;
        n.dist_ = 0;
    }

    nos_[0].visitado_ = true;
    nos_[1].dist_ = INT_MAX;

    MaxHeap<int, int> heap(num_nos_, -5);
    //if -5 -> not found
    for (int i = 1; i <=num_nos_; i++) {
        heap.insert(i, nos_[i].dist_);
    }
    //erro aqui -> nao altera o anterior
    while(heap.getSize() != 0){
        int v = heap.removeMax();
        nos_[v].visitado_=true;
        for(auto &w : nos_[v].adj){
            if (min(nos_[v].dist_, w.capacidade_) > nos_[w.destino_].dist_){
                cout << "jerjgjerg" << endl;
                nos_[w.destino_].dist_=min(nos_[v].dist_, w.capacidade_);
                nos_[w.destino_].anterior_ = v;
                heap.increaseKey(w.destino_,nos_[w.destino_].dist_);
            }
        }
    }
    int node = num_nos_;
    cout << "nos: " << nos_[node].anterior_ << endl;
    int capacity = INT_MAX;
    while(nos_[node].anterior_ != -1 && node != 1){
        int pos_anterior = nos_[node].anterior_;
        for (auto &aresta : nos_[pos_anterior].adj) {
            if (aresta.destino_==node){
                if(capacity > aresta.capacidade_)
                    capacity=aresta.capacidade_;
            }
        }
        node= nos_[node].anterior_;
    }
    return capacity;
}