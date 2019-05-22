#include "../../include/BinarySearchTree/tree/binary_search_tree.hpp"
#include "../../include/BinarySearchTree/tree/node.hpp"
#include "../../include/BinarySearchTree/util/type.hpp"
#include <vector>
#include <iostream>

BinarySearchTree::BinarySearchTree() {
    this->elementAmount = this->levelAmount = 0;
    this->root = NULL;
}

BinarySearchTree::BinarySearchTree(TYPE rootElement) {
    this->root = new Node(rootElement);
    this->elementAmount = this->levelAmount = 1;
}

BinarySearchTree::BinarySearchTree(std::vector<TYPE> *elements) {
    for (std::vector<TYPE>::iterator it = elements->begin(); it != elements->end(); ++it)
        this->addElement(*it);
}

BinarySearchTree::~BinarySearchTree() {
    
}

TYPE BinarySearchTree::getRoot() {
    return this->root->getElement();
}

TYPE BinarySearchTree::removeElement(unsigned index) {
    
}

BinarySearchTree::STATUS BinarySearchTree::removeElement(TYPE element) {

}

unsigned BinarySearchTree::getIndex(TYPE element) {

}

unsigned BinarySearchTree::getLevel(TYPE element) {

}

bool BinarySearchTree::contains(TYPE element) {
    return (searchNode(element) != NULL);
}

Node* BinarySearchTree::searchNode(TYPE element) {
    Node *tmpNode = this->root;
    TYPE currentElement;
    while (tmpNode != NULL) {
        currentElement = tmpNode->getElement();
        if (element == currentElement) 
            return tmpNode;
        else
            tmpNode = (element > currentElement) ? tmpNode->getRightChild() : tmpNode->getLeftChild();
    }
    return NULL;
}

BinarySearchTree::STATUS BinarySearchTree::addElement(TYPE element) {
    if (this->elementAmount == 0) {
        this->root = new Node(element);
        ++this->elementAmount;
        return BinarySearchTree::STATUS::_SUCCESS_;
    } else {
        
        Node *tmpNode = this->root;
        Node *fatherNode = NULL;

        while (tmpNode != NULL) {
            fatherNode = tmpNode;
            tmpNode = (element > tmpNode->getElement()) ? tmpNode->getRightChild() : tmpNode->getLeftChild();
        }
        if (element > fatherNode->getElement()) {
            fatherNode->setRightChild(new Node(element));
        } else {
            fatherNode->setLeftChild(new Node(element));
        }
        ++this->elementAmount;
        return BinarySearchTree::STATUS::_SUCCESS_;
    }
    
}

BinarySearchTree::STATUS BinarySearchTree::addElement(std::vector<TYPE> *elements) {
    for (std::vector<TYPE>::iterator it = elements->begin(); it != elements->end(); ++it)
        addElement(*it);
    return BinarySearchTree::STATUS::_SUCCESS_;
}

unsigned BinarySearchTree::getElementAmount() {
    return this->elementAmount;
}

inline unsigned BinarySearchTree::getLevelAmount() {
    return this->levelAmount;
}
