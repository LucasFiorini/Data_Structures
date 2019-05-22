#include "../../include/BinarySearchTree/tree/binary_search_tree.hpp"
#include "../../include/BinarySearchTree/tree/node.hpp"
#include "../../include/BinarySearchTree/util/type.hpp"
#include <iostream>

int main() {
    TYPE kkk = 10;
    BinarySearchTree *bst = new BinarySearchTree(kkk);
    std::cout << bst->contains(11);
    return 0;
}