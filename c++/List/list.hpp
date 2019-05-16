#include "node.hpp"
#ifndef LIST
#define LIST

typedef int Data;

class List {
	private:
		Node* first;
		Node* last;
		unsigned int size;
	public:
		List();
		~List();
		void insert(Data d);
		void insertEnd(Data d);
		void insertHead(Data d);
		void insertIntoPos(int pos, Data d);
		void print();
		inline bool empty();
		void remove(unsigned int pos);
		bool search(Data d);
		void printReverse(Node* n, int node);
		void printReverse();
		bool operator==(const List& l);
};



#endif
