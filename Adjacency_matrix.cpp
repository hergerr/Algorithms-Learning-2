//
// Created by tymek on 25/04/19.
//

#include "Adjacency_matrix.h"

Adjacency_matrix::Adjacency_matrix(bool directed) {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->start_node_SP = 0;
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

        if (directed) {
            file >> this->start_node_SP;
        }

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
    this->start_node_SP = 0;

    for (int i = 0; i < this->nodes; i++) {
        delete[] this->graph[i];
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


void Adjacency_matrix::prim() {
    cout << "Reprezentacja macierzowa - wynikowe MST uzyskane algorytmem Prima" << endl;

    bool *visited = new bool[this->nodes];          // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony
    priority_queue <Edge, vector<Edge>, CompareWeight> queue;

    for (int i = 0; i < this->nodes; i++) {
        visited[i] = false;
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
            queue.pop();

            if (!visited[minimal_weight_edge.destination]) {
                cout << minimal_weight_edge.source << " -> " << minimal_weight_edge.destination << "  Waga: "
                     << minimal_weight_edge.weight << endl;
                weight += minimal_weight_edge.weight;
            }
            visited[node] = true;     // oznaczenie wierzcholka jako odwiedzony
        } else {    //jesli byl odwiedzony to jego krawedzie juz sa w kolejce
            minimal_weight_edge = queue.top();
            queue.pop();

            if (!visited[minimal_weight_edge.destination]) {
                cout << minimal_weight_edge.source << " -> " << minimal_weight_edge.destination << "  Waga: "
                     << minimal_weight_edge.weight << endl;
                weight += minimal_weight_edge.weight;
            }
            i--;    //skoro byl juz odwiedzony to nalezy zmienszyc indeks, inaczej petla by nie przeszla po wszytkich wierzcholkach
        }
        node = minimal_weight_edge.destination;    // przejscie do kolejnego wierzcholka
    }


    printf("\nSuma wag: %d\n", weight);    // wyswietlenie wag

    delete[] visited;    //czyszczenie
    clear();
}

void Adjacency_matrix::kruskal() {
    cout << "Reprezentacja macierzowa - wynikowe MST uzyskane algorytmem Kruskala" << endl;

    DisjointSet disjointSet(this->nodes);
    int weight = 0;

    priority_queue <Edge, vector<Edge>, CompareWeight> queue;

    for (int i = 0; i < this->nodes; ++i) {
        for (int j = 0; j < this->nodes; ++j) {
            if (graph[i][j] != 0)
                queue.push(Edge(i, j, this->graph[i][j]));   //dodanie wszystkich krawedzi
        }
    }

    int loop_index = queue.size();    //zdefiniowanie zmiennej ktora trzyma poczatkowa wielkosc kolejki

    for (int i = 0; i < loop_index; ++i) {
        int src = queue.top().source;
        int dst = queue.top().destination;
        int single_weight = queue.top().weight;

        int set_v1 = disjointSet.find_parent(src);
        int set_v2 = disjointSet.find_parent(dst);
        queue.pop();

        if (set_v1 != set_v2) {
            cout << src << " -> " << dst << "  Waga: " << single_weight << endl;
            weight += single_weight;
            disjointSet.make_union(set_v1, set_v2);
        }

    }

    cout << "Waga: " << weight << endl;
    clear();

}

void Adjacency_matrix::dijkstra() {
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > >
                                                                                            queue;  //kolejka priorytetowa - typ przechowywany, kontener, funktor


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


        int iterator = 0; // pierwszy sasiad wierzcholka u

        while (iterator != this->nodes) {
            if (graph[u][iterator] == 0) {
                iterator++;
                continue;
            }

            int number = iterator;    //  numer sasiadujego wierzcholka
            int weight = graph[u][iterator];         //  waga sasiadujacego wierzcholka

            if (distances[number] > distances[u] +
                                    weight) {    //  jesli dotychczasowy dystans jest mniejszy od kosztu dojscia do u + waga krawedzie pomiedzy u i v
                distances[number] = distances[u] + weight;    //  zaktualizuj wartosc dystansu
                previous[number] = u;                    //  dodaj poprzednika
                queue.push(make_pair(distances[number],
                                     number)); //  wrzucenie do kolejki zaktualizowany koszt dojscia i samego numeru wierzcholka v
            }
            iterator++;
        }

    }

    for (int j = 0; j < this->nodes; ++j) {
        cout << "Dojscie do wierzcholka " << j << ": " << start_node_SP;
        print_path(previous, j);
        cout << "   Koszt: " << distances[j] << endl;
    }


    delete[] q_s_sets;
    delete[] distances;
    delete[] previous;
    clear();
}

void Adjacency_matrix::print_path(int *previous, int i) {
    if (previous[i] == -1) return;
    print_path(previous, previous[i]);
    cout << " -> " << i;
}

void Adjacency_matrix::ford_bellman() {
    int node = this->start_node_SP;

    int *distances = new int[this->nodes];      // tutaj przechowywane sa koszta
    int *previous = new int[this->nodes];       // tutaj przechowywani sa poprzednicy

    for (int i = 0; i < this->nodes; i++) {
        previous[i] = -1;
        distances[i] = MAX;
    }

    distances[node] = 0; //koszt dojscia do siebie samego to 0

    for (int i = 1; i < this->nodes; ++i) {        // pętlę główną wykonujemy co najwyżej n - 1 razy
        bool test = true;                           // zmienna przechowuje informację o zmianach
        for (int j = 0; j < this->nodes; ++j) {
            int iterator = 0;
            while (iterator != this->nodes) {      // Przeglądamy listę sąsiadów wierzchołka x
                if (graph[j][iterator] == 0) {
                    iterator++;
                    continue;
                }

                if (distances[iterator] > distances[j] + graph[j][iterator]) { // Sprawdzamy warunek relaksacji
                    test = false;
                    distances[iterator] = distances[j] + graph[j][iterator];
                    previous[iterator] = j;
                }
                iterator++;
            }
        }
        if (test) {
            for (int j = 0; j < this->nodes; ++j) {
                cout << "Dojscie do wierzcholka " << j << ": " << start_node_SP;
                print_path(previous, j);
                cout << "   Koszt: " << distances[j] << endl;
            }

            return;
        }
    }

    for (int j = 0; j < this->nodes; ++j) {
        int iterator = 0;
        while (iterator != this->nodes) {      // Przeglądamy listę sąsiadów wierzchołka x
            if (graph[j][iterator] == 0) {
                iterator++;
                continue;
            }
            if (distances[iterator] > distances[j] + graph[j][iterator]) { // Sprawdzamy warunek relaksacji
                cout << "Ujemny cykl" << endl;
                return;
            }
            iterator++;
        }
    }

    for (int j = 0; j < this->nodes; ++j) {
        cout << "Dojscie do wierzcholka " << j << ": " << start_node_SP;
        print_path(previous, j);
        cout << "   Koszt: " << distances[j] << endl;
    }

    delete[] distances;
    delete[] previous;
    clear();
}

void Adjacency_matrix::generate(vector <list<Edge>> g) {
    clear();

    this->nodes = g.size();

    this->graph = new int *[this->nodes];

    for (int k = 0; k < this->nodes; k++) {
        this->graph[k] = new int[this->nodes];
    }

    for (int k = 0; k < this->nodes; k++) {
        for (int l = 0; l < this->nodes; l++) {
            this->graph[k][l] = 0;
        }
    }

    for (int i = 0; i < g.size(); i++) {    //dodawanie krawedzi z parametru do macierzy
        Edge edge;
        auto iter = g[i].begin();
        while (iter != g[i].end()) {
            edge.source = (*iter).source;
            edge.destination = (*iter).destination;
            edge.weight = (*iter).weight;
            add_edge(edge.source, edge.destination, edge.weight);
            iter++;
        }
    }
}
