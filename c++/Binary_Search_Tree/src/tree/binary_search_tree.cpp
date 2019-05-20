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


TYPE BinarySearchTree::removeElement(unsigned index) {

}

BinarySearchTree::STATUS BinarySearchTree::removeElement(TYPE element) {

}

BinarySearchTree::STATUS BinarySearchTree::addElement(TYPE element) {
    if (this->elementAmount == 0) {
        this->root = new Node(element);
        ++this->elementAmount;
        return BinarySearchTree::STATUS::_SUCCESS_;
    } else {
        Node *tmpNode = this->root;
        while (tmpNode != NULL) {
            if (element > tmpNode->getElement()) {
                tmpNode = tmpNode->rightChild;
            } else {
                tmpNode = tmpNode->leftChild;
            }
        }
    }
    
}

BinarySearchTree::STATUS BinarySearchTree::addElement(std::vector<TYPE> *elements) {

}

inline unsigned BinarySearchTree::getElementAmount() {
    return this->elementAmount;
}

inline unsigned BinarySearchTree::getLevelAmount() {
    return this->levelAmount;
}
