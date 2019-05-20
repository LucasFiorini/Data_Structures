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
        STATUS addElement(TYPE element);
        STATUS addElement(std::vector<TYPE> *elements);
        STATUS removeElement(TYPE element);
        TYPE removeElement(unsigned index);
        inline unsigned getElementAmount();
        inline unsigned getLevelAmount();
    
    private:
        Node *root;
        unsigned elementAmount;
        unsigned levelAmount;
};

#endif