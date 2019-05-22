#ifndef NODE_H
#define NODE_H 1


class Node {
	
	friend class List;
	
	private:
		
		Node* next;
		
		Node* previous;
		
		int data;
	
	public:
		
		Node(int d);
		
		Node();

		~Node();
};


#endif
