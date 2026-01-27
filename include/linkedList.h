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
private:
    Node* head;
    Node* tail;

public:
    linkedList();
    void insert(int);
    void remove(int);
    void print();
    void searching(int);
};
