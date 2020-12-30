#include <iostream>
using namespace std;

const int PRIMO = 37;

int hashFunction(string s, int M){
    int h = 0;

    for(unsigned long i = 0; i < s.length(); i++){
        h = (PRIMO * h + s[i]) % M;
    }
    return h;
}

class noh{
    friend class Hash_table;
private:
    noh* next;
    string data;
    string key;
public:
    noh();
};

noh::noh(){
    data = "";
    key = "";
    next = NULL;
} 

class Hash_table {
private:
    noh** elements;
    int capacity;
public:
    Hash_table(int capacity = 100);
    string recover(string given_key);
    void insert(string given_key, string content);
    void change(string given_key, string content);
    void remove(string given_key);
    void through();
};

Hash_table::Hash_table(int cap) {
    elements = new noh*[cap];
    capacity = cap;

    for(int i = 0; i < cap; i++) {
        elements[i] = NULL;
    }
}

string Hash_table::recover(string given_key) {
    int h;
    h = hashFunction(given_key, capacity);

    if ((elements[h] != NULL) and (elements[h]->key == given_key)) {
        return elements[h]->data;
    } else {
        noh* aux = elements[h];

        while((aux != NULL) and (aux->key != given_key)) {
            aux = aux->next;
        }

        if((aux != NULL) and (aux->key == given_key)) {
            return aux->data;
        } else {
            return "NOT FOUND";
        }
    }
}

void Hash_table::insert(string given_key, string content) {
    int h;
    h = hashFunction(given_key, capacity);

    if (recover(given_key) == "NOT FOUND") {
        if(elements[h] == NULL) {
            elements[h] = new noh;
            elements[h]->data = content;
            elements[h]->key = given_key;
        } else {
            cout << "there was a collision!" << endl;
            noh* aux = elements[h];

            while (aux->next != NULL) {
                aux = aux->next;
            }

            noh* fresh = new noh;
            fresh->data = content;
            fresh->key = given_key;
            aux->next = fresh;
        }
    } else {
        cout << "THERE IS ALREADY THAT ELEMENT AT THE LIST!" << endl;
    }
}


void Hash_table::change(string given_key, string content) {
    int h = hashFunction(given_key, capacity);

    if ((elements[h] != NULL) and (elements[h]->key == given_key)) {
        elements[h]->data = content;
    } else {
        noh* aux = elements[h];

        while ((aux != NULL) and (aux->key != given_key)) {
            aux = aux->next;
        }

        if ((aux != NULL) and (aux->key == given_key)) {
            aux->data = content;
        } else {
            cerr << "IMPOSSIBLE TO CHANGE THE CONTENT!" << endl;
        }
    }
}

void Hash_table::remove(string given_key) {
    int h;
    h = hashFunction(given_key, capacity);

    if((elements[h] != NULL) and (elements[h]->key == given_key)) {

        noh* aux = elements[h];
        elements[h] = elements[h]->next;
        delete aux;
    } else {
        noh* aux = elements[h];
        noh* previous;

        while((aux != NULL) and (aux->key != given_key)) {
            previous = aux;
            aux = aux->next;
        }

        if ((aux != NULL) and (aux->key == given_key)) {
            previous->next = aux->next;
            delete aux;
        } else {
            cerr << "REMOVAL ERROR!!" << endl;
        }
    }
}

void Hash_table::through() {
    noh* aux;
    for(int i = 0; i < capacity; i++) {
        cout << i << ": " << endl;
        aux = elements[i];
        int j = 0;
        while (aux != NULL){
            cout << i << '.' << j << ':' << endl;
            cout << "key: " << aux->key << endl;
            cout << "data: " << aux->data <<endl;
            cout << endl;
            j++;
            aux = aux->next;
        }
    }
}


int main() {
	Hash_table th(10);

	th.insert("hi", "hello");
	th.insert("hill","angerfist");
	th.insert("lucas","unkinkedash");
	th.insert("rio","Riotoro Mouse");
	th.insert("apple","Macbook pro");
	th.insert("metal","Aluminium macbook");
	th.insert("tupac","california love");
	th.insert("28","i m sleepy");
	th.insert("class","data structure class");
	th.insert("beats","beats mixr");

	th.through();
	cout << endl;

	cout << th.recover("hi") << endl;
	cout << th.recover("hill") << endl;
	cout << th.recover("apple") << endl;
	cout << th.recover("beats") << endl;

	th.change("apple", "MacBookPro");
	cout << th.recover("apple") <<endl;

	th.change("tupac", "changes");
	cout << th.recover("tupac");

	th.remove("beats");
	th.remove("metal");
	cout << th.recover("beats") << endl;
	cout << th.recover("metal") << endl;
	th.remove("gym");

	cout << endl;
	th.through();
	cout << endl;
		
	return 0;
}
