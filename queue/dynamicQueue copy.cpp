using namespace std;
#include <iostream>
#include "../include/queue/queue.h"


DynamicQueue::DynamicQueue() {
    front = nullptr;
    rear = nullptr;

}
 

void DynamicQueue::enqueue(int value) {
    QueueNode* newNode = new QueueNode(value);

    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// void DynamicQueue::peek() {
//      if (front == nullptr) {
//             cout << "Queue is empty\n";
//             return;
//         }
//         cout << front->data << endl;
// }


void DynamicQueue::dequeue() {
    if ( front == nullptr) {
        printf("Queue is empty\n");
        return;
    }
    QueueNode* temp = front;
    front = front->next;

    if (front == nullptr) 
        rear = nullptr;

    delete temp;
}

void DynamicQueue::print() {
    QueueNode* cur = front;
    while (cur != nullptr) {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "NULL";
}




