#ifndef QUEUE_H 
#define QUEUE_H 1

#include"node.hpp"

class Queue {
	
	private:

		Node* first;
		Node* last;
		
	public:
	
		Queue();
		Queue(char d);
		~Queue();
		void push(char data);
		char pop();
		inline bool empty();
		inline char front();
		inline char back();
		unsigned int size();
	
		void print();
};

#endif
