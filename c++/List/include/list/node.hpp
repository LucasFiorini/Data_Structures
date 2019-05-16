#ifndef NODE_H
#define NODE_H 1

typedef int Data;

class Node {
	
	friend class List;
	
	private:
		
		Node* next;
		
		Node* previous;
		
		Data data;
	
	public:
		
		Node(Data d);
		
		Node();

		~Node();
};


#endif
