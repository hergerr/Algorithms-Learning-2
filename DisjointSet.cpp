//
// Created by tymek on 08/05/19.
//

#include "DisjointSet.h"
#include <vector>

using namespace std;

#include "DisjointSet.h"

DisjointSet::DisjointSet(int size) {
    this->size = size;

    parent = new int[size];
    rank = new int[size];     //rangi danych elementow

    for(int i = 0; i <= size; i++) {    //na poczotku wszystkie elementy sa w osobnych zbiorach
        rank[i] = 0;
        parent[i] = i;
    }
}

DisjointSet::~DisjointSet() {
//    delete [] parent;
//    delete [] rank;
    this->size = 0;
}

int DisjointSet::find_parent(int node) {// znajduje rodzica podanego wierzcholka - sprawdza w jakim zbiorze jest dany element
    if(node != parent[node]) {
        parent[node] = find_parent(parent[node]);   //jesli element nie jest rodzicem dla samego siebie nastepuje wywolanie rekurencyjne
    }                                               // jedno rekurencyjne przejscie przypisuje wartosc w tablicy parent kazdemu elementowi
    return parent[node];
}


// laczy 2 zbiory w jeden
void DisjointSet::make_union(int u, int v) {//laczy zbiory danych wierzcholkow w jeden
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