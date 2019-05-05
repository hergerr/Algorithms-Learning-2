//
// Created by tymek on 25/04/19.
//

#ifndef ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H
#define ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H

#include<string>
#include <queue>
#include <list>
#include<iostream>
#include <fstream>
#include "Edge.h"

using namespace std;

class Adjacency_matrix {
    int **graph;
    int **spanningTree;
    priority_queue<Edge, vector<Edge>, CompareWeight> queue;
    bool directed;  // 0 - MST, 1 - SP
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    int startNodeSP;
    const int MAX = 999999999;

public:
    Adjacency_matrix(bool directed);

    ~Adjacency_matrix();

    void load_from_file(string fileName);

    void generate(vector<list<Edge>> g);

    void add_edge(int src, int dest, int weight);

    void print();

    void print(int **graph);

    void clear();

    void prim();

    void kruskal();

    void dijkstra();

    void fordBellman();
};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H
