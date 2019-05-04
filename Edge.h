//
// Created by tymek on 04/05/19.
//

#ifndef ALGORITHMS_LEARNING_2_EDGE_H
#define ALGORITHMS_LEARNING_2_EDGE_H


struct Edge {
    int source;
    int destination;
    int weight;

    explicit Edge(int src = 0, int dest = 0, int weight = 0) {
        this->source = src;
        this->destination = dest;
        this->weight = weight;
    }
};

struct CompareWeight {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight;
    }
};


#endif //ALGORITHMS_LEARNING_2_EDGE_H
