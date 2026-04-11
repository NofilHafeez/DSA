#include<stack>
using namespace std;
#include <iostream>

stack<int> rear;
stack<int> front;
stack<int> temp; 


void enqueue(int value) {
   
    if (front.size() == 1) {
    cout << "Enqueued: " << value << endl;

        rear.push(value);
    } else {
         cout << "Enqueued: " << value << endl;
        front.push(value);

    }
}

void dequeue() {
    if (!front.empty()) {
        cout << "Dequeuing: " << front.top() << endl;
        front.pop(); 
        while (rear.size() > 1) { // move all but the last element from rear to temp
        temp.push(rear.top());
        cout << "Moving " << rear.top() << " from rear to temp" << endl;
        rear.pop();
    }
        front.push(rear.top());
        cout << "Moving " << rear.top() << " from rear to front" << endl;
        rear.pop(); 
        while (temp.size() > 0) { // move all elements back from temp to rear
            rear.push(temp.top());
            cout << "Moving " << temp.top() << " from temp back to rear" << endl;
            temp.pop();
        }
    }
}


void display() {
    stack<int> tempFront = front; 
    stack<int> tempRear = rear;  
    stack<int> temprev; 

    cout << "Queue: ";
    while (!tempFront.empty()) {
        cout << tempFront.top() << " ";
        tempFront.pop();
    }

    while (tempRear.size() > 0) { // move all elements from rear to temprev to reverse order
        temprev.push(tempRear.top());
        tempRear.pop();
    }

    while (!temprev.empty()) { //  display elements from temprev and empty it
        cout << temprev.top() << " ";
        temprev.pop();
    }
    
    cout << endl;
}

