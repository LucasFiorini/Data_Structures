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

TYPE BinarySearchTree::getLargestElement() {
    Node *tmpNode = this->root;
    Node *fatherNode = NULL;
    while (tmpNode != NULL) {
        fatherNode = tmpNode;
        tmpNode = tmpNode->getRightChild();
    }
    return fatherNode->getElement();
}

TYPE BinarySearchTree::getMinorElement() {
    Node *tmpNode = this->root;
    Node *fatherNode = NULL;
    while (tmpNode != NULL) {
        fatherNode = tmpNode;
        tmpNode = tmpNode->getLeftChild();
    }
    return fatherNode->getElement();
}

BinarySearchTree::STATUS BinarySearchTree::removeElement(TYPE element) {
    if (!contains(element)) return BinarySearchTree::STATUS::_FAILUIRE_;
    Node *targetNode = searchNode(element);
    if (isLeaf(targetNode)) {
        targetNode->~Node();
    } else {
        Node *tmpNode = this->root;
        TYPE currentElement = tmpNode->getElement();
        if (element > currentElement) {
            if (tmpNode->getRightChild()->getElement() == element) {
                //Filho direito dele tem q ser apagado;
            } else if (tmpNode->getLeftChild()->getElement() == element){
                //Filho esquerdo tem q ser apagado;
            } else {
                tmpNode = tmpNode->getRightChild();
            }
        } else {
            if (tmpNode->getLeftChild()->getElement() == element) {
                //filho esquerdo tem q ser apagado
            } else if (tmpNode->getRightChild()->getElement() == element) {
                //filho direito tem q ser apagado
            } else {
                tmpNode = tmpNode->getLeftChild();
            }
        }
    }

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
        TYPE currentElement;

        while (tmpNode != NULL) {
            currentElement = tmpNode->getElement();
            fatherNode = tmpNode;
            if (element == currentElement) return BinarySearchTree::STATUS::_FAILUIRE_;
            tmpNode = (element > currentElement) ? tmpNode->getRightChild() : tmpNode->getLeftChild();
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

bool BinarySearchTree::isLeaf(Node *node) {
    return (
        node->getLeftChild() == NULL && node->getRightChild() == NULL
        );
}