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
    bool *visited = new bool[this->nodes];          // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony

    for (int i = 0; i < this->nodes; i++) {
        visited[i] = false;
    }

    this->spanningTree = new int *[this->nodes];    // stworzenie i wypelnienie drzewa rozpinajacego


    for (int k = 0; k < this->nodes; k++) {
        this->spanningTree[k] = new int[this->nodes];
    }

    for (int k = 0; k < this->nodes; k++) {
        for (int l = 0; l < this->nodes; l++) {
            this->spanningTree[k][l] = 0;
        }
    }

    int node = 0;       // numer wierzcholka - zaczynamy od 0
    int weight = 0;     // waga calego drzewa

    for (int i = 0; i < this->nodes; i++) {
        Edge minimal_weight_edge;
        Edge edge;

        if (!visited[node]) {
            for (int j = 0; j < this->nodes; j++) { // dodanie nieodwiedzonych do kolejki priorytetowej
                if (graph[node][j] != 0) { //sprawdzenie czy krawedz istnieje
                    edge.source = node;
                    edge.destination = j;
                    edge.weight = this->graph[node][j];
                    queue.push(edge);
                }
            }

            minimal_weight_edge = queue.top();
            this->queue.pop();

            if (!visited[minimal_weight_edge.destination]) {             // dodanie do drzewa i zwiekszenie wagi
                this->spanningTree[minimal_weight_edge.source][minimal_weight_edge.destination] = minimal_weight_edge.weight;
                this->spanningTree[minimal_weight_edge.destination][minimal_weight_edge.source] = minimal_weight_edge.weight;
                weight += minimal_weight_edge.weight;
            }
            visited[node] = true;     // oznaczenie wierzcholka jako odwiedzony
        } else {    //jesli byl odwiedzony to jego krawedzie juz sa w kolejce
            minimal_weight_edge = queue.top();
            this->queue.pop();

            if (!visited[minimal_weight_edge.destination]) {
                this->spanningTree[minimal_weight_edge.source][minimal_weight_edge.destination] = minimal_weight_edge.weight;
                this->spanningTree[minimal_weight_edge.destination][minimal_weight_edge.source] = minimal_weight_edge.weight;
                weight += minimal_weight_edge.weight;
            }
            i--;    //skoro byl juz odwiedzony to nalezy zmienszyc indeks, inaczej petla by nie przeszla po wszytkich wierzcholkach
        }
        node = minimal_weight_edge.destination;    // przejscie do kolejnego wierzcholka
    }

    print(this->spanningTree);    // wyswietlenie drzewa rozpinajacego

    printf("\nSuma wag: %d\n", weight);    // wyswietlenie wag

    delete[] visited;    //czyszczenie
    clear();
}

void Adjacency_matrix::kruskal() {

    this->spanningTree = new int *[this->nodes];    // stworzenie i wypelnienie drzewa rozpinajacego

    for (int k = 0; k < this->nodes; k++) {
        this->spanningTree[k] = new int[this->nodes];
    }

    for (int k = 0; k < this->nodes; k++) {
        for (int l = 0; l < this->nodes; l++) {
            this->spanningTree[k][l] = 0;
        }
    }

    DisjointSet disjointSet(this->nodes);
    int weight = 0;

    priority_queue<Edge, vector<Edge>, CompareWeight> edges_queue;  //kolejka priorytetowa - typ przechowywany, kontener, funktor

    for (int i = 0; i < this->nodes; ++i) {
        for (int j = 0; j < this->nodes; ++j) {
            if (graph[i][j] != 0)
                edges_queue.push(Edge(i, j, this->graph[i][j]));   //dodanie wszystkich krawedzi
        }
    }

    int loop_index = edges_queue.size();    //zdefiniowanie zmiennej ktora trzyma poczatkowa wielkosc kolejki

    for (int i = 0; i < loop_index; ++i) {
        int src = edges_queue.top().source;
        int dst = edges_queue.top().destination;
        int single_weight = edges_queue.top().weight;

        int set_v1 = disjointSet.find_parent(src);
        int set_v2 = disjointSet.find_parent(dst);
        edges_queue.pop();

        if (set_v1 != set_v2) {
            this->spanningTree[src][dst] = single_weight;   //dodanie do drzewa rozpinajacego
            this->spanningTree[dst][src] = single_weight;
            weight += single_weight;
            disjointSet.make_union(set_v1, set_v2);
        }

    }

    print(this->spanningTree);
    cout << "Waga: " << weight << endl;
    clear();

}

