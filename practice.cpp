#include <iostream>
using namespace std;
#include "models/searchingAlgo.cpp"
#include "models/sortingAlgo.cpp"
// #include "linkedList/single/linkedList.cpp"
#include "linkedList/double/linkedList.cpp"



    // struct Node {
    //     int data;
    //     Node* next;
    // };

int main() {

    // Node* head = new Node{10, nullptr};
    // head->next = new Node{20, nullptr};
    // head->next->next = new Node{30, nullptr};

    // cout << "Linked List elements: ";
    // Node* current = head;
    // while (current != nullptr) {
    //     cout << current->data << " ";
    //     current = current->next;
    // }
    

    // searchingAlgo sa;
    // int arr[10] = {3, 3 ,3 , 52, 131, 134, 400, 400, 700, 700};
    // sa.recursiveBinarySearch(arr, 400);

    DoubleLinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);


    list.remove(30);

    list.printForward();
    list.printBackward();
    // sa.binarySearch(400);
    // sa.linearSearch(42);

    //    sortingAlgo sa;
    //    sa.bubbleSort();
        // sa.selectionSort();
        // sa.insertionSort();


    



    return 0;
}