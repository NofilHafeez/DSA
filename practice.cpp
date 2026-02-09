#include <iostream>
using namespace std;
// #include "models/searchingAlgo.cpp"
// #include "models/sortingAlgo.cpp"
// #include "include/single/linkedList.h"
// #include "linkedList/double/linkedList.cpp"
// #include "linkedList/circular/linkedList.cpp"
// #include "linkedList/multist/linkedList.cpp"
// #include "heap/heap.cpp"
// #include "linkedList/multist/studentList.cpp"
// #include "linkedList/multist/courseList.cpp"
// #include "include/multist/studentList.h"
// #include "include/multist/courseList.h"
// #include "include/stack/stack.h"
// #include "stack/staticStack.cpp"
// #include "queue/queue.cpp"
// #include "hashing/openHashing.cpp"
// #include "hashing/closeHashing.cpp"
// #include "mergeSort/mergeSort.cpp"
// #include "queue/dynamicQueue.cpp"
#include "quickSort/quickSort.cpp"





int main() {

    // CourseLinkedList courseList;
  
    // courseList.insert("maths");
    // courseList.insert("physics");

    // Course* math = courseList.find("maths");
    // Course* physics = courseList.find("physics");
    
    // math->studentList = new StudentLinkedList();
    // math->studentList->insert("Alice");
    // math->studentList->insert("bob");

    // math->studentList->remove("bob");

    // physics->studentList = new StudentLinkedList();
    
    // courseList.remove("physics");


    // Student* alice = math->studentList->find("Alice");
    // cout << "Found student: " << alice->name << endl;

    // math->studentList->print(); 
    // courseList.print();

    // staticStack stack;
    // stack.push(10);
    // stack.push(20);
    // stack.push(30);

    // stack.pop();
    // stack.peek();
    // stack.print(); 

    // staticQueue queue;
    // queue.enqueue(3);
    // // queue.enqueue(5);
    // // queue.enqueue(10);
    // // queue.dequeue();
    // queue.dequeue();
    // // queue.peek();

    // queue.print();

    // stack.searching(30);


    // closeHashing h;
    // h.insert(3);
    // h.insert(5);
    // h.insert(3);
    // h.print();
    // cout << h.search(3);


    // DynamicQueue dq;
    // dq.enqueue(3);
    // dq.enqueue(4);
    // dq.enqueue(8);
    // dq.enqueue(2);
    // dq.dequeue();
    // dq.dequeue();

    // dq.print();

    vector<int> arr = {5, 2, 4, 1, 3, 40, 100 ,6, 150};

    QuickSort ms;
    ms.sort(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    


    return 0;
}