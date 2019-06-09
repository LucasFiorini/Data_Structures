#include<iostream>
#include <time.h>
#include"../../include/heap/min_heap.hpp"
using namespace std;


int main() {
    cout << "Inserir valores aleatórios? (y/n) ";
    char answer;
    //wrong entry type prevention
    if(cin >> answer) {
        if(answer == 'y' or answer == 'n') {
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cerr << "ERRO! Informe novamente usando os caracteres (y/n) ";
            cin >> answer;
        }

    }
    
    int numberOfNodes;
    
    cout << "Quantos elementos deseja inserir: ";

    //wrong entry type prevention
    if(!(cin >> numberOfNodes)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "ERRO! Infrme novamente com valor inteiro: ";
        cin >> numberOfNodes;
    }
    
    MinHeap *m;

    cout << "Inserir em tempo linear? (y/n) ";
    char answer2;

    if(cin >> answer2) {
        if(answer2 == 'y' or answer2 == 'n') {
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cerr << "ERRO! Informe novamente usando os caracteres (y/n) ";
            cin >> answer2;
        }
    }

    if(answer2 == 'y') {
        if (answer == 'y') {
            m = new MinHeap(numberOfNodes,true);
            cout << "inserindo com valores aleatorios de forma  linear" << endl;
        } else {
            m = new MinHeap(numberOfNodes,false);
            cout << "inserindo com valores sequanciais de forma linear" << endl;
        }
    } else {
        m = new MinHeap(numberOfNodes);
        if (answer == 'y') {
            m->insert(numberOfNodes);
            cout << "inserindo com valores aleatorios de forma nao linear" << endl;
        } else {
            m->insertRandom(numberOfNodes);
            cout << "inserindo com valores sequanciais de forma nao linear" << endl;
        }
    }

    m->isHeap();

	return 0;
}
