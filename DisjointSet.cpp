//
// Created by tymek on 08/05/19.
//

#include "DisjointSet.h"
#include <vector>

using namespace std;

#include "DisjointSet.h"

DisjointSet::DisjointSet(int size) {
    this->size = size;

    parent = new int[size+1];
    rank = new int[size+1];

    for(int i = 0; i <= size; i++) {
        rank[i] = 0;
        parent[i] = i;
    }
}

DisjointSet::~DisjointSet() {
    delete [] parent;
    delete [] rank;
    this->size = 0;
}

// znajduje rodzica podanego wierzcholka - sprawdza w jakim zbiorze jest dany element
int DisjointSet::find_parent(int node) {
    if(node != parent[node]) {
        parent[node] = find_parent(parent[node]);
    }
    return parent[node];
}


// laczy 2 zbiory w jeden
void DisjointSet::make_union(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);

    if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
    }

    if (rank[u] == rank[v]) {
        rank[v]++;
    }
}