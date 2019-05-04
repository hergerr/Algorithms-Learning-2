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
    priority_queue<Edge, vector<Edge>, CompareWeight> priorQueue;
    bool directed;  // 0 - MST, 1 - SP
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    int startNodeSP;
    const int MAX = 999999999;


public:
    // konstruktor i destruktor
    Adjacency_list(bool directed);
    ~Adjacency_list();

    // glowne funkcje
    void load_from_file(string file_name);
    vector<list<Edge>> generate(int nodes, double density);
    void add_edge(int src, int dest, int weight);
    void print();
    void clear();

    // algorytmy
    void prim();


};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
