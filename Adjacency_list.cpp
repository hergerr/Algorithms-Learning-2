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


void Adjacency_list::load_from_file(string file_name) {
    ifstream file; //strumien do otwierania pliku
    string str;
    Edge edge;

    clear();

    file.open("../" + file_name);

    if (file.is_open()) {
        file >> this->edges;

        file >> this->nodes;


        //wczytywanie kolejnych krawedzi
        for (int i = 0; i < this->edges; i++) {
            file >> edge.source >> edge.destination >> edge.weight;
            add_edge(edge.source, edge.destination, edge.weight);
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

void Adjacency_list::print() {
    cout << endl;
    for (int i = 0; i < this->graph.size(); i++) {
        cout << "Wierzcholek[" << i << "]: ";
        for (Edge edge : this->graph[i]) {
            cout << edge.source << " -> " << edge.destination << " waga: " << edge.weight << ", ";
        }
        cout << endl;
    }
}

void Adjacency_list::print(vector<list<Edge>> spanning_tree) {
    cout << endl;
    for (int i = 0; i < spanning_tree.size(); i++) {
        cout << "Wierzcholek[" << i << "]: ";
        for (Edge edge : this->spanning_tree[i]) {
            cout << edge.source << " -> " << edge.destination << " waga: " << edge.weight << ", ";
        }
        cout << endl;
    }
}


void Adjacency_list::add_edge(int src, int dest, int weight) {
    this->graph.resize(this->nodes);

    if (this->directed) {
        this->graph[src].push_back(Edge(src, dest, weight));
    } else {
        this->graph[src].push_back(Edge(src, dest, weight));
        this->graph[dest].push_back(Edge(dest, src, weight));
    }
}

void Adjacency_list::prim() {
    bool *visited = new bool[this->graph.size()];       // alokacja tablicy odwiedzynych wierzcholkow
    int node = 0;                                       // poczatkowy wierzcholek
    this->spanning_tree.resize(this->graph.size());     // ustawienie rozmiaru wektora do ilosci wierzcholkow drzewa
    int weight = 0;                                    // waga calego drzewa


    for (int i = 0; i < this->graph.size(); i++) {
        visited[i] = false;
    }


    for (int j = 0; j < this->graph.size(); ++j) {
        Edge minimal_weight_edge;

        auto iterator = this->graph[node].begin();

        if (!visited[node]) {
            do {
                if (!visited[(*iterator).destination]) {    //unikniecie dodania do kolejki odwiedzonych wierzcholkow
                    queue.push(*iterator);
                }
                ++iterator;
            } while (iterator != this->graph[node].end());


            minimal_weight_edge = queue.top();
            queue.pop();

            if (!visited[minimal_weight_edge.destination]) {   //jako ze graf jest niekierowany trzeba dodac 2 krawedzie na raz
                this->spanning_tree[minimal_weight_edge.source].push_back(
                        Edge(minimal_weight_edge.source, minimal_weight_edge.destination, minimal_weight_edge.weight));
                this->spanning_tree[minimal_weight_edge.destination].push_back(
                        Edge(minimal_weight_edge.destination, minimal_weight_edge.source, minimal_weight_edge.weight));

                weight += minimal_weight_edge.weight;
            }

            visited[node] = true;

        } else { // jesli node jest nieodwiedzony to wszystko juz jest w kolejce
            minimal_weight_edge = queue.top();
            queue.pop();

            if (!visited[minimal_weight_edge.destination]) {//zabezpieczenie przed dodanie krawedzi do odwiedzonego wierzcholka
                this->spanning_tree[minimal_weight_edge.source].push_back(
                        Edge(minimal_weight_edge.source, minimal_weight_edge.destination, minimal_weight_edge.weight));
                this->spanning_tree[minimal_weight_edge.destination].push_back(
                        Edge(minimal_weight_edge.destination, minimal_weight_edge.source, minimal_weight_edge.weight));

                weight += minimal_weight_edge.weight;
            }
            j--;
        }
        node = minimal_weight_edge.destination;
    }

    print(spanning_tree);
    cout << endl << "Suma wag: " << weight << endl;

    delete[] visited;
    clear();
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
    queue = priority_queue<Edge, vector<Edge>, CompareWeight>();
}

