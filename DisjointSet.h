//
// Created by tymek on 08/05/19.
//

#ifndef ALGORITHMS_LEARNING_2_DISJOINTSET_H
#define ALGORITHMS_LEARNING_2_DISJOINTSET_H

#include <vector>
#include "Edge.h"

using namespace std;

class DisjointSet {
    int* parent;
    int* rank;
    int size;  // size

public:
    explicit DisjointSet(int size);
    ~DisjointSet();

    int find_parent(int node);
    void make_union(int u, int v);
};


#endif //ALGORITHMS_LEARNING_2_DISJOINTSET_H
