#pragma once

class Node {
    public:
    int data;
    Node* next;

    Node(int value) {
        data = value; // initialize data
        next = nullptr; // set next to nullptr initially
    }
};


class linkedList {
public:
    Node* head;
    Node* tail;

public:
    linkedList();
    void insert(int);
    void remove(int);
    void print();
    void printRecursionForward(Node*);
    void printRecursionBackward(Node*);
    void searching(int);
};
