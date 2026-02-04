using namespace std;
#include <iostream>

class staticQueue
{
private:
    int arr[5];
    int front = 0;
    int rear = -1;
public:
    staticQueue() {
        // arr[size];
    }

void enqueue(int value) {
    arr[++rear] = value;
}

void peek() {
    cout << arr[front] << endl;
}


void dequeue() {
      if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
   front++;
}

void print() {
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


};

