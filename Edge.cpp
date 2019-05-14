//
// Created by tymek on 04/05/19.
//

#include "Edge.h"

Edge::Edge(int src, int dest, int weight) {
    this->source = src;
    this->destination = dest;
    this->weight = weight;
}

bool CompareWeight::operator()(Edge const &e1, Edge const &e2) {
    return e1.weight > e2.weight;
}
