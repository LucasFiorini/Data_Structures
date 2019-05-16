#include "../../include/list/list.hpp"
#include "../../include/list/node.hpp"
#include <iostream>

Node::Node() {
	next = previous = NULL;
	data = 0; 	
}

Node::~Node() {}

Node::Node(int d) {
	next = previous = NULL;
	data = d;	
}
