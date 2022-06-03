//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"
#include "maxHeap.h"
#include "minHeap.h"
using namespace std;

#define INF INT_MAX

Grafo::Grafo(int num, bool dir) : inicial_(1), num_nos_(num), nos_(num + 1), hasDir_(dir) {}

int Grafo::getNumNos() {
    return num_nos_;
}

void Grafo::addAresta(int origem,int destino, int capacidade, int duracao, int fluxo) {
    if (origem < 1 || origem > num_nos_ || destino < 1 || destino > num_nos_){
        return;
    }
    nos_[origem].adj_.push_back({destino, capacidade, duracao, fluxo});

}

void Grafo::init_grafo(int num) {
    nos_.clear();
    No aux{{}, -1, 0, 0};
    for (int i = 0; i <= num; i++) {
        nos_.push_back(aux);
    }
    num_nos_=(int)nos_.size();
}

//1.1

int Grafo::maxGrupo(int origem, int destino) {
    for(auto &w : nos_){
        w.cap_=0;
        w.anterior_=-1;
    }
    nos_[origem].anterior_=-1;
    nos_[origem].cap_=INF; 

    MaxHeap<int, int> heap(num_nos_, -5);
    //if -5 -> not found
    for (int i = 1; i <=num_nos_; i++) {
        heap.insert(i, nos_[i].cap_);
    }

    while(heap.getSize() != 0){
        int v = heap.removeMax();
        nos_[v].visitado_=true;
        for(auto &w : nos_[v].adj_){
            if (min(nos_[v].cap_, w.capacidade_) > nos_[w.destino_].cap_ && heap.hasKey(w.destino_)){
                nos_[w.destino_].cap_=min(nos_[v].cap_, w.capacidade_);
                nos_[w.destino_].anterior_ = v;
                heap.increaseKey(w.destino_,nos_[w.destino_].cap_);
            }
        }
    }
    if (nos_[destino].anterior_==-1) return -1;
    print_caminho(getCaminho(1, num_nos_));
    return nos_[destino].cap_;
}

//1.2

int Grafo::minTransbordos(int origem, int destino){

    for(auto &w : nos_){
        w.dist_=INF;
        w.anterior_=-1;
    }
    nos_[origem].dist_=0;
    nos_[origem].anterior_=origem;

    MinHeap<int, int> heap(num_nos_, -5);
    //if -5 -> not found
    for (int i = 1; i <=num_nos_; i++) {
        heap.insert(i, nos_[i].dist_);
    }

    while(heap.getSize()!=0){
        int v = heap.removeMin();
        for(auto &w : nos_[v].adj_){
            if(nos_[v].dist_ + 1 < nos_[w.destino_].dist_ && heap.hasKey(w.destino_)){
                nos_[w.destino_].dist_=nos_[v].dist_ + 1;
                nos_[w.destino_].anterior_ = v;
                heap.decreaseKey(w.destino_,nos_[v].dist_ +1 );
            }
        }
    }
    if(nos_[destino].dist_ == INF) return -1;
    return nos_[destino].dist_ -1;
}

int Grafo::maxGrupoMultiCaminhos(int origem, int destino) {
    for(auto &w : nos_){
        w.cap_=0;
        w.anterior_=-1;
    }
    nos_[origem].anterior_=-1;
    nos_[origem].cap_=INF;

    MaxHeap<int, int> heap(num_nos_, -5);
    //if -5 -> not found
    for (int i = 1; i <=num_nos_; i++) {
        heap.insert(i, nos_[i].dist_);
    }

    while(heap.getSize() != 0){
        int v = heap.removeMax();
        nos_[v].visitado_=true;
        for(auto &w : nos_[v].adj_){
            if(heap.hasKey(w.destino_)){
                if (min(nos_[v].cap_, w.capacidade_) == nos_[w.destino_].cap_){
                    nos_[w.destino_].vec_pred_.push_back(v);
                }else if(min(nos_[v].cap_, w.capacidade_) > nos_[w.destino_].cap_){
                    nos_[w.destino_].vec_pred_.clear();
                    nos_[w.destino_].vec_pred_.push_back(v);
                    nos_[w.destino_].cap_=min(nos_[v].cap_, w.capacidade_);
                    heap.increaseKey(w.destino_,nos_[w.destino_].cap_);
                }
            }
        }
    }
    if(nos_[destino].cap_ == INF) return -1;
    print_caminho(getCaminho(1, num_nos_-1));
    return nos_[destino].dist_;
}

//list<list<int>> Grafo::getTodosCaminhos(){}

//2.1
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
        for (auto &w : nos_[u].adj_) {
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
    print_caminho(getCaminho(1, num_nos_-1));
    return nos_[num_nos_-1].dist_;
}

void Grafo::edmunds_karp(int s, int t) {
    int fluxo_max = 0;
    while (true) {
        bfs(1);
        if (nos_[t].dist_ == INF) {
            break;
        }
        int path_flow = INF;
        for (int v = t; v != s; v = nos_[v].anterior_) {
            path_flow = min(path_flow, nos_[nos_[v].anterior_].adj_[procura_no(nos_[v].anterior_, v)].capacidade_);
        }
        fluxo_max += path_flow;
        for (int v = t; v != s; v = nos_[v].anterior_) {
            int u = nos_[v].anterior_;
            int w = procura_no(u, v);
            nos_[u].adj_[w].capacidade_ -= path_flow;
            nos_[v].adj_[w].capacidade_ += path_flow;
        }
    }
    cout << "Fluxo máximo: " << fluxo_max << endl;
}

Grafo Grafo::residual_grid(int s, int t) {
    Grafo res(num_nos_);
    for (int i = 1; i <= num_nos_; i++) {
        for (auto &w : nos_[i].adj_) {
            res.addAresta(i, w.destino_, w.capacidade_, w.duracao_);
        }
    }
    for (int i = 1; i <= num_nos_; i++) {
        for (auto &w : nos_[i].adj_) {
            res.addAresta(w.destino_, i, 0, -w.duracao_);
        }
    }
    return res;
}


//2.4

int Grafo::earliestStart(int origem, int destino){
    for(auto &v : nos_){
        v.es_ = 0;
        v.precede_ = -1;
        v.grauE_ = 0;
    }

    for(auto &v : nos_){
        for(auto &w : v.adj_){
            nos_[w.destino_].grauE_++;
        }
    }

    stack<int> pilha;
    for(int i = 1; i<= num_nos_; i++){
        if(nos_[i].grauE_ == 0){
            pilha.push(i);
        }
    }

    int durMin = -1, vf = -1, v;

    while(!pilha.empty()){
        v = pilha.top();
        pilha.pop();
        if(durMin < nos_[v].es_){
            durMin = nos_[v].es_;
            vf = v;
        }
        for(auto &w : nos_[v].adj_){
            if(nos_[w.destino_].es_ < nos_[v].es_ + w.duracao_){
                nos_[w.destino_].es_ = nos_[v].es_ + w.duracao_;
                nos_[w.destino_].precede_ = v;
            }
            nos_[w.destino_].grauE_--;
            if(nos_[w.destino_].grauE_ == 0){
                pilha.push(w.destino_);
            }
        }
    }
    print_caminho(getCaminho(vf, nos_[vf].precede_));
    return durMin;
}

int Grafo::procura_no(int u, int v) {
    if (u < 0) return -1;
    for (size_t i = 1; i <= nos_[u].adj_.size(); i++) {
        if (nos_[u].adj_[i].destino_ == v) {
            return i;
        }
    }
    return -1;
}

void Grafo::inicializaNos(){
    for(auto &n: nos_) {
        n.visitado_ = false;
        n.anterior_ = -1;
        n.cap_ = 0;
    }

    nos_[0].visitado_ = true;
    nos_[1].cap_ = INF;
}

list<int> Grafo::getCaminho(int origem, int destino) {
    list<int> caminho;

    int node = destino;
    caminho.push_front(node);
    while (node != origem && nos_[node].anterior_ != -1) {
        node = nos_[node].anterior_;
        caminho.push_front(node);
    }
    return caminho;
}

void Grafo::print_grafo() {
    for (int i = 1; i <=num_nos_; i++) {
        cout << "No " << i << ": ";
        for (auto &aresta : nos_[i].adj_) {
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