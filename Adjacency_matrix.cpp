//
// Created by tymek on 25/04/19.
//

#include "Adjacency_matrix.h"

Adjacency_matrix::Adjacency_matrix(int vertex_number, int edge_number) {
    this->edge_number = edge_number;
    this->vertex_number = vertex_number;

    matrix = new int *[vertex_number];


    //tworzenie wierszy macierzy
    for (int i = 0; i < vertex_number; ++i)
        matrix[i] = new int[vertex_number];


    //zapelnienie jej zerami
    for (int i = 0; i < vertex_number; ++i) {
        for (int j = 0; j < vertex_number; ++j) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < edge_number; ++i) {
        cin >> x >> y;
        matrix[x][y] = 1;
    }
}

void Adjacency_matrix::print() {
    for (int i = 0; i < vertex_number; ++i) {
        for (int j = 0; j < vertex_number; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
