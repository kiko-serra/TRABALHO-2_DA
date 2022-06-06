//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"
#include "maxHeap.h"
#include "minHeap.h"
using namespace std;

#define INF INT_MAX

Grafo::Grafo(int num, bool dir) :  num_nos_(num), nos_(num + 1) {}

int Grafo::getNumNos() {
    return num_nos_;
}

void Grafo::addAresta(int origem,int destino, int capacidade, int duracao, int fluxo, int residual) {
    if (origem < 1 || origem > num_nos_ || destino < 1 || destino > num_nos_){
        return;
    }
    nos_[origem].adj_.push_back({destino, capacidade, duracao, fluxo, residual});

}

void Grafo::inicializaNos(){
    for(auto &n: nos_) {
        n.visitado_ = false;
        n.anterior_ = -1;
        n.cap_ = 0;
        n.dist_ = INF;
    }

    nos_[0].visitado_ = true;
    nos_[1].cap_ = INF;
    nos_[1].dist_ = 0;
    nos_[1].anterior_ = -1;
}

void Grafo::printCaminho(vector<int> caminho) {
    cout << "Caminho: ";
    for (auto &i : caminho) {
        cout << i << " -> ";
    }
    cout << endl;
    cout << "Numero de nos: " << caminho.size() << endl;
}

//1.1
int Grafo::maxGrupo(int origem, int destino) {
    inicializaNos();

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
    printCaminho(getCaminhoGrafo(1, num_nos_));
    return nos_[destino].cap_;
}

vector<int> Grafo::getCaminhoGrafo(int origem, int destino) {
    vector<int> caminho;
    if(!nos_[destino].visitado_) return caminho;
    caminho.push_back(destino);
    while (destino != origem) {
        destino = nos_[destino].anterior_;
        caminho.push_back(destino);

    }
    reverse(caminho.begin(), caminho.end());
    return caminho;
}

//1.2


//2
void Grafo::unweightedShortestPathRede(Grafo *rede){
    inicializaNos();
    queue<int> fila;
    fila.push(1);
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        for (auto &w : (*rede).nos_[u].adj_) {
            if (!(*rede).nos_[w.destino_].visitado_) {
                (*rede).nos_[w.destino_].dist_ = (*rede).nos_[u].dist_ + 1;
                (*rede).nos_[w.destino_].anterior_ = u;
                fila.push(w.destino_);
                (*rede).nos_[w.destino_].visitado_ = true;
            }
        }
    }
    for (int i = 1; i <= (*rede).num_nos_; i++) {
        (*rede).nos_[i].dist_ = (*rede).nos_[i].dist_;
        (*rede).nos_[i].anterior_ = (*rede).nos_[i].anterior_;
    }
}

Grafo Grafo::redeResidual(int origem, int destino) {
    Grafo rede(num_nos_);
    for (int i = 1; i <= num_nos_; i++) {
        for (auto &w : nos_[i].adj_) {
            if (w.capacidade_ - w.fluxo_> 0) {
                rede.addAresta(i, w.destino_, w.capacidade_, w.duracao_, 0, w.capacidade_ - w.fluxo_);
            }
        }
    }

    for(int i = 1 ; i<= num_nos_; i++){
        for(auto &w : nos_[i].adj_){
            if(w.fluxo_ > 0){
                rede.addAresta(w.destino_, i, w.fluxo_, w.duracao_, 0, w.fluxo_);
            }
        }
    }

    return rede;
}

int Grafo::imprimeCaminho2(int origem, int destino) {

    int somaFluxo = 0, duracaoCam = 0, maiorCaminho = 0;
    for(auto &w : nos_[origem].adj_){
        if(w.fluxo_ > 0){
            somaFluxo += w.fluxo_;
        }
    }

    while(somaFluxo > 0){
        for(auto &w: nos_[origem].adj_){
            if(w.fluxo_ != 0){
                cout <<endl<<  w.fluxo_ << " pessoas foram por este caminho: " << endl;
                cout << "->  " << origem << " ->  " << w.destino_;
                somaFluxo -= w.fluxo_;
                duracaoCam += w.duracao_;
                w.fluxo_=0;
                caminhoRestante(w.destino_, destino,  &duracaoCam);
            }
            if(maiorCaminho < duracaoCam){
                maiorCaminho = duracaoCam;
            }
            duracaoCam = 0;
        }
    }

    return maiorCaminho;
}

void Grafo::caminhoRestante(int origem, int destino, int *duracaoCam) {
    if(origem == destino){
        cout << endl<<"Duracao: " << (*duracaoCam) << endl << endl;
        return;
    }

    for(auto &w: nos_[origem].adj_){
        if(w.fluxo_ > 0){
            cout << " ->  " << w.destino_;
            (*duracaoCam) += w.duracao_;
            w.fluxo_=0;
            caminhoRestante(w.destino_, destino, duracaoCam);
            break;
        }
    }
}

//2.1 - 2.2 
bool Grafo::determinaEncam(int origem, int destino, int grupo) {
    int capResidual = INT32_MAX;
    Grafo rede = Grafo::redeResidual(origem, destino);
    unweightedShortestPathRede(&rede);
    vector<int> caminho = Grafo::getCaminhoRede(rede,origem, destino);

    while(grupo>0){
        if(caminho.empty()){
            cout << "Dimensao do grupo muito grande" << endl;
            return false;
        }
        for(int i = 0; i<caminho.size(); i++){
            for(auto &w : rede.nos_[caminho[i]].adj_){
                if(w.destino_ == caminho[i+1]){
                    capResidual=min(w.residual_, capResidual);
                }
            }
        }
        for(int i = 0; i<caminho.size(); i++){
            for(auto &w : nos_[caminho[i]].adj_){
                if(w.destino_ == caminho[i+1]){
                    w.fluxo_ += capResidual;
                }
            }
        }
        rede = redeResidual(origem, destino);
        unweightedShortestPathRede(&rede);
        caminho = getCaminhoRede(rede, origem, destino);
        grupo-=capResidual;
    }
    imprimeCaminho2(origem, destino);
    return true;
}

//2.3
int Grafo::determinaEncamMax(int origem, int destino) {
    int capResidual = INT32_MAX;
    Grafo rede = Grafo::redeResidual(origem, destino);
    unweightedShortestPathRede(&rede);
    vector<int> caminho = Grafo::getCaminhoRede(rede,origem, destino);

    while(rede.nos_[destino].visitado_){
        for(int i = 0; i<caminho.size(); i++){
            for(auto &w : rede.nos_[caminho[i]].adj_){
                if(w.destino_ == caminho[i+1]){
                    capResidual=min(w.residual_, capResidual);
                }
            }
        }
        for(int i = 0; i<caminho.size(); i++){
            for(auto &w : nos_[caminho[i]].adj_){
                if(w.destino_ == caminho[i+1]){
                    w.fluxo_ += capResidual;
                }
            }
        }
        rede = redeResidual(origem, destino);
        unweightedShortestPathRede(&rede);
        caminho = getCaminhoRede(rede, origem, destino);

    }
    int fluxoMax = 0;
    for(auto &w: nos_[origem].adj_)
        fluxoMax += w.fluxo_;
    
    imprimeCaminho2(origem, destino);
    return fluxoMax;
}

vector<int> Grafo::getCaminhoRede(Grafo rede, int origem, int destino) {
    vector<int> caminho;
    if(!rede.nos_[destino].visitado_) return caminho;
    caminho.push_back(destino);
    while (destino != origem) {
        destino = rede.nos_[destino].anterior_;
        caminho.push_back(destino);
    }
    reverse(caminho.begin(), caminho.end());
    return caminho;
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
    printCaminho(getCaminhoGrafo2(vf, 1));
    return durMin;
}

vector<int> Grafo::getCaminhoGrafo2(int origem, int destino) {
    vector<int> caminho;

    caminho.push_back(origem);
    while (origem != destino) {
        origem = nos_[origem].precede_;
        caminho.push_back(origem);
    }
    reverse(caminho.begin(), caminho.end());
    return caminho;
}

//2.5
int Grafo::latestFinish(int origem, int destino, int durMin){
    for(auto &v : nos_){
        v.lf_ = durMin;
        v.grauS_ = 0;
    }
    for(auto &v : nos_){
        for(auto &w: v.adj_){
            nos_[w.destino_].grauS_++;
        }
    }

    //grafo transposto
    Grafo Gt(num_nos_);
    for(int i = 1; i <= num_nos_; i++){
        for(auto &w : nos_[i].adj_){
            Gt.addAresta(w.destino_, i, w.capacidade_, w.duracao_);
        }
    }
    int v;
    stack<int> pilha;
    for(int i = 1; i<= num_nos_; i++){
        if(nos_[i].grauS_ == 0){
            pilha.push(i);
        }
    }

    while(pilha.size() != 0){
        int v = pilha.top();
        pilha.pop();
        for(auto &w : Gt.nos_[v].adj_){
            if(nos_[w.destino_].lf_ > nos_[v].lf_ - w.duracao_){
                nos_[w.destino_].lf_ = nos_[v].lf_ - w.duracao_;
                nos_[w.destino_].precede_ = v;
            }
            nos_[w.destino_].grauS_--;
            if(nos_[w.destino_].grauS_ == 0){
                pilha.push(w.destino_);
            }
        }
    }
    return durMin;
}


