//
// Created by tymek on 25/04/19.
//

#ifndef ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
#define ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H

#include <iostream>

using namespace std;

class Adjacency_list {
    struct List_element {
        List_element *next;
        int v;
    };

    int vertex_number, edge_number, start, end;
    List_element **list;

public:
    Adjacency_list(int vertex_number, int edge_number);
    void print();

};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
