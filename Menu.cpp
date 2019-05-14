//
// Created by tymek on 03/05/19.
//

#include "Menu.h"

void Menu::displayMenuMST() {
    cout << endl;
    cout << "=== Wyznaczanie minimalnego drzewa rozpinającego (MST) ===" << endl;
    cout << "1. Wczytaj z pliku" << endl;
    cout << "2. Wygeneruj graf losowo" << endl;
    cout << "3. Wyswietl listowo i macierzowo na ekranie" << endl;
    cout << "4. Algorytm Prima" << endl;
    cout << "5. Algorytm Kruskala" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje: ";
}

void Menu::displayMenuShortestPath() {
    cout << endl;
    cout << "=== Wyznaczanie najkritszej sciezki w grafie ===" << endl;
    cout << "1. Wczytaj z pliku" << endl;
    cout << "2. Wygeneruj graf losowo" << endl;
    cout << "3. Wyswietl listowo i macierzowo na ekranie" << endl;
    cout << "4. Algorytm Dijkstry" << endl;
    cout << "5. Algorytm Forda-Bellmana" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje: ";

}

void Menu::menuMST() {
    char option;
    string file_name;
    Adjacency_list al(false);
    Adjacency_matrix am(false);
    vector<list<Edge>> gph;
    int node_number;
    double dens;


    do {
        displayMenuMST();
        cin >> option;
        switch (option) {
            case '1': // wczytanie z pliku
                cout << "Podaj nazwe pliku: ";
                cin >> file_name;
                cout << endl;

                al.load_from_file(file_name);
                al.print();
                cout << endl;

                am.load_from_file(file_name);
                am.print();
                break;

            case '2': // wygenerowanie losowego grafu
                cout << "Podaj ilosc wierzcholkow i gestosc grafu: " << endl;
                cin >> node_number >> dens;

                gph = al.generate(node_number, dens);
                al.print();
                cout << endl;
                am.generate(gph);
                am.print();
                break;

            case '3': // wyswietlenie
                cout << endl;
                al.print();
                cout << endl;
                am.print();
                am.print();
                break;

            case '4': // algorytm prima
                cout << endl;
                al.prim();
                cout << endl;
                am.prim();
                break;

            case '5': // algorytm kruskala
                cout << endl;
                am.kruskal();
                cout << endl;
                al.kruskal();
                break;
        }

    } while (option != '0');

}

void Menu::menuShortestPath() {
    Adjacency_list al(true);     // Dla algorytmow SP graf jest skierowany
    Adjacency_matrix am(true);
    vector<list<Edge>> g;
    vector<list<Edge>> gph;

    char opt;
    string fileName;
    int node_number;
    double dens;

    do {
        displayMenuShortestPath();
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': // wczytanie z pliku
                cout << "Podaj nazwe pliku:";
                cin >> fileName;

                al.load_from_file(fileName);
                al.print();

                am.load_from_file(fileName);
                am.print();
                break;

            case '2': // wygenerowanie losowego grafu
                cout << "Podaj ilosc wierzcholkow i gestosc grafu: " << endl;
                cin >> node_number >> dens;

                gph = al.generate(node_number, dens);
                al.print();
                cout << endl;
                am.generate(gph);
                am.print();
                break;

            case '3': // wyswietlenie
                al.print();
                am.print();
                break;

            case '4': // algorytm dijkstry
                al.dijkstra();
                cout << endl;
                am.dijkstra();
                break;

            case '5': // algorytm forda-bellmana
                al.ford_bellman();
                cout << endl;
                am.ford_bellman();
                break;
        }

    } while (opt != '0');
}
