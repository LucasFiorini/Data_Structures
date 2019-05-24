#include "../../include/list/list.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

List::List() {
	first = last = NULL;
	size = 0;	
}

//list destructor
List::~List() {
	Node* aux = first;
	Node* del;
	while(aux != NULL) {
		del = aux;
		aux = aux->next;
		delete del;
	}
	// clear the list head and tail pointers
	first = last = NULL;
}

//Insert with no especification where, inserts by the end of the list
void List::insert(int d) {
	Node* newNode = new Node(d);
	//if list is empty, than insert the element
	if(empty()) {
		first = newNode;
		last = newNode;
	} else { // insert in the end if is not empty
		newNode->previous = last;
		last->next = newNode;
		last = newNode;
	}
	++size;
}

//Retrun true if the first element is null
inline bool List::empty() {
	return (first == NULL);
}

void List::print() {
	Node* aux = first;
	unsigned short i = 0;
	while(aux != NULL) {
		cout << "Node" << i << " : " << aux->data << endl;
		aux = aux->next;
		i++;
	}
}

void List::printReverse() {
	printReverse(first,0);
}

void List::printReverse(Node* n, int node) {
	if(n->next == NULL) {
		cout << "Node " << node << " : " << n->data <<endl;
	} else {
		printReverse(n->next, node+1);
		cout << "Node " << node << " : " << n->data <<endl;
	}
}

void List::remove(unsigned int position) {
	if(position < size) {
		Node* aux = first;
		unsigned int i = 1;
		if(position == 0) {
			first = first->next;
			delete aux;
		} else {
			Node* remove = first->next;
			while((remove != NULL) and (i < position)) {
				i++;
				aux = remove;
				remove = remove->next;
			}
			if(remove == last){
				last = aux;
				aux->next = NULL;
				delete remove;
			} else {
				aux->next = remove->next;
				remove->next->previous = aux;
				delete remove;
			}
			--size;
		}
    } else {
		cout << "error" << endl;
	}
}

void List::insertEnd(int data) {
	Node* newNode = new Node(data);
	if(empty()) {
		first = newNode;
		last = newNode;
	} else {
		last->next = newNode;
		newNode->previous = last;
		last = newNode;
	}
	++size;
}

void List::insertHead(int data) {
	Node* newNode = new Node(data);
	if(empty()) {
		first = newNode;
		last = newNode;
	} else {
		first->previous = newNode;
		newNode->next = first;
		first = newNode;
	}
	++size;
}

bool List::search(int data) {
	Node* iterator = first;
	while(iterator != NULL)	{
		if(data == iterator->data) {
			return true;
		} else {
			iterator = iterator->next;
		}
	}
	return false;
}

void List::insertIntoPos(int pos, int data) {
	if(pos == 0) {
		Node* newNode = new Node(data);
		newNode->next = first->next;
		first->previous = newNode;
		first = newNode;
		++size;
		return;
	}
	Node* iterator = first;
	int posAux = 0;
	while(pos > posAux){
		iterator = iterator->next;
		posAux++;
	}
	Node* newNode = new Node(data);	
	newNode->previous = iterator->previous;
	newNode->next = iterator;
	iterator->previous->next = newNode;
	iterator->previous = newNode;
	++size;
}

bool List::operator==(const List& l) {
    if (l.size != size) {
        return false;
    } else {
        Node* aux1 = first;
        Node* aux2 = l.first;
        while((aux1 != NULL) and (aux2 != NULL)) {
            if (aux1->data != aux2->data) return false;
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
    }
    return true;
}//TODO


