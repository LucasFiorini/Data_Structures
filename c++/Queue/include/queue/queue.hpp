#ifndef QUEUE_H 
#define QUEUE_H 1
#include"node.hpp"

class Queue {
	
	private:
        /**
         * Pointer to the head of the queue
         */
		Node* first;

		/**
		 * Pointer to the tail of the queue
		 */
		Node* last;
		
	public:

        /**
         * Constructor that initialize the attributes
         * @author Lucas Fiorini Braga
         */
		Queue();

		/**
		 * Constructor that initilize attributes and push
		 * an element into the queue
		 * @author Lucas Fiorini Braga
		 * @param character to insert
		 */
		Queue(char d);

		/**
		 * class destructor iterates trough the queue
		 * deleting the nodes
		 * @author Lucas Fiorini Braga
		 */
		~Queue();

		/**
		 * Method to push an element into the queue
		 * inserts into the tail
		 * @author Lucas Fiorini Braga
		 * @param data to insert into the tail
		 * @return void
		 */
		void push(char data);

		/**
		 * Method to remove the head of the queue
		 * @author Lucas Fiorini Braga
		 * @return element from the queue's head
		 */
		char pop();

		/**
		 * Check if structure is empty
		 * @author Lucas Fiorini Braga
		 * @return true if is empty
		 */
		inline bool empty();

		/**
		 * Return the data of the head without
		 * deleting the node
		 * @author Lucas Fiorini Braga
		 * @return data into the node
		 */
		inline char front();

		/**
		 * Return the data of the tail without
		 * deleting the node
		 * @author Lucas Fiorini Braga
		 * @return data into the node
		 */
		inline char back();

		/**
		 * Check the amount of nodes into the structure
		 * @author Lucas Fiorini Braga
		 * @return non negative integer size
		 */
		unsigned int size();

		/**
		 * Iterates trough the structure printing the
		 * content of each node
		 */
		void print();
};

#endif
