//
// Created by tymek on 25/04/19.
//

#include "Adjacency_matrix.h"

Adjacency_matrix::Adjacency_matrix(int vertex_number, int edge_number) {
    this->edge_number = edge_number;
    this->vertex_number = vertex_number;

    matrix = new Edge *[vertex_number];


    //tworzenie wierszy macierzy
    for (int i = 0; i < vertex_number; ++i)
        matrix[i] = new Edge[vertex_number];


    //zapelnienie jej zerami
    for (int i = 0; i < vertex_number; ++i) {
        for (int j = 0; j < vertex_number; ++j) {
            matrix[i][j].exists = 0;
        }
    }

    for (int i = 0; i < edge_number; ++i) {
        cin >> x >> y;
        matrix[x][y].exists = 1;
    }
}

void Adjacency_matrix::print() {
    for (int i = 0; i < vertex_number; ++i) {
        for (int j = 0; j < vertex_number; ++j) {
            cout << matrix[i][j].exists << " ";
        }
        cout << endl;
    }
}

Adjacency_matrix::~Adjacency_matrix() {
    for(int i = 0; i < vertex_number; i++) delete [] matrix[i];
    delete [] matrix;
}
