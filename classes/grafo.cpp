//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"

#define INF (INT_MAX/2)

Grafo::Grafo(int num) : n(num), nos(num + 1) {}

Grafo::Grafo() = default;

/**
 * @brief adds an edge connecting the src node to the dest node with a given weight
 * @param origem the source node
 * @param dest the destination node
 * @param capacidade the line the edge belongs
 * @param duracao the weight given to the edge
 */

void Grafo::addAresta(int origem,int dest, int capacidade, int duracao) {
    if (origem<1 || origem>n || dest<1 || dest>n) return;
    nos[origem].adj.push_back({dest, capacidade, duracao});
}

void Grafo::init_grafo(int num) {
    nos.clear();
    No aux;
    aux.dist=0;
    aux.pred=0;
    aux.visitado=0;
    aux.adj={};
    for (int i = 0; i <= num; ++i) {
        nos.push_back(aux);
    }
    n=num;
}
