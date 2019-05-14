//
// Created by Tymek on 2019-05-14.
//

#include "Test.h"

void Test::run_tests() {
    int sizes[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        test_prim(sizes[i], 0.25);
    }

    for (int i = 0; i < 5; i++) {
        test_kruskal(sizes[i], 0.25);

    }for (int i = 0; i < 5; i++) {
        test_dijkstra(sizes[i], 0.25);
    }

    for (int i = 0; i < 5; i++) {
        test_ford_bellman(sizes[i], 0.25);
    }
}

void Test::test_prim(int nodes, double density) {
    Adjacency_list al(false);
    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        al.prim();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;
    }
    double average = (sum_list / tests).count();


    cout << endl << "Lista Prim" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    Adjacency_matrix am(false);
    for (int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        am.prim();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_matrix += time;
    }
    average = (sum_matrix / tests).count();

    cout << endl << "Macierz Prim" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    cout << "\n=================================================================" << endl;
}

void Test::test_kruskal(int nodes, double density) {
    Adjacency_list al(false);
    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        al.kruskal();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;
    }
    double average = (sum_list / tests).count();


    cout << endl << "Lista Kruskal" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    Adjacency_matrix am(false);
    for (int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        am.kruskal();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_matrix += time;
    }
    average = (sum_matrix / tests).count();

    cout << endl << "Macierz Kruskal" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    cout << "\n=================================================================" << endl;

}

void Test::test_dijkstra(int nodes, double density) {
    Adjacency_list al(false);
    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        al.dijkstra();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;
    }
    double average = (sum_list / tests).count();


    cout << endl << "Lista Dijkstra" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    Adjacency_matrix am(false);
    for (int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        am.dijkstra();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_matrix += time;
    }
    average = (sum_matrix / tests).count();

    cout << endl << "Macierz Dijkstra" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    cout << "\n=================================================================" << endl;
}

void Test::test_ford_bellman(int nodes, double density) {
    Adjacency_list al(false);
    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        al.ford_bellman();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;
    }
    double average = (sum_list / tests).count();


    cout << endl << "Lista Ford-Bellman" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    Adjacency_matrix am(false);
    for (int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        am.ford_bellman();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_matrix += time;
    }
    average = (sum_matrix / tests).count();

    cout << endl << "Macierz Ford-Bellman" << endl;
    cout << "Nodes: " << nodes << " Density: " << density << " Average: " << average << endl;

    cout << "\n=================================================================" << endl;
}
