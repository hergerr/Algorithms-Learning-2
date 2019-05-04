//
// Created by tymek on 25/04/19.
//

#include "Adjacency_list.h"


Adjacency_list::Adjacency_list(bool directed) {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    this->directed = directed;
}

Adjacency_list::~Adjacency_list() {
    clear();
}


void Adjacency_list::load_from_file(string file_name){
    ifstream file; //strumien do otwierania pliku
    string str;
    Edge edge;

    clear();

    file.open("../" + file_name);

    if(file.is_open()) {
        file >> this->edges;

        file >> this->nodes;


        //wczytywanie kolejnych krawedzi
        for(int i = 0; i < this->edges; i++) {
            file >>edge.source >> edge.destination >> edge.weight;

            add_edge(edge.source, edge.destination, edge.weight);
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

void Adjacency_list::print() {
    for(int i = 0; i < this->graph.size(); i++) {
        cout << "Wierzcholek[" << i << "]: ";
        for (Edge edge : this->graph[i]) {
            cout <<edge.source << " -> "<< edge.destination << " waga: " << edge.weight << ", ";
        }
        cout << endl;
    }
}

void Adjacency_list::add_edge(int src, int dest, int weight) {
    this->graph.resize(this->nodes);

    if(this->directed) {
        this->graph[src].push_back(Edge(src, dest, weight));
    } else {
        this->graph[src].push_back(Edge(src, dest, weight));
        this->graph[dest].push_back(Edge(dest, src, weight));
    }
}

void Adjacency_list::clear() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    this->graph.clear();
    this->graph.resize(0);
    this->spanning_tree.clear();
    this->spanning_tree.resize(0);
    priorQueue = priority_queue<Edge, vector<Edge>, CompareWeight>();
}