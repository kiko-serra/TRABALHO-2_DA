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
    };

    struct No {
        vector<Aresta> adj_; 
        int anterior_;
        bool visitado_;
        int dist_;
        int es_;
        int cap_;
        vector<int> vec_pred_;
        int grauE_;
        int precede_;
    };
    int num_nos_;
    vector<No> nos_;
    bool hasDir_;
    int inicial_;
    int fluxo_max_;

public:
    Grafo(int num, bool dir = false);

    /**
    * @brief inicializa o grafo com um certo valor de nos
    * @param num numero de nos lido do ficheiro
    */
    void init_grafo(int num);

    /**
    * @brief adiciona uma aresta que liga o no de origem ao de destino com uma capacidade e duracao
    * @param origem o no de origem
    * @param destino o no de destino
    * @param capacidade a capacidade que a aresta tem para transporte
    * @param duracao a duracao de transporte por esta aresta
    */
    void addAresta(int origem,int destino, int capacidade, int duracao, int fluxo=0);

    int getNumNos();


//------------------Cenário 1------------------

    int maxGrupo(int origem, int destino);

    int minTransbordos(int origem, int destino);

    int maxGrupoMultiCaminhos(int origem, int destino);

    int unweighted_shortest_path();

    void inicializaNos();

    list<int> getCaminho(int origem, int destino);

    list<list<int>> getTodosCaminhos(int origem, int destino);

    void print_grafo();

    void print_caminho(list<int> caminho);

//------------------Cenário 2------------------
    //2.1
    bool caminhoGrupo(int grupo);

    //2.2
    void caminhoMaiorGrupo(int grupo, int incremento);
    void bfs(int v);

    //2.3
    int getFluxoMax();

    //2.4
    int earliestStart(int origem, int destino);


    int bfs(int& tamanho_max);

    int capacidadeResidual(Aresta a);

    void edmunds_karp(int s, int t);

    Grafo residual_grid(int s, int t);

    //Grafo rede_residual();

    int procura_no(int u, int v);

};


#endif //TRABALHO_2_DA_GRAFO_H
