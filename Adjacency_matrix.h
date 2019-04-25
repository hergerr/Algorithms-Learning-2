//
// Created by tymek on 25/04/19.
//

#ifndef ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H
#define ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H

#include<fstream>
#include <iostream>

using namespace std;

class Adjacency_matrix {
    struct Edge {
        int exists, weight;
    };
    int vertex_number, edge_number;
    Edge **matrix;
    int x, y, w;//poczatek, koniec i waga krawedzi w pliku

public:
    Adjacency_matrix(string file_name);

    ~Adjacency_matrix();

    void print();
};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_MATRIX_H
