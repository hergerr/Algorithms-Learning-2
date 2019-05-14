//
// Created by tymek on 04/05/19.
//

#ifndef ALGORITHMS_LEARNING_2_EDGE_H
#define ALGORITHMS_LEARNING_2_EDGE_H


class Edge {
public:
    int source;
    int destination;
    int weight;

    Edge(int src = 0, int dest = 0, int weight = 0);
};

struct CompareWeight {
    bool operator()(Edge const& e1, Edge const& e2);
};


#endif //ALGORITHMS_LEARNING_2_EDGE_H
