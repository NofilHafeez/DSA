#include <iostream>
using namespace std;
# include <vector>
// #include <algorithm>
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
#include "hashing/openHashing.cpp"
// #include "hashing/closeHashing.cpp"
// #include "mergeSort/mergeSort.cpp"
// #include "queue/dynamicQueue.cpp"
// #include "quickSort/quickSort.cpp"





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
    // h.flageInsertQuadratic(0);
    // h.flageInsertQuadratic(1);
    // h.flageInsertQuadratic(2);
    // h.flageInsertQuadratic(3);
    // h.flageInsertQuadratic(4);
    // h.flageInsertQuadratic(5);
    // h.flageInsertQuadratic(25);
    // h.flageInsertQuadratic(26);
    // h.flageInsertQuadratic(-1);
    // h.flageInsertQuadratic(-17);


    // // h.flageInsertQuadratic(50);
    // // h.flageInsertQuadratic(70);
    // // h.flageInsertQuadratic(100);
    // // h.flageInsertQuadratic(102);
    // // h.flageInsertQuadratic(132);
 
    


    // h.print();
    // cout << h.searchQuadratic(7);


    // DynamicQueue dq;
    // dq.enqueue(3);
    // dq.enqueue(4);
    // dq.enqueue(8);
    // dq.enqueue(2);
    // dq.dequeue();
    // dq.dequeue();

    // dq.print();

    // vector<int> arr = {5, 2, 4, 1, 3, 40, 100 ,6, 150};

    // QuickSort ms;
    // ms.sort(arr);

    // for (int x : arr) {
    //     cout << x << " ";
    // }



    //     string ordered = n;   

    //     for (int i = 0; i < ordered.length(); i++) {
    //         for (int j = i + 1; j < ordered.length(); j++) {

    //             if (ordered[i] > ordered[j]) {
    //                 char temp = ordered[i];
    //                 ordered[i] = ordered[j];
    //                 ordered[j] = temp;
    //             }
    //         }
    //     }

    //     // print with spaces
    // for (int i = 0; i < ordered.length(); i++) {
    //     cout << ordered[i];
    //     if (i != ordered.length() - 1)
    //         cout << " ";
    // }


        // cout << ordered << endl;


        
    //  string n;
    //     cin >> n;

    //     sort(n.begin(), n.end());        // ascending
    //     // sort(n.rbegin(), n.rend());   // descending

    //     cout << n << endl;

    

    OpenHashing h;

    h.insert(12);
    h.insert(25);
    h.insert(7);
    h.insert(32);
    h.insert(5);
    h.insert(20);

    h.print();

    cout << "Search 25: " << (h.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 15: " << (h.search(15) ? "Found" : "Not Found") << endl;


  


    return 0;
}