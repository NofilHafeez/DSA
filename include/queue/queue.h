#pragma once

class QueueNode {
    public:
    int data;
    QueueNode* next;

    QueueNode(int value) {
        data = value; 
        next = nullptr;
    }
};


class DynamicQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    DynamicQueue();
    void enqueue(int value);
    void dequeue();
    // int top() const;
    // bool isEmpty() const;
    void print();
    // void searching(int);
};



