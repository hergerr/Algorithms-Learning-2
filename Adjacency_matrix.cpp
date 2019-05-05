//
// Created by tymek on 25/04/19.
//

#include "Adjacency_matrix.h"

Adjacency_matrix::Adjacency_matrix(bool directed) {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    this->directed = directed;
}

Adjacency_matrix::~Adjacency_matrix() {
    clear();
}

void Adjacency_matrix::load_from_file(string file_name) {
    ifstream file; //strumien do otwierania pliku
    string str;
    Edge edge;

    clear();

    file.open("../" + file_name);

    if (file.is_open()) {
        file >> this->edges;
        file >> this->nodes;

        this->graph = new int *[this->nodes];   //tworzenie macierzy sasiedztwa o wymiarach n*n

        for (int k = 0; k < this->nodes; k++) {
            this->graph[k] = new int[this->nodes];
        }

        for (int k = 0; k < this->nodes; k++) { //wypelnienie jej zerami
            for (int l = 0; l < this->nodes; l++) {
                this->graph[k][l] = 0;
            }
        }


        // wczytywanie kolejnych krawedzi i dodanie ich do macirzy
        for (int i = 0; i < this->edges; i++) {
            file >> edge.source >> edge.destination >> edge.weight;
            add_edge(edge.source, edge.destination, edge.weight);
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

void Adjacency_matrix::clear() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    queue = priority_queue<Edge, vector<Edge>, CompareWeight>();

    for (int i = 0; i < this->nodes; i++) {
        delete[] this->graph[i];
    }

    for (int i = 0; i < this->nodes; i++) {
        delete[] this->spanningTree[i];
    }

    if (this->nodes > 0) {
        delete[] this->graph;
        delete[] this->spanningTree;
    }
}

void Adjacency_matrix::add_edge(int src, int dest, int weight) {
    if (this->directed) {
        this->graph[src][dest] = weight;
    } else {
        this->graph[src][dest] = weight;
        this->graph[dest][src] = weight;
    }
}


void Adjacency_matrix::print() {
    cout << endl;
    for (int i = 0; i < this->nodes; ++i) {
        for (int j = 0; j < this->nodes; ++j) {
            cout << this->graph[i][j] << " ";
        }
        cout << endl;
    }
}


void Adjacency_matrix::print(int **graph) {
    cout << endl;

    for (int i = 0; i < this->nodes; ++i) {
        for (int j = 0; j < this->nodes; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void Adjacency_matrix::prim() {
    bool *visited = new bool[this->nodes];     // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony

    for (int i = 0; i < this->nodes; i++) {
        visited[i] = false;
    }

    // stworzenie i wypelnienie drzewa rozpinajacego
    this->spanningTree = new int *[this->nodes];

    for (int k = 0; k < this->nodes; k++) {
        this->spanningTree[k] = new int[this->nodes];
    }

    for (int k = 0; k < this->nodes; k++) {
        for (int l = 0; l < this->nodes; l++) {
            this->spanningTree[k][l] = 0;
        }
    }

    // numer wierzcholka - zaczynamy od 0
    int node = 0;

    // sumaryczna waga spanning tree
    int weight = 0;

    for (int i = 0; i < this->nodes; i++) {
        Edge minEdge;
        Edge edge;

        // jesli wierzcholek wczesniej nie byl odwiedzony to dodaje
        // go do kolejki piorytetowej
        if (!visited[node]) {
            for (int j = 0; j < this->nodes; j++) {
                // dodanie wierzcholka do kolejki piorytetowej
                if (!visited[node] && this->graph[node][j] != MAX) {
                    edge.source = node;
                    edge.destination = j;
                    edge.weight = this->graph[node][j];
                    queue.push(edge);
                }
            }

            // sciagniecie wierzcholka o najnizszej wadze
            minEdge = queue.top();
            // usuniecie tego wierzcholka z kolejki
            this->queue.pop();

            // jesli nie byl jeszcze odwiedzony - dodaje go do spanning tree i zwiekszam wage sumaryczna
            if (!visited[minEdge.destination]) {
                this->spanningTree[minEdge.source][minEdge.destination] = minEdge.weight;
                this->spanningTree[minEdge.destination][minEdge.source] = minEdge.weight;
                weight += minEdge.weight;
            }

            // oznaczenie wierzcholka jako odwiedzony
            visited[node] = true;
        } else {
            // sciagniecie wierzcholka o najnizszej wadze
            minEdge = queue.top();
            // usuniecie tego wierzcholka z kolejki
            this->queue.pop();

            // jesli nie byl jeszcze odwiedzony - dodaje go do spanning tree i zwiekszam wage sumaryczna
            if (!visited[minEdge.destination]) {
                this->spanningTree[minEdge.source][minEdge.destination] = minEdge.weight;
                this->spanningTree[minEdge.destination][minEdge.source] = minEdge.weight;
                weight += minEdge.weight;
            }
            i--;
        }
        // przejscie do kolejnego wierzcholka
        node = minEdge.destination;
    }

    // wyswietlenie drzewa rozpinajacego
    print(this->spanningTree);

    // wyswietlenie wag
    printf("\nSuma wag: %d\n", weight);

    //czyszczenie
    delete[] visited;
    clear();
}

