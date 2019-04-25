#include <iostream>

#include "Adjacency_list.h"
#include "Adjacency_matrix.h"

using namespace std;


int main() {
    int vertex_number, edge_number;

    cout << "Podaj liczbe wierzcholkow i krawedzi: ";
    cin >> vertex_number >> edge_number;


//    Adjacency_matrix* matrix = new Adjacency_matrix(vertex_number, edge_number);
//    matrix->print();

    Adjacency_list* list = new Adjacency_list(vertex_number, edge_number);
    list->print();

    return 0;
}