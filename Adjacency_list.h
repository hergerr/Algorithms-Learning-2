//
// Created by tymek on 25/04/19.
//

#ifndef ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
#define ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H

#include "Edge.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Adjacency_list {
    vector<list<Edge>> graph;
    vector<list<Edge>> spanning_tree;
    priority_queue<Edge, vector<Edge>, CompareWeight> queue;
    bool directed;  // 0 - MST, 1 - SP
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    int startNodeSP;


public:
    Adjacency_list(bool directed);

    ~Adjacency_list();

    void load_from_file(string file_name);

    void add_edge(int src, int dest, int weight);

    void print();

    void print(vector<list<Edge>> spanning_tree);

    void clear();

    void prim();

};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
