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
        int dest;
        int capacidade;
        int custo;
        int duracao;
    };

    struct No {
        vector<Aresta> adj; // The list of outgoing edges (to adjacent nodes)
        int pred;
        bool visitado;
        double dist;
    };
    int n;
    bool hasDir;
    vector<No> nos;
    void dijkstra(int s);
    void bfs(int v);
    void mst(int s);

public:
    Grafo();
    Grafo(int nos, bool dir = false);
    void addAresta(int origem,int dest, int capacidade, int custo, int duracao);
    double dijkstra_distance(int a, int b);
    int bfs_distance(int a, int b);
    list<int> dijkstra_path(int a, int b);
    list<int> bfs_path(int a, int b);
    double mst_distance(int a);
    void closeNo(int a);
};


#endif //TRABALHO_2_DA_GRAFO_H
