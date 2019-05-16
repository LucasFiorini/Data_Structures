#ifndef LIST_H
#define LIST_H 1

#include "node.hpp"

typedef int Data;

class List {
		
	public:

		List();

		~List();
		
		void insert(Data d);
		
		void insertEnd(Data d);
		
		void insertHead(Data d);
		
		void insertIntoPos(int pos, Data d);
		
		void print();
		
		void remove(unsigned int pos);
		
		void printReverse(Node* n, int node);
		
		void printReverse();
		
		bool search(Data d);
		
		bool operator==(const List& l);

		inline bool empty();
	
	private:
		
		Node* first;
		
		Node* last;
		
		unsigned int size;
};



#endif
