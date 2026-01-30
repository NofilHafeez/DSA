#pragma once

class StackNode {
    public:
    int data;
    StackNode* topNode;

    StackNode(int value) {
        data = value; 
        topNode = nullptr; 
    }
};


class Stack {
private:
    StackNode* topNode;

public:
    Stack();
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    void print();
    void searching(int);
};
