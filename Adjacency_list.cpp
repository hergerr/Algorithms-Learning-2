//
// Created by tymek on 25/04/19.
//

#include "Adjacency_list.h"

Adjacency_list::Adjacency_list(int vertex_number, int edge_number) {
    this->vertex_number = vertex_number;
    this->edge_number = edge_number;

    list = new List_element* [vertex_number];
    for (int j = 0; j < vertex_number; ++j) {
        list[j] = NULL;
    }

    for (int i = 0; i < edge_number; i++) {             // start = wierzcholek, end = polaczenie z niego
        cin >> start >> end;                            // Wierzchołek startowy i końcowy krawędzi
        List_element* temp = new List_element;          // Tworzymy nowy element
        temp->v = end;                                  // Numerujemy go jako end
        temp->next = list[start];                       // Dodajemy go na początek listy A[start]
        list[start] = temp;
    }

}


Adjacency_list::~Adjacency_list() {
    for(int i = 0; i < vertex_number; i++)
    {
        List_element* prev = list[i];
        List_element* current = list[i];
        while(current)
        {
            prev = current;
            current = current->next;
            delete prev;
        }
    }
    delete [] list;
}

void Adjacency_list::print() {
    for (int j = 0; j < vertex_number; ++j) {
        cout << "List[" << j << "]: ";
        List_element *temp  = list[j];
        while(temp != NULL){
            cout << temp->v << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

