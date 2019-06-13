#include<iostream>
#include <time.h>
#include"../../include/heap/min_heap.hpp"
using namespace std;


char readEntryYN();
int readIntegerEntry();

int main() {

    cout << "Inserir valores aleatórios? (y/n) ";
    char answer = readEntryYN();
    

    cout << "Quantos elementos deseja inserir: ";
    int numberOfNodes = readIntegerEntry();


    cout << "Inserir em tempo linear? (y/n) ";
    char answer2 = readEntryYN();


    MinHeap *m;

    if(answer2 == 'y') {
        if (answer == 'y') {
            system("clear");
            cout << "inserindo com valores aleatorios de forma linear" << endl;
            m = new MinHeap(numberOfNodes,true);
        } else {
            system("clear");
            cout << "inserindo com valores sequanciais decrescentes de forma linear" << endl;
            m = new MinHeap(numberOfNodes,false);
        }
    } else {
        m = new MinHeap(numberOfNodes);
        if (answer == 'y') {
            system("clear");
            cout << "inserindo com valores aleatorios de forma nao linear" << endl;
            m->insert(numberOfNodes);
        } else {
            system("clear");
            cout << "inserindo com valores sequanciais decrescentes de forma nao linear" << endl;
            m->insertRandom(numberOfNodes);
        }
    }

    delete m;
	return 0;
}


//Wrong entry prevention read method
char readEntryYN() {
    char answer;
    if (cin >> answer) {
        if (answer == 'y' or answer == 'n') {
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cerr << "ERRO! Informe novamente usando os caracteres (y/n) ";
            cin >> answer;
        }

    }
    return answer;
}

int readIntegerEntry() {
    int value;
    if(!(cin >> value)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "ERRO! Infrme novamente com valor inteiro: ";
        cin >> value;
    }
    return value;
}