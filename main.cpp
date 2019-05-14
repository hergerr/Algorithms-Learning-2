#include <iostream>

#include "Adjacency_list.h"
#include "Adjacency_matrix.h"
#include "Menu.h"
#include "Test.h"

using namespace std;


int main() {
//    Adjacency_matrix *matrix = new Adjacency_matrix("x.txt");
//    matrix->print();

//    Adjacency_list* list = new Adjacency_list("x.txt");
//    list->print();

    Menu menu;
    Test test;

    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1. Minimalne drzewo rozpinajace" << endl;
        cout << "2. Najkrotsza sciezka w grafie" << endl;
        cout << "3. Testy" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Podaj opcje: ";
        cin >> option;
        cout << endl;

        switch (option){
            case '1':
                menu.menuMST();
                break;

            case '2':
                menu.menuShortestPath();
                break;

            case '3':
                test.run_tests();
                break;
        }

    } while (option != '0');



    return 0;
}