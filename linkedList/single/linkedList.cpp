#include "node.cpp"
using namespace std;
#include <iostream>

class linkedList
{
private:
   Node* head;
   Node* tail;

public:
    linkedList() {
        head =  nullptr;
        tail = nullptr;
    }

    void insert(int value) {
    // "new" allocates memory on heap "Node" calls constructor of Node class
    // and returns the address of the newly created object
    // newNode  ---->  [ data | next ]
    //              value   NULL

    Node* newNode = new Node(value); 

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode; // better O(1)
    tail = newNode;

    // Node* current = head;
    // while (current->next != nullptr) {
    //     current = current->next;
    // }
    // current->next = newNode;
 }


    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }


    void remove(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* current = head;
        // 10 != 20
        // current = current->next;
        // 20 != 20
        while (current->next != nullptr && current->next->data != value) { // stops when the node is detected
            current = current->next; //prev node
        }
        if (current->next != nullptr) {
            Node* toDelete = current->next; // node to be deleted
            current->next = current->next->next; // bypass the node
            delete toDelete;
        }
    }
        


};

