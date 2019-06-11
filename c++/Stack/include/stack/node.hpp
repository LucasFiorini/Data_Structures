#ifndef NODE_H
#define NODE_H 1

class Node {
    fiend class Stack;

private:
    Node* next;
    unsigned int data;
public:
    Node(int data);
    ~Node();
};

#endif