#ifndef NODE_H
#define NODE_H 1

#include "../util/type.hpp"

class Node {

    public:
        Node();
        Node(TYPE data);
        ~Node();
        inline TYPE getElement();
        inline void addElement(TYPE element);
    
    private:
        TYPE data;
        Node *rightChild;
        Node *leftChild;
};

#endif