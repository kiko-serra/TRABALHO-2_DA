//
// Created by Francisco Pimentel Serra on 24/05/2022.
//

#include "grafo.h"

#define INF (INT_MAX/2)

Grafo::Grafo(int num, bool dir) : n(num), hasDir(dir), nos(num + 1) {}

Grafo::Grafo() = default;

/**
 * @brief adds an edge connecting the src node to the dest node with a given weight
 * @param src the source node
 * @param dest the destination node
 * @param line the line the edge belongs
 * @param weight the weight given to the edge
 */
void Grafo::addAresta(int origem,int dest, int capacidade, int custo, int duracao) {
    if (origem<1 || origem>n || dest<1 || dest>n) return;
    nos[origem].adj.push_back({dest, capacidade, custo, duracao});
    if (!hasDir) nos[dest].adj.push_back({dest, capacidade, custo, duracao});
}

/**
 * @brief calculates the shortest distance to a given node
 * @brief time complexity O(E log(V)), E represents the edge relaxations and V the number of nodes
 * @param s the node to calculate the distance to
 */
void Grafo::dijkstra(int s) {
    MinHeap<int, int> q(n, -1);
    for (int v=1; v<=n; v++) {
        nos.at(v).dist = INF;
        q.insert(v, INF);
        nos.at(v).visitado = false;
    }
    nos.at(s).dist = 0;
    q.decreaseKey(s, 0);
    nos.at(s).pred = s;
    while (q.getSize()>0) {
        int u = q.removeMin();
        // cout << "Node " << u << " with dist = " << nodes[u].dist << endl;
        nos.at(u).visitado = true;
        for (auto e : nos.at(u).adj) {
            if (nos.at(u).isOpen){
                double v = e.dest;
                double w = e.weight;

                if (!nos.at(v).visitado && nos.at(u).dist + w < nos.at(v).dist) {
                    nos.at(v).dist = nos.at(u).dist + w;
                    q.decreaseKey(v, nos.at(v).dist);
                    nos.at(v).pred = u;
                }
            }
        }
    }
}

/**
 * @brief calculates the minimum distance between 2 nodes
 * @param a the first node
 * @param b the second node
 * @return the minimum distance between the nodes
 */
double Grafo::dijkstra_distance(int a, int b) {
    dijkstra(a);
    if(nos.at(b).dist == INF) return -1.0;
    return nos.at(b).dist;
}

/**
 * @brief calculates the path from a starting node to a destination node
 * @param a the starting node
 * @param b the destination node
 * @return a list containing the nodes that are part of the path
 */
list<int> Grafo::dijkstra_path(int a, int b) {
    dijkstra(a);
    list<int> path;
    if (dijkstra_distance(a,b) == -1.0) return path;
    path.push_front(b);
    int i = b;
    while( i != a) {
        i = nos[i].pred;
        path.push_front(i);
    }
    return path;
}

/**
 * @brief finds the path that passes through the fewer number of stops
 * @brief time complexity: O(V + E) in which V is the number of nodes and E the number of edges
 * @param v the starting node
 */
void Grafo::bfs(int v) {
    for (int v=1; v<=n; v++)
        nos.at(v).visitado = false;

    nos.at(v).dist = 0;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nos.at(v).visitado = true;
    nos.at(v).pred = v;

    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        for (auto e : nos.at(u).adj) {
            int w = e.dest;
            if (!nos.at(w).visitado) {
                q.push(w);
                nos.at(w).visitado = true;
                nos.at(w).dist = nos.at(u).dist +1;
                nos.at(w).pred = u;
            }
        }
    }
}

/**
 * @brief gets the amount of stops between 2 nodes
 * @param a the starting node
 * @param b the ending node
 * @return the amount of stops between the 2 nodes
 */
int Grafo::bfs_distance(int a, int b) {
    if (a == b) return 0;
    for (int v = 1; v < n; v++) nos[v].dist = -1;
    bfs(a);
    return nos[b].dist;
}

/**
 * @brief calculates the path from a starting node to a destination node
 * @param a the starting node
 * @param b the ending node
 * @return a list containing the nodes that are part of the path
 */
list<int> Grafo::bfs_path(int a, int b) {
    list<int> path;
    if (bfs_distance(a,b) == -1) return path;
    bfs(a);
    path.push_front(b);
    int i = b;

    while( i != a) {
        i = nos.at(i).pred;
        path.push_front(i);
    }
    return path;
}

/**
 * @brief minimum spanning tree to be used in the stops
 * @brief the time complexity is O(E + V), in which E represents the number of edges and V the number of nodes
 * @param s the starting stop
 */
void Grafo::mst(int s) {
    MinHeap<int, double> q(n, -1);

    for(int i = 0; i < nos.size(); i++) {
        nos.at(i).dist = INF;
        nos.at(i).pred = NULL;
        q.insert(i, nos.at(i).dist);
    }
    nos.at(s).dist = 0;
    q.decreaseKey(s, nos.at(s).dist);
    nos.at(s).pred = s;

    while(q.getSize() != 0) {
        int u = q.removeMin();

        for(auto e: nos.at(u).adj) {
            double v = e.dest;
            double w = e.weight;
            if (!nos.at(v).visitado && w < nos.at(v).dist) {
                nos.at(v).dist = w;
                q.decreaseKey(v, nos.at(v).dist);
                nos.at(v).pred = u;
            }
        }
    }
}

/**
 * @brief calculates the minimum distance to go through all the stops from a starting stop
 * @param a the starting stop
 * @return the minimum distance to go through all the stops
 */
double Grafo::mst_distance(int a) {
    mst(a);
    double sum = 0;

    for(No node: nos) {
        if(node.dist != INF)
            sum += node.dist;
    }
    return sum;
}

/**
 * @brief sets node at position "a" isOpen field as false
 * @param a position of the node to close
 */
void Grafo::closeNode(int a) {
    nos.at(a).isOpen = false;
}