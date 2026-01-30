using namespace std;
#include <iostream>

class staticStack
{
private:
    int arr[5];
    int top = 0;
public:
    staticStack() {
        // arr[size];
    }

    void push(int value) {
    arr[top] = value;
    top++;
}

void peek() {
    cout << arr[top - 1] << endl;
}


void pop() {
    arr[top - 1] = 0;
    top--;
}

void print() {
    for (int i = top - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


};

