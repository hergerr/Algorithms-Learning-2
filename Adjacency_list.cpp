//
// Created by tymek on 25/04/19.
//

#include "Adjacency_list.h"


Adjacency_list::Adjacency_list(bool directed) {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->start_node_SP = 0;
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

        if (directed) {
            file >> this->start_node_SP;
        }


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
    cout << "Reprezentacja listowa - wynikowe MST uzyskane algorytmem Prima" << endl;

    bool *visited = new bool[this->graph.size()];       // alokacja tablicy odwiedzynych wierzcholkow
    int node = 0;                                       // poczatkowy wierzcholek
    int weight = 0;                                    // waga calego drzewa
    priority_queue<Edge, vector<Edge>, CompareWeight> queue;


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
                cout << minimal_weight_edge.source << " -> " << minimal_weight_edge.destination << " Waga: "
                     << minimal_weight_edge.weight << endl;
                weight += minimal_weight_edge.weight;
            }

            visited[node] = true;

        } else { // jesli node jest nieodwiedzony to wszystko juz jest w kolejce
            minimal_weight_edge = queue.top();
            queue.pop();

            if (!visited[minimal_weight_edge.destination]) {//zabezpieczenie przed dodanie krawedzi do odwiedzonego wierzcholka
                cout << minimal_weight_edge.source << " -> " << minimal_weight_edge.destination << " Waga: "
                     << minimal_weight_edge.weight << endl;
                weight += minimal_weight_edge.weight;
            }
            j--;
        }
        node = minimal_weight_edge.destination;
    }

    cout << endl << "Suma wag: " << weight << endl;

    delete[] visited;
    clear();
}

void Adjacency_list::clear() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->start_node_SP = 0;
    this->graph.clear();
    this->graph.resize(0);
}

void Adjacency_list::kruskal() {
    cout << "Reprezentacja listowa - wynikowe MST uzyskane algorytmem Kruskala" << endl;

    DisjointSet disjointSet(this->nodes);
    int weight = 0;

    priority_queue<Edge, vector<Edge>, CompareWeight> edges_queue;  //kolejka priorytetowa - typ przechowywany, kontener, funktor

    for (int i = 0; i < this->graph.size(); i++) {
        for (Edge edge : this->graph[i]) {
            edges_queue.push(edge);   //dodanie wszystkich krawedzi
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
            cout << src << " -> " << dst << " Waga: " << single_weight << endl;
            weight += single_weight;
            disjointSet.make_union(set_v1, set_v2);
        }

    }
    cout << "Waga: " << weight << endl;
}

void Adjacency_list::dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > queue;  //kolejka priorytetowa - typ przechowywany, kontener, funktor


    int node = this->start_node_SP;

    int *distances = new int[this->nodes];      // tutaj przechowywane sa koszta
    int *previous = new int[this->nodes];       // tutaj przechowywani sa poprzednicy
    bool *q_s_sets = new bool[this->nodes];     // tablica mowiaca czy przeszlismy wszystkie wierzcholiki (wtedy sa w zbiorze s)

    for (int i = 0; i < this->nodes; i++) {
        previous[i] = -1;
        distances[i] = MAX;
        q_s_sets[i] = false;    //poczatkowo wszystkie wierzcholki sa w zbiorze q
    }

    distances[node] = 0; //koszt dojscia do siebie samego to 0

    queue.push(make_pair(0, node)); //dodanie do kolejki zerowego kosztu i numeru wierzcholka startowego

    while (!queue.empty()) {
        int u = queue.top().second;     //zdjecie numeru wierzcholka z najnizsza waga
        queue.pop();

        if (q_s_sets[u] == true) continue;  // jesli wierzcholek jest juz w zbiorze s to pomijamy go
        q_s_sets[u] = true;                 // inaczej dodaj go do zbioru s

        auto iterator = graph[u].begin();   // pierwszy sasiad wierzcholka u

        while(iterator != graph[u].end()){
            int number = (*iterator).destination;    //  numer sasiadujego wierzcholka
            int weight = (*iterator).weight;         //  waga sasiadujacego wierzcholka

            if(distances[number] > distances[u] + weight){    //  jesli dotychczasowy dystans jest mniejszy od kosztu dojscia do u + waga krawedzie pomiedzy u i v
                distances[number] = distances[u] + weight;    //  zaktualizuj wartosc dystansu
                previous[number] = u;                    //  dodaj poprzednika
                queue.push(make_pair(distances[number], number)); //  wrzucenie do kolejki zaktualizowany koszt dojscia i samego numeru wierzcholka v
            }
            iterator++;
        }

    }

    for (int j = 0; j < this->nodes; ++j) {
        cout << "Dojscie do wierzchlka " << j << ": " << start_node_SP;
        print_path(previous, j);
        cout << "   Koszt: " << distances[j] << endl;
    }


    delete[] q_s_sets;
    delete[] distances;
    delete[] previous;
    clear();
}

void Adjacency_list::print_path(int *previous, int i) {
    if (previous[i] == -1) return;
    print_path(previous, previous[i]);
    cout << " -> " << i;
}


