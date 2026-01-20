class DoubleCircularNode {
public:
    int data; // data part of the node
    DoubleCircularNode* next; // pointer to the next node
    DoubleCircularNode* prev; // pointer to the previous node
    
    DoubleCircularNode(int value) {
        data = value; // initialize data
        next = nullptr; // set next to nullptr initially
        prev = nullptr; // set prev to nullptr initially
    }
};
