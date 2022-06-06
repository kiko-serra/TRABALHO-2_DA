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
    * @brief Retorna o numero de nos do grafo
    * @return int 
    */
    int getNumNos();


    /**
    * @brief adiciona uma aresta que liga o no de origem ao de destino com uma capacidade e duracao
    * @param origem o no de origem
    * @param destino o no de destino
    * @param capacidade a capacidade que a aresta tem para transporte
    * @param duracao a duracao de transporte por esta aresta
    * @param fluxo o fluxo atual da aresta
    * @param residual o fluxo residual da aresta
    */
    void addAresta(int origem,int destino, int capacidade, int duracao, int fluxo=0, int residual = 0);

    /**
     * @brief iniciaializa todos os nos do grado com a capacidade 0 e distancia à origem infinita
     * 
     */
    void inicializaNos();
    
    /**
     * @brief imprime o caminho seguuido pelo grupo
     * 
     * @param caminho vetor com o caminho seguido pelo grupo
     */
    void printCaminho(vector<int> caminho);

//------------------Cenário 1------------------
//---------------------1.1---------------------
    /**
     * @brief procura no grafo qual a capacidade maxima de transporte entre dois nos
     * @param origem valor do no de origem
     * @param destino valor do no de destino
     * @return capacidade maxima de transporte 
     */
    int maxGrupo(int origem, int destino);
    
    /**
     * @brief Com base no grafo procura o caminho seguido pelo grupo
     * 
     * @param origem no de origem do grafo
     * @param destino no de destino do grafo
     * @return vector<int> caminho ordenado do no de origem ao no de destino
     */
    vector<int> getCaminhoGrafo(int origem, int destino);

//---------------------1.2---------------------
    int minTransbordos(int origem, int destino);

    int maxGrupoMultiCaminhos(int origem, int destino);


    list<list<int>> getTodosCaminhos(int origem, int destino);

    

    

//------------------Cenário 2------------------
    /**
     * @brief procura um caminho (se existir) entre dois nos na rede residual
     * 
     * @param rede 
     */
    void unweightedShortestPathRede(Grafo *rede);
    
    /**
     * @brief cria uma rede residua tendo em conta as capacidades e fluxos das arestas do grafo
     * 
     * @param origem no de origem do grafo
     * @param destino no de destino do grafo
     * @return Grafo rede residual 
     */
    Grafo redeResidual(int origem, int destino);

//------------------2.1-2.2-2.3----------------
    /**
     * @brief determina se é possivel encontar um caminho para um grupo de transporte
     * 
     * @param origem no de origem do grafo 
     * @param destino no de destino do grafo
     * @param grupo dimensao do grupo (2.2 recebe o grupo + incremento)
     * @return true se houver caminhos para transportar o grupo ate ao no de destino
     * @return false se não houver caminhos para transportar o grupo ate ao no de destino
     */
    bool determinaEncam(int origem, int destino, int grupo);

    /**
     * @brief Procura o caminho na rede se houver
     * 
     * @param rede rede para procurar o caminho
     * @param origem no de origem do grafo
     * @param destino no de destino do grafo
     * @return vector<int> caminho ordenado do no de origem ao no de destino
     */
    vector<int> getCaminhoRede(Grafo rede, int origem, int destino);


//--------------------2.4--------------------

    /**
     * @brief retorna a duração mínima da viagem do grupo
     * 
     * @param origem no de origem do grafo
     * @param destino no de destino do grafo
     * @return int tempo em horas
     */
    int earliestStart(int origem, int destino);

    /**
     * @brief procura o caminho com base nos precedentes
     * 
     * @param origem no de origem do grafo
     * @param destino no de destino do grafo
     * @return vector<int> caminho ordenado
     */
    vector<int> getCaminhoGrafo2(int origem, int destino);

//--------------------2.5--------------------
    /**
    * @brief retorna a duracao máxima da viagem do grupo
    * 
    * @param origem no de origem do grafo
    * @param destino no de destino do grafo
    * @param durMin duracao mínima da viagem
    * @return int tempo de espera entre a duração maxima e a duração mínima
    */
    int latestFinish(int origem, int destino, int durMin);


    //Nao usados 
    void bfs(int v);
    void edmundsKarp(int s, int t);
    int procuraNo(int u, int v);
    void unweightedShortestPathGrafo();
    void printGrafo();
};


#endif //TRABALHO_2_DA_GRAFO_H
