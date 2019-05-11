//
// Created by tymek on 25/04/19.
//

#ifndef ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
#define ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H

#include "Edge.h"
#include "DisjointSet.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <utility>

using namespace std;

class Adjacency_list {
    vector<list<Edge>> graph;
    bool directed;  // 0 - MST, 1 - SP
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    int start_node_SP;
    const int MAX = 999999999;


public:
    Adjacency_list(bool directed);

    ~Adjacency_list();

    void load_from_file(string file_name);

    void add_edge(int src, int dest, int weight);

    void print();

    void clear();

    void prim();

    void kruskal();

    void dijkstra();

};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
