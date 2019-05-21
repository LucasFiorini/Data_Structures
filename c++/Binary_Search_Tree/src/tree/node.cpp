#include "../../include/BinarySearchTree/tree/node.hpp"
#include "../../include/BinarySearchTree/util/type.hpp"
#include <cstddef>

Node::Node() {
    this->rightChild = this->leftChild = NULL;
}

Node::Node(TYPE data) {
    this->addElement(data);
    this->rightChild = this->leftChild = NULL;
}

Node::~Node() {
    this->leftChild = this->rightChild = NULL;
    delete this;
}

TYPE Node::getElement() {
    return this->data;
}

inline void Node::addElement(TYPE data) {
    this->data = data;
}

Node* Node::getRightChild() {
    return this->rightChild;
}

Node* Node::getLeftChild() {
    return this->leftChild;
}

void Node::setLeftChild(Node *node) {
    this->leftChild = node;
}

void Node::setRightChild(Node *node) {
    this->rightChild = node;
}