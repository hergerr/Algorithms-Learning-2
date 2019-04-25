//
// Created by tymek on 25/04/19.
//

#include "Adjacency_matrix.h"

Adjacency_matrix::Adjacency_matrix(string file_name) {

    ifstream in_file;
    in_file.open(("../" + file_name));
    if (!in_file) {
        cout << "Nie można otworzyć pliku\n";
        exit(1); // terminate with error
    }

    in_file >> edge_number;
    in_file >> vertex_number;

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
        in_file >> x >> y >> w;
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
