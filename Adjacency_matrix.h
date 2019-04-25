//
// Created by tymek on 25/04/19.
//

#ifndef ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H
#define ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H

#include <iostream>

using namespace std;

class Adjacency_matrix {
    struct Edge{
        int exists, weight;
    };
    int vertex_number, edge_number;
    Edge **matrix;
    int x, y;//poczatek i koniec krawedzi

public:
    Adjacency_matrix(int vertex_number, int edge_number);
    ~Adjacency_matrix();
    void print();
};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H
