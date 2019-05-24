#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H 1

class PriorityQueue {
	private:
		unsigned int size;
		char* array;
	public:
		PriorityQueue(unsigned int size);
		~PriorityQueue();
		void heapfy();
		char pop();

};

#endif
