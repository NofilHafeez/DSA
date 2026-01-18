class Node {
public:
    int data; // data part of the node
    Node* next; // pointer to the next node

    Node(int value) {
        data = value; // initialize data
        next = nullptr; // set next to nullptr initially 
    }
};
