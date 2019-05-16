#include<iostream>
#include <time.h>
#include"../../include/heap/min_heap.hpp"
using namespace std;

int main() {
    cout << "Inserir valores aleatórios de 1 a 100? (y/n) ";
    char answer;
    //wrong entry type prevention
    if(cin >> answer){
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
    if(!(cin >> numberOfNodes)){
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "ERRO! Infrme novamente com valor inteiro: ";
        cin >> numberOfNodes;
    }
    
    MinHeap *m;

    if(answer == 'y' || answer == 'Y') {
        system("clear");
        m = new MinHeap(numberOfNodes,true);
    } else {
        system("clear");
        m = new MinHeap(numberOfNodes,false);
    }
    //m->print();
    delete m;

}
