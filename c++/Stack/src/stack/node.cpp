#include "../../include/stack/stack.hpp"
#include "../../include/stack/node.hpp"
#include <iostream>

Node::Node(int data) {
    this->data = data;
    this->next = NULL;
}

Node::~Node() {}

