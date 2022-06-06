//
// Created by Francisco Pimentel Serra on 23/05/2022.
//

#ifndef TRABALHO_2_DA_MENU_H
#define TRABALHO_2_DA_MENU_H

#include "grafo.h"
class Menu {
public:

    /**
    * @brief carrega e cria um grafo consuante um ficheiro lido
    * @return grafo populado
    */
    Grafo load(string teste);

    /**
     * @brief funcao que carrega os valores de um ficheiro para o grafo e executa o algoritmo maxGrupo
     * 
     */
    void ex1_1();

    /**
     * @brief funcao que carrega os valores de um ficheiro para o grafo e executa o algoritmo maxGrupoMultiCaminhos
     * 
     */
    void ex1_2();

    /**
     * @brief funcao que carrega os valores de um ficheiro para o grafo e executa o algoritmo determinaEncam
    */
    void ex2_1();

    /**
     * @brief funcao que carrega os valores de um ficheiro para o grafo e executa o algoritmo determinaEncam com um incremento no grupo
    */
    void ex2_2();

    /**
     * @brief funcao que carrega os valores de um ficheiro para o grafo e executa o algoritmo determinaEncam e retorna o fluxo maximo
    */
    void ex2_3();

    /**
     * @brief funcao que carrega os valores de um ficheiro para o grafo e executa o algoritmo erliestStart
    */
    void ex2_4();

    /**
     * @brief funcao que carrega os valores de um ficheiro para o grafo e executa o algoritmo latestFinish
    */
    void ex2_5();

    /**
     * @brief funcao que recebe um valor para escolha do ficheiro de teste
     * @return string nome do ficheiro
    */
    string escolhaFicheiroTeste(int num);

    /**
     * @brief funcao que recebe um valor para escolha da funcao a executar
    */
    void escolhaFuncoes(char opcoes);

    /**
     * @brief funcao que imprime o menu
    */
    void printCenarios();

    //Constructor
    Menu();
};


#endif //TRABALHO_2_DA_MENU_H
