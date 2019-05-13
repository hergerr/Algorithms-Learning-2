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
    cout << "=== Wyznaczanie najkrótszej ścieżki w grafie ===" << endl;
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
    int value;
    string file_name;
    Adjacency_list al(false);
    Adjacency_matrix am(false);

    do{
        displayMenuMST();
        cin >> option;
        switch (option){
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
                break;

            case '3': // wyswietlenie
                cout << endl;
                al.print();
                cout << endl;
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
                al.kruskal();
                cout << endl;
                am.kruskal();
                break;
        }

    }
    while (option != '0');

}

void Menu::menuShortestPath() {
    // Dla algorytmow SP graf jest skierowany
    Adjacency_list al(true);
    Adjacency_matrix am(true);
    vector<list<Edge>> g;

    char opt;
    string fileName;
    int index, value;

    do{
        displayMenuShortestPath();
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': // wczytanie z pliku
                cout << "Podaj nazwe pliku:";
                cin >> fileName;

                al.load_from_file(fileName);
                al.print();

                am.load_from_file(fileName);
                am.print();
                break;

            case '2': // wygenerowanie losowego grafu
                al.generate(100, 0.25);
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
