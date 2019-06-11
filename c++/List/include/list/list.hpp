#ifndef LIST_H
#define LIST_H 1

#include "node.hpp"


class List {
		
	public:

		List();

		~List();

	       /**
		* This method insert a node at the end 
		* of the list
		* \author Lucas Fiorini
		*
		* \param integer 'd' to be inserted
		* \return void 
		*/
		void insert(int d);
		
	       /**
		* This method insert a node in the end
		*  of the list
		* \author Lucas Fiorini
		* 
		* \param integer 'd' to be inserted
		* \return void 
		*/
		void insertEnd(int d);
				
	       /**
		* This method insert a node at the begining
		* of the list
		* \author Lucas Fiorini
		*
		* \param integer 'd' to be inserted
		* \return void
		*/
		void insertHead(int d);
		
	       /**
		* This method insert a node into a specific 
		* part of the list 
		* \author Lucas Fiorini
		*
		* \param integer 'pos' that represents the index
		* integer 'd' to be inserted
		* \return void
		*/
		void insertIntoPos(int pos, int d);
		
	       /**
		* This method prints the entire list
		* \author Lucas Fiorini
		*
		* \param 
		* \return void
		*/	
		void print();
		
	       /**
		* This method removes an specific given node
		* \author Lucas Fiorini
		*
		* \param unsignd integer 'pos' that represents the 
		* position to be removed [0 to n-1] 
		* \return void
		*/
		void remove(unsigned int pos);
		
	       /**
		* This method is a recursive step of the method
		* printReverse()
		* \author Lucas Fiorini
		*
		* \param pointer to a node and integer to track 
		* nodes index
		* \return void
		*/
		void printReverse(Node* n, int node);
		
	       /**
		* This method prints a list backwords
		* \author Lucas Fiorini
		*
		* \param  
		* \return void
		*/
		void printReverse();
		
	       /**
		* This method searches for a given node
		* \author Lucas Fiorini
		*
		* \param integer 'd' to be searched for
		* \return boolean
		*/
		bool search(int d);
		
	       /**
		* This method overloads the == operator
		* to be able use it to compare the content of two lists
		* \author Lucas Fiorini
		*
		* \param reference to a list
		* \return boolean
		*/
		bool operator==(const List& l);

	       /**
		* This method quickly verifies if the list has is empty
		* \author Lucas Fiorini
		*
		* \param 
		* \return boolean 
		*/
		inline bool empty();
		//copy constructor TODO
		//operator + TODO	
	private:
		//pointer to the first node
		Node* first;
		//pointer to the last node
		Node* last;
		//ammount of nodes currently in the list
		unsigned int size;
};



#endif
