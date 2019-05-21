#ifndef NODE_H
#define NODE_H 1

#include "../util/type.hpp"

class Node {

    public:
        Node();
        Node(TYPE data);
        ~Node();
        TYPE getElement();
        inline void addElement(TYPE element);
        Node* getRightChild();
        Node* getLeftChild();
        void setRightChild(Node *node);
        void setLeftChild(Node *node);
    
    private:
        TYPE data;
        Node *rightChild;
        Node *leftChild;
};

#endif