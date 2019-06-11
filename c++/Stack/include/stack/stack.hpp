#include "node.hpp"
#ifndef STACK_H
#define STACK_H 1

class Stack {
public:
    Stack();
    Stack(const Stack& s);
    ~Stack();
    void copyToArray(int arr[]);
    unsigned int peek();
    unsigned int pop();
    void push(unsigned int data);
    inline bool empty();
    void print();
private:
    Node* head;
    Node* tail;
    unsigned int size;
};

#endif