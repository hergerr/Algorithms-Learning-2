#include <iostream>

#include "Adjacency_list.h"
#include "Adjacency_matrix.h"

using namespace std;


int main() {
//    Adjacency_matrix *matrix = new Adjacency_matrix("x.txt");
//    matrix->print();

    Adjacency_list* list = new Adjacency_list("x.txt");
    list->print();

    return 0;
}