#ifndef NODE_H 
#define NODE_H 1

class Node {
friend class Queue;
	private:
		Node* next;
		char data;
	public:
		Node(char d);
		~Node();
};



#endif
