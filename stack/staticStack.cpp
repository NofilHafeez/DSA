using namespace std;
#include <iostream>

class staticStack
{
// private:
    
public:
    char arr[5];
    int top = 0;
    staticStack() {
        // arr[size];
    }

    void push(char value) {
    arr[top] = value;
    top++;
}

// void peek() {
//     cout << arr[top - 1] << endl;
// }

char peek(int index = 1) {
    // cout << arr[top - index] << endl;
    return arr[top - index];
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

