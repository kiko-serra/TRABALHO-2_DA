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

using namespace std;

class Grafo {
    struct Aresta {
        int destino_;
        int capacidade_;
        int duracao_;
    };

    struct No {
        vector<Aresta> adj; // The list of outgoing edges (to adjacent nodes)
        int anterior_;
        bool visitado_;
        int dist_;
    };
    int num_nos_;
    vector<No> nos_;
    void dijkstra(int s);
    void bfs(int v);
    void mst(int s);

public:
    Grafo();
    Grafo(int num);

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
    void addAresta(int origem,int destino, int capacidade, int duracao);

    /**
    * @brief Getter para facil acesso ao vetor de nos do grafo
    * @return vetor de nos do grafo
    */
    vector<No> get_nos() const;


    /**
    * @brief facil acesso ao numero de nos do grafo
    * @return inteiro com o numero de nos do grafo
    */
    int get_num_nos() const;

    int maxGrupo();


    double dijkstra_distance(int a, int b);
    int bfs_distance(int a, int b);
    list<int> dijkstra_path(int a, int b);
    list<int> bfs_path(int a, int b);
    double mst_distance(int a);
    void closeNo(int a);
};


#endif //TRABALHO_2_DA_GRAFO_H
