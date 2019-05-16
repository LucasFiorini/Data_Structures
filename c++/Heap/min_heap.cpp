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

    clock_t t0, t1;
	t0 = clock();
    for(int i = (capacity/2) -1; i >= 0; i--) {
        heapfy(i);
    }
	t1 = clock();
   	cout << "Time enlapsed: "<<(t1 - t0) / (double)CLOCKS_PER_SEC <<"s"<< endl;


}

MinHeap::~MinHeap() {
    delete[] array;
}

inline void MinHeap::swap(int x,int y){
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
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
        cout << "Node #1: " << array[i] << "\n";
    }
    cout << "\n";
}