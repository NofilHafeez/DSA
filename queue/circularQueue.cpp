using namespace std;
#include <iostream>

class CircularQueue
{
private:    
    static constexpr int size = 5;
    int arr[size];
    int front = -1;
    int rear = -1;
public:
    CircularQueue() {
        // arr[size];
    }

void enqueue(int value) {
    if ((rear + 1) % size == front) {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % size;
    arr[rear] = value;
}

void peek() {
    cout << arr[front] << endl;
}


void dequeue() {
      if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
   front = (front + 1) % size;
}

void print() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    int i = front;

    while (true) {
        cout << arr[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % size;
    }

    cout << endl;
}



};

