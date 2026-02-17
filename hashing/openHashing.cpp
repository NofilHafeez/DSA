#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int value) {
        data = value; 
        next = nullptr;
    }
};

class OpenHashing {
public:
    static constexpr int TABLE_SIZE = 10;
    vector<Node*> table;

    OpenHashing() {
        table.resize(TABLE_SIZE, nullptr); 
    }
    
    unsigned int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        unsigned int index = hashFunction(key);
        Node* head = table[index]; 
        Node* prev = nullptr;

        Node* newNode = new Node(key);
        while (head != nullptr && head->data < key) {
            prev = head;
            head = head->next;
        }

        if (prev == nullptr) {
            newNode->next = table[index];
            table[index] = newNode;
        } else {
            prev->next = newNode;
            newNode->next = head;
        }
       

}

     bool search(int key) {
        unsigned int index = hashFunction(key);
        Node* head = table[index];
        
        while (head != nullptr) {
            if (head->data == key) return true;
            head = head->next;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " -> ";
            Node* head = table[i];
            while (head != nullptr) {
                cout << head->data << " -> ";
                head = head->next;
            }
            cout << "nullptr" << endl;
        }
    }
};
