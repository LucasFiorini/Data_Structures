#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H 1
#include"element.hpp"
class PriorityQueue {
	private:
		unsigned int size;
		Element* array;
	public:
		PriorityQueue(unsigned int size);
		~PriorityQueue();
		void heapfy();
		char pop();

};

#endif
