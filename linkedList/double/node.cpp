class DoubleNode {
public:
    int data; // data part of the node
    DoubleNode* next; // pointer to the next node
    DoubleNode* prev; // pointer to the previous node

    DoubleNode(int value) {
        data = value; // initialize data
        next = nullptr; // set next to nullptr initially
        prev = nullptr; // set prev to nullptr initially
    }
};
