//
// Created by tymek on 08/05/19.
//

#ifndef ALGORITHMS_LEARNING_2_DISJOINTSET_H
#define ALGORITHMS_LEARNING_2_DISJOINTSET_H


class DisjointSet {
    int *array;
    int size;

public:
    DisjointSet(int size);
    ~DisjointSet();

    int find(int x);
    void make_union(int u, int v);
};


#endif //ALGORITHMS_LEARNING_2_DISJOINTSET_H
