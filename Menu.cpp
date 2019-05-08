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
    cout << "Podaj opcje:";
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
    cout << "Podaj opcje:";

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
                cout << "Podaj nazwe pliku:";
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
                al.print();
                cout << endl;

                am.print();
                break;

            case '4': // algorytm prima
                al.prim();
                am.prim();
                break;

            case '5': // algorytm kruskala
//                al.kruskal();
                am.kruskal();
                break;
        }

    }
    while (option != '0');

}

void Menu::menuShortestPath() {
    char option;


    do{
        displayMenuShortestPath();
        cin >> option;
    }
    while (option != '0');
}