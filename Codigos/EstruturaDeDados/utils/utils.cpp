
/**
 * @file utils.cpp
 * @brief Conjunto de estruturas e definições utilitárias para o manejo dos algoritmos de busca em grafos.
 *
 * Este arquivo contém definições auxiliares, como enumerações de cores para marcação de vértices
 * e variáveis globais utilizadas nos algoritmos de busca em grafos.
 *
 * @enum cores
 * Enumeração que representa as cores utilizadas para marcar o estado dos vértices durante a execução dos algoritmos de busca:
 * - BRANCO: Vértice não visitado.
 * - VERMELHO: Vértice visitado, mas ainda não processado completamente.
 * - PRETO: Vértice totalmente processado.
 *
 * @var tempo
 * Variável global utilizada para controlar o tempo ou ordem de visitação dos vértices nos algoritmos de busca.
 */


enum cores {
    BRANCO,
    VERMELHO,
    PRETO
};


int tempo = 0;