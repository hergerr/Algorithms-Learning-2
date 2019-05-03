//
// Created by tymek on 25/04/19.
//

#ifndef ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
#define ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H

#include <iostream>
#include <fstream>

using namespace std;

class Adjacency_list {
    struct List_element {
        List_element *next;
        int v;
        int weight;
    };

    int vertex_number;
    int edge_number, start, end, weight;
    List_element **list;

public:
    Adjacency_list();

    ~Adjacency_list();

    void load_from_file(string file_name);

    void print();

};


#endif //ALGORITHMS_LEARNING_2_ADJACENCY_LIST_H
