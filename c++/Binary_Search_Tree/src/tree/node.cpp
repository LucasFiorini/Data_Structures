#include "../../include/BinarySearchTree/tree/node.hpp"
#include "../../include/BinarySearchTree/util/type.hpp"

Node::Node() {
    
}

Node::Node(TYPE data) {
    this->addElement(data);
}

Node::~Node() {}

inline TYPE Node::getElement() {
    return this->data;
}

inline void Node::addElement(TYPE data) {
    this->data = data;
}