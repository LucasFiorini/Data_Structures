#include "../../include/BinarySearchTree/tree/binary_search_tree.hpp"
#include "../../include/BinarySearchTree/tree/node.hpp"
#include "../../include/BinarySearchTree/util/type.hpp"
#include <iostream>

int main() {
    TYPE kkk = 10;
    BinarySearchTree *bst = new BinarySearchTree(kkk);
    bst->addElement(25);
    bst->addElement(5);
    bst->addElement(20);
    bst->addElement(23);
    bst->addElement(42);
    std::cout << bst->getLargestElement();
    return 0;
}