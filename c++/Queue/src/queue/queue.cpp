#include "../../include/util/queue.hpp"
#include<iostream>

using namespace std;

Queue::Queue() {
	first = NULL;
	last = NULL;
}

Queue::Queue(char d) {
	first = NULL;
	last = NULL;
	push(d);
}


~Queue::Queue() {
    Node* aux = this.first;
    Node* del;
    while(aux != NULL) {
        del = aux;
        aux = aux->next;
        delete del;
    }

    first = last = NULL;
}


void Queue::push(char d) {
	Node* n = new Node(d);
	if(empty()) {
		first = n;
		last = n;
	} else {
		last->next = n;
		last = n;
	}
}


inline bool Queue::empty() {
	return (first == NULL);
}

char Queue::pop() {
	char data = first->data;
	Node* aux = first;
	first = aux->next;
	delete aux;
	return data;
}

inline char Queue::front() {
	return (first->data);
}

inline char Queue::back() {
	return (last->data);
}

unsigned int Queue::size() {
	Node* aux = first;
	
	unsigned int count = 0;

	while(aux != NULL) {
		aux = aux->next;
		count++;
	}
	return count;
}


void Queue::print() {
	Node* aux = first;

	cout << "Head -> ";
	while(aux != NULL) {
	    if(aux->next == NULL){
            cout << aux->data;
        } else {
            cout << aux->data << " -> ";
        }
		aux = aux->next;
	}
	cout << " <- Tail" << endl;

}

