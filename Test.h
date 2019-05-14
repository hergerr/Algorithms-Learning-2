//
// Created by Tymek on 2019-05-14.
//

#ifndef ALGORITHMS_LEARNING_2_TEST_H
#define ALGORITHMS_LEARNING_2_TEST_H


#include <chrono>
#include "Adjacency_list.h"
#include "Adjacency_matrix.h"

class Test {
public:
    void run_tests();

    void test_prim(int nodes, double density);

    void test_kruskal(int nodes, double density);

    void test_dijkstra(int nodes, double density);

    void test_ford_bellman(int nodes, double density);

private:
    const int tests = 100;

};


#endif //ALGORITHMS_LEARNING_2_TEST_H
