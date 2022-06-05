//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#ifndef TRABALHO_2_DA_GRAFO_H
#define TRABALHO_2_DA_GRAFO_H

#include "maxHeap.h"
#include <vector>
#include <list>
#include <iostream>
#include <climits>
#include <queue>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

class Grafo {
    struct Aresta {
        int destino_;
        int capacidade_;
        int duracao_;
        int fluxo_;
        int residual_;
    };

    struct No {
        vector<Aresta> adj_; 
        int anterior_;
        bool visitado_;
        int dist_;
        int cap_;
        vector<int> vec_pred_;
        int es_;
        int grauE_;
        int precede_;
        int lf_;
        int grauS_;
    };
    int num_nos_;
    vector<No> nos_;
    bool hasDir_;
    int inicial_;
    int fluxo_max_;

public:
    Grafo(int num, bool dir = false);


    /**
    * @brief adiciona uma aresta que liga o no de origem ao de destino com uma capacidade e duracao
    * @param origem o no de origem
    * @param destino o no de destino
    * @param capacidade a capacidade que a aresta tem para transporte
    * @param duracao a duracao de transporte por esta aresta
    * 
    */
    void addAresta(int origem,int destino, int capacidade, int duracao, int fluxo=0, int residual = 0);

    int getNumNos();


//------------------Cenário 1------------------

    int maxGrupo(int origem, int destino);

    int minTransbordos(int origem, int destino);

    int maxGrupoMultiCaminhos(int origem, int destino);

    void unweightedShortestPathGrafo();

    void inicializaNos();

    vector<int> getCaminhoGrafo(int origem, int destino);

    list<list<int>> getTodosCaminhos(int origem, int destino);

    void print_grafo();

    void printCaminho(vector<int> caminho);

//------------------Cenário 2------------------

    void unweightedShortestPathRede(Grafo *rede);
    vector<int> getCaminhoRede(Grafo rede, int origem, int destino);

    //2.1
    bool determinaEncam(int origem, int destino, int grupo);

    //2.2
    void caminhoMaiorGrupo(int grupo, int incremento);
    void bfs(int v);

    //2.3
    int getFluxoMax();

    //2.4
    int earliestStart(int origem, int destino);
    vector<int> getCaminhoGrafo2(int origem, int destino);

    //2.5
    int latestFinish(int origem, int destino, int durMin);

    int bfs(int& tamanho_max);

    int capacidadeResidual(Aresta a);

    void edmundsKarp(int s, int t);

    Grafo redeResidual(int origem, int destino);

    //Grafo rede_residual();

    int procuraNo(int u, int v);

};


#endif //TRABALHO_2_DA_GRAFO_H
