//
// Created by tymek on 08/05/19.
//

#include "DisjointSet.h"

DisjointSet::DisjointSet(int size) {
    array = new int[size];
}

DisjointSet::~DisjointSet() {
    delete[] array;
    this->size = 0;
}

int DisjointSet::find(int x) {   //znajduje nazwe zbioru w ktorym jest node
    return array[x];
}


void DisjointSet::make_union(int x, int y) { //laczy zbiory
    int rx, ry, i;
    rx = array[x]; //nazwa zbioru gdzie znajduje sie x
    ry = array[y];

    if(rx != ry)
        for(int i = 0; i < size; ++i)
            if(array[i] == ry) array[i] = rx;
}