//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#ifndef TRABALHO_2_DA_GRAFO_H
#define TRABALHO_2_DA_GRAFO_H

#include "minHeap.h"
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
    void init_grafo(int num) ;
    void addAresta(int origem,int destino, int capacidade, int duracao);
    vector<No> get_nos() const;
    int get_num_nos() const;
    double dijkstra_distance(int a, int b);
    int bfs_distance(int a, int b);
    list<int> dijkstra_path(int a, int b);
    list<int> bfs_path(int a, int b);
    double mst_distance(int a);
    void closeNo(int a);
};


#endif //TRABALHO_2_DA_GRAFO_H
