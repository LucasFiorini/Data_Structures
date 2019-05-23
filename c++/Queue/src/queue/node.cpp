#include "../../include/util/node.hpp"
#include "../../include/util/queue.hpp"
#include<iostream>

Node::Node(char d) {
	next = NULL;
	data = d;
}

Node::~Node() {}
