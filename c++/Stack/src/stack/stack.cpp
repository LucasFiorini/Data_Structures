#include "../../include/stack/stack.hpp"
#include "../../include/stack/node.hpp"

#include <iostream>

Stack::Stack() {
    head = tail = NULL;
    size = 0;
}

Stack::~Stack() {
    Node* aux = head;
    Node* del;

    while (aux != NULL) {
        del = aux;
        aux = aux->next;
        delete del;
    }

    head = tail = NULL;
}

Stack::Stack(const Stack &s) {
    Node* aux = s.head;

    while (aux != NULL) {
        
    }
}