//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"
#include "maxHeap.h"
using namespace std;

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
    nos_.clear();
    No aux{{}, -1, 0, 0};
    for (int i = 0; i <= num; i++) {
        nos_.push_back(aux);
    }
    num_nos_=(int)nos_.size();
}

vector<Grafo::No> Grafo::get_nos() const {
    return nos_;
}

int Grafo::get_num_nos() const{
    return num_nos_;
};

int Grafo::maxGrupo() {

    inicializa_nos();

    MaxHeap<int, int> heap(num_nos_, -5);
    //if -5 -> not found
    for (int i = 1; i <=num_nos_; i++) {
        heap.insert(i, nos_[i].dist_);
    }

    while(heap.getSize() != 0){
        int v = heap.removeMax();
        nos_[v].visitado_=true;
        for(auto &w : nos_[v].adj){
            if (min(nos_[v].dist_, w.capacidade_) > nos_[w.destino_].dist_){
                nos_[w.destino_].dist_=min(nos_[v].dist_, w.capacidade_);
                nos_[w.destino_].anterior_ = v;
                heap.increaseKey(w.destino_,nos_[w.destino_].dist_);
            }
        }
    }
    print_caminho(get_caminho(1, num_nos_-1));
    return nos_[num_nos_-1].dist_;
}

void Grafo::bfs(int v) {
    for (int i = 1; i <= num_nos_; i++) {
        nos_[i].dist_ = INF;
        nos_[i].anterior_ = -1;
        nos_[i].visitado_ = false;
    }
    nos_[v].dist_ = 0;
    queue<int> fila;
    fila.push(v);
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        for (auto &w : nos_[u].adj) {
            if (!nos_[w.destino_].visitado_) {
                nos_[w.destino_].dist_ = nos_[u].dist_ + 1;
                nos_[w.destino_].anterior_ = u;
                fila.push(w.destino_);
                nos_[w.destino_].visitado_ = true;
            }
        }
    }
}
int Grafo::unweighted_shortest_path() {
    bfs(1);
    print_caminho(get_caminho(1, num_nos_-1));
    return nos_[num_nos_-1].dist_;
}



void Grafo::inicializa_nos(){
    for(auto &n: nos_) {
        n.visitado_ = false;
        n.anterior_ = -1;
        n.dist_ = 0;
    }

    nos_[0].visitado_ = true;
    nos_[1].dist_ = INT_MAX;
}

list<int> Grafo::get_caminho(int origem, int destino) {
    list<int> caminho;
    if (nos_[destino].anterior_ == -1) {
        return caminho;
    }
    int node = destino;
    while (node != origem && nos_[node].anterior_ != -1) {
        int pos_anterior = nos_[node].anterior_;
        for (auto &aresta : nos_[pos_anterior].adj) {
            if (aresta.destino_ == node) {
                caminho.push_front(node);
                break;
            }
        }
        node = nos_[node].anterior_;
    }
    caminho.push_front(node);
    return caminho;
}

void Grafo::print_grafo() {
    for (int i = 1; i <=num_nos_; i++) {
        cout << "No " << i << ": ";
        for (auto &aresta : nos_[i].adj) {
            cout << "(" << aresta.destino_ << "," << aresta.capacidade_ << "," << aresta.duracao_ << ") ";
        }
        cout << endl;
    }
}

void Grafo::print_caminho(list<int> caminho) {
    cout << "Caminho: ";
    for (auto &i : caminho) {
        cout << i << " -> ";
    }
    cout << endl;
    cout << "Numero de nos: " << caminho.size() << endl;
}