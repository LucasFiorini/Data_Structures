#include"node.hpp"
#include<iostream>
Node::Node(){
	next = NULL;
	previous = NULL;
	data = 0; 	
}

Node::Node(int d){
	next = NULL;
	previous = NULL;
	data = d;	
}
