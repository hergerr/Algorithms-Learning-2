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

    do{
        displayMenuMST();
        cin >> option;
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