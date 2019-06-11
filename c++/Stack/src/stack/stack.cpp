#include "../../include/stack/stack.hpp"
#include "../../include/stack/node.hpp"
#include <iostream>

using namespace std;



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
        push(aux->data);
        aux = aux->next;
    }
}

void Stack::push(unsigned int data) {
    Node* n = new Node(data);
    if (empty()) {
        head = n;
        tail = n;
    } else {
        n->next = head;
        head = n;
    }
    size++;
}

unsigned int Stack::pop() {
        Node *aux = head;
        head = head->next;
        unsigned int data = aux->data;
        delete aux;
        return data;
}

unsigned int Stack::peek() {
    Node* aux = head;
    return (aux->data);
}

inline bool Stack::empty() {
    return (head == NULL);
}

void Stack::copyToArray(int *arr) {
    Node* aux = head;

    unsigned int i = 0;
    while(aux != NULL) {
        arr[i] = aux->data;
        i++;
        aux = aux->next;
    }
}

void Stack::print() {
    Node* aux = head;
    while (aux != NULL) {
        if (aux->next == NULL) {
            cout << aux->data << endl;
        } else {
            cout << aux->data << " -> ";
        }
        aux = aux->next;
    }
}