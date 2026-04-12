#pragma once

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int value) {
        data = value;
        next = nullptr;
    }
};


class Stack {
    
public:
    StackNode* topNode;
    Stack();
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    void print();
    void searching(int);
    void merge(Stack& s1, Stack& s2);

};



