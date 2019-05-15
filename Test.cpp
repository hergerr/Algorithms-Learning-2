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

    }

    for (int i = 0; i < 5; i++) {
        test_dijkstra(sizes[i], 0.99);
    }

    for (int i = 0; i < 5; i++) {
        test_ford_bellman(sizes[i], 0.99);
    }
}

void Test::test_prim(int nodes, double density) {
    Adjacency_list al(false);
    Adjacency_matrix am(false);

    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        al.prim();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;

        beginning = std::chrono::steady_clock::now();
        am.prim();
        end = std::chrono::steady_clock::now();
        time = end - beginning;
        sum_matrix += time;
    }
    double average_list = (sum_list / tests).count();
    double average_matrix = (sum_matrix / tests).count();


    cout << endl << "Prim " << nodes << endl;
    cout <<" Average List: " << average_list << endl;
    cout <<" Average Matrix: " << average_matrix << endl;

}

void Test::test_kruskal(int nodes, double density) {
    Adjacency_list al(false);
    Adjacency_matrix am(false);

    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        al.kruskal();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;

        beginning = std::chrono::steady_clock::now();
        am.kruskal();
        end = std::chrono::steady_clock::now();
        time = end - beginning;
        sum_matrix += time;
    }
    double average_list = (sum_list / tests).count();
    double average_matrix = (sum_matrix / tests).count();


    cout << endl << "Kruskal " << nodes << endl;
    cout <<" Average List: " << average_list << endl;
    cout <<" Average Matrix: " << average_matrix << endl;

}

void Test::test_dijkstra(int nodes, double density) {
    Adjacency_list al(true);
    Adjacency_matrix am(true);
    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        al.dijkstra();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;

        beginning = std::chrono::steady_clock::now();
        am.dijkstra();
        end = std::chrono::steady_clock::now();
        time = end - beginning;
        sum_matrix += time;
    }
    double average_list = (sum_list / tests).count();
    double average_matrix = (sum_matrix / tests).count();


    cout << endl << "Dijkstra " << nodes << endl;
    cout <<" Average List: " << average_list << endl;
    cout <<" Average Matrix: " << average_matrix << endl;

}

void Test::test_ford_bellman(int nodes, double density) {
    Adjacency_list al(true);
    Adjacency_matrix am(true);
    vector<list<Edge>> g;
    chrono::duration<double> sum_list;
    chrono::duration<double> sum_matrix;

    for (int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now();
        al.ford_bellman();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum_list += time;

        beginning = std::chrono::steady_clock::now();
        am.ford_bellman();
        end = std::chrono::steady_clock::now();
        time = end - beginning;
        sum_matrix += time;
    }
    double average_list = (sum_list / tests).count();
    double average_matrix = (sum_list / tests).count();


    cout << endl << "Ford-Bellman " << nodes << endl;
    cout <<" Average List: " << average_list << endl;
    cout <<" Average Matrix: " << average_matrix << endl;
}
