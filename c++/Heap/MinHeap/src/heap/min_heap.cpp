#include<iostream>
#include<random>
#include "../../include/heap/min_heap.hpp"
using namespace std;

MinHeap::MinHeap(int cap, bool rand) {
    array = new int[cap];
    capacity = cap;
    if (rand){
        mt19937 generator;
        generator.seed((unsigned int)time(0));
        uniform_int_distribution<uint32_t> dice(1,100);
        
        int count = 0;
        for(int i = cap; i > 0; i--) {

            array[count] = dice(generator);
            count++;
        }
    } else {
        int count = 0;
        for(int i = cap; i > 0; i--) {
            array[count] = i;
            count++;
        }
    }

    clock_t start, finish;
	start = clock();
    for(int i = (capacity/2) -1; i >= 0; i--) {
        heapfy(i);
    }
	finish = clock();
   	cout << "Time enlapsed: "<<(finish - start) / (double)CLOCKS_PER_SEC <<"s"<< endl;


}

void MinHeap::insertRandom(int qtd) {
    mt19937 generator;
    generator.seed((unsigned int)time(0));
    uniform_int_distribution<uint32_t> dice(1,100);

    for (int i = 0; i < qtd; ++i) {
        array[i] = dice(generator);
        heapUp(i);
    }
}

MinHeap::MinHeap(int cap) {
	capacity = cap;
	array = new int[cap];
}

void MinHeap::insert(int qtd) {
	for(int i = 0; i < qtd; i++) {
		array[i] = qtd-i;
		heapUp(i);
	}
}


MinHeap::~MinHeap() {
    delete[] array;
    cout << "Structure deleted!" << endl;
}

inline void MinHeap::swap(int x,int y){
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

inline int MinHeap::father(int i) {
	return ((i-1)/2);
}


void MinHeap::heapUp(int i) {
	int fatherIndex = father(i);
	if((array[i] < array[fatherIndex])) {
		swap(i,fatherIndex);
		heapUp(fatherIndex);
	}
}

bool MinHeap::isHeap(){
        for (int i=0; i<=(capacity-2)/2; i++) 
        { 
            if (array[2*i +1] < array[i]) {
                    cout << "Nao e um heap" << endl;
                    return false; 
            }
     
            if (2*i+2 < capacity && array[2*i+2] < array[i]) {
                    cout << "Nao e um heap" << endl;
                    return false; 
            }
        } 
        cout << "E um heap" << endl;
        return true; 
} 


inline int MinHeap::leftSon(int i) {
    return (2*i +1);
} 
inline int MinHeap::rightSon(int i) {
    return (2*i +2);
} 

void MinHeap::heapfy(int i) {
    int left = leftSon(i);
    int right = rightSon(i);
    int smaller = i;
    if((left < capacity) && (array[left] < array[i])){
        smaller = left;
    }
    if((right < capacity) && (array[right] < array[smaller])) {
        smaller = right;
    }

    if (smaller != i) {
        swap(smaller, i);
        heapfy(smaller);
    }
}


void MinHeap::print() {
    for(int i = 0; i < capacity; i++) {
		cout << "Node #"<< i << ": " << array[i] << "\n";
    }
    cout << "\n";
}
