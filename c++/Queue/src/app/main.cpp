#include "../../include/util/node.hpp"
#include "../../include/util/queue.hpp"
#include<iostream>

using namespace std;

int main() {
	Queue* q = new Queue();
	char array[] = {'a','s','d','f','g','h','j','k','l','z'};
	for(unsigned int i = 0; i < 10; i++ ){
		q->push(array[i]);
	}

	q->print();
	q->pop();
	q->pop();
	cout << endl<< endl;
	q->print();	


	return 0;
}
