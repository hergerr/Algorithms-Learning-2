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
    bool *visited = new bool[this->graph.size()]; //alokacja tablicy odwiedzynych wierzcholkow
    int node = 0;
    this->spanning_tree.resize(this->graph.size());     // ustawienie rozmiaru wektora zawierajacego drzewo rozpinajace
    int weights = 0; //waga calego drzewa
    Edge minimal_weight_edge;


    for (int i = 0; i < this->graph.size(); i++) {
        visited[i] = false;
    }


    for (int i = 0; i < this->graph.size(); i++) {


        if (!visited[node]) {                           //jesli wierzcholek wczesniej nie byl odwiedzony to dodaje go do kolejki piorytetowej
            auto iter = this->graph[node].begin();      //poczatek wektora -> begin zwraca iterator

            // dodanie wierzcholka do kolejki piorytetowej
            while (iter != this->graph[node].end()) {       //dopoki iterator nie dojdzie do konca vectora
                if (!visited[node]) {                       //jezeli wierzcholek nie jest odwiedzony
                    queue.push((*iter));                    //dodaj do kolejki to na co wskazuje iterator
                }
                iter++;
            }

            minimal_weight_edge = queue.top();  // sciagniecie wierzcholka o najnizszej wadze

            this->queue.pop();                  // usuniecie tego wierzcholka z kolejki

            if (!visited[minimal_weight_edge.destination]) {         // dodanie do drzewa, zwiekszenie wagi
                this->spanning_tree[node].push_back(
                        Edge(minimal_weight_edge.source, minimal_weight_edge.destination, minimal_weight_edge.weight));

                this->spanning_tree[minimal_weight_edge.destination].push_back(
                        Edge(minimal_weight_edge.destination, minimal_weight_edge.source, minimal_weight_edge.weight));

                weights += minimal_weight_edge.weight;
            }

            visited[node] = true; //wierzcholek odwiedzony
        } else {
            minimal_weight_edge = queue.top();       // sciagniecie wierzcholka o najnizszej wadze
            this->queue.pop();                       // usuniecie tego wierzcholka z kolejki

            // jesli nie byl jeszcze odwiedzony - dodaje go do spanning tree i zwiekszam wage sumaryczna
            if (!visited[minimal_weight_edge.destination]) {
                this->spanning_tree[node].push_back(
                        Edge(minimal_weight_edge.source, minimal_weight_edge.destination, minimal_weight_edge.weight));
                this->spanning_tree[minimal_weight_edge.destination].push_back(
                        Edge(minimal_weight_edge.destination, minimal_weight_edge.source, minimal_weight_edge.weight));
                weights += minimal_weight_edge.weight;
            }
            i--;
        }
        node = minimal_weight_edge.destination;  // przejscie do kolejnego wierzcholka

    }

    print(spanning_tree);     // wyswietlenie drzewa rozpinajacego

    cout << endl << "Waga drzewa: " << weights;     // wyswietlenie wag

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

