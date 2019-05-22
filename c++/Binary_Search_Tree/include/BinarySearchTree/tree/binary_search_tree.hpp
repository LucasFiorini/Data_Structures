#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H 1

#include "node.hpp"
#include "../util/type.hpp"
#include <vector>

class BinarySearchTree {

    public:
        enum STATUS {
            _SUCCESS_,
            _FAILUIRE_
        };
        BinarySearchTree(std::vector<TYPE> *elements);
        BinarySearchTree(TYPE rootElement);
        BinarySearchTree();
        ~BinarySearchTree();
        TYPE getLargestElement();
        TYPE getMinorElement();
        TYPE getRoot();
        TYPE removeElement(unsigned index);
        unsigned getIndex(TYPE element);
        unsigned getLevel(TYPE element);
        unsigned getElementAmount();
        bool contains(TYPE element);
        STATUS addElement(TYPE element);
        STATUS addElement(std::vector<TYPE> *elements);
        STATUS removeElement(TYPE element);
        inline unsigned getLevelAmount();
    
    private:
        Node *root;
        unsigned elementAmount;
        unsigned levelAmount;
        Node* searchNode(TYPE element);
        bool isLeaf(Node *node);
};

#endif