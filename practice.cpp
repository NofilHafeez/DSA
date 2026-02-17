#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
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

    

    // OpenHashing h;

    // h.insert(12);
    // h.insert(25);
    // h.insert(7);
    // h.insert(32);
    // h.insert(5);
    // h.insert(20);

    // h.print();

    // cout << "Search 25: " << (h.search(25) ? "Found" : "Not Found") << endl;
    // cout << "Search 15: " << (h.search(15) ? "Found" : "Not Found") << endl;

    
    // int x = 10;
    // cout << &x << endl;
    // int* ptr = &x;
    // cout << *ptr << endl;


    // int b =  2;
    // int* ptr1 = &b;
    // int** ptr2 = &ptr1;
    // cout << ptr2 <<endl; // giving the address of the ptr1 
    // cout << &ptr2 <<endl; // the address of the ptr2

    // int* ptr = new int(5);
    // delete ptr;
    // ptr = nullptr;
    // cout << *ptr;  //  Undefined behavior


    // int* a = new int(5); // return the address of the memory. and returns int* (pointer)
    // int** b = &a;
    // // int** c = &b;

    // // b = a;
    // cout << **b;  //  Undefined behavior

    // int c = 4;
    // int a = 4;
    // a = c;
    // cout <<&a << &c;

    // int y = 5;
    // int& ref = y;
    // cout << ref;

    // ptr->something
    // ptr->something




    // for (int i = 1; i <= 10; i++) 
    // {
    //     if ( i == 1 / 2 + i) {
    //         continue;
    //     }
    //     cout << i;
    // }


    // for (int i = 1; i <= 10; i++) 
    // {
    //     if ( i == 1 / 2 + i && i % 2 == 0) {
    //         cout << "nothing" << endl;
    //     } else {
    //         break;
    //     }
    //     cout << i;
    // }


    // for (int i = 1; i <= 10; i++)
    // {
    //     int j = i + 1; 
    //     int d = i % 4;

    //    if (j == 1) {
    //         break;
    //    } else if (j == 6 || i * 10 == 10) {
    //         cout << "Good" << endl;
    //    } else if ( d < 4  && d != 0) {
    //         continue;
    //    } else {
    //     cout << "nothing" << endl;
    //    }
    // }


    // for (int i = 1; i <= 10; i++)
    // {
    //     int j = i + 1; 
    //     int d = i % 4;

    //    if (j == 2) {
    //         cout << "nice" << endl;
    //    } else if (j == 6 || i * 10 == 10) {
    //         cout << "Good" << endl;
    //    }
    // }

    // if (A)
    // else if (B)
    // else if (C)
    // else


    // if (A) {
    //      }
    // else {
    //     if (B) {
    //     }
    //     else {
    //         if (C) {
    //         }
    //         else {
    //         }
    //     }
    // }

    // for (int i = 1; i < 10 / 2 || i == 1 / 2 + i  + 1; i++)
    // {
    //     cout << i;
    // }
    
    // for (int i = 10; i >= 1; i = i / 2  )
    // {
    //     cout << i << endl;
    // }

    // float b = 3.2;
    // int a = floor(b);
    // cout << a;
    
    // string str = "hello";
    // cout << str.length() << endl;
    // cout << str.substr(0, 3) << endl;
    // cout << str.find("ll") << endl;
    // cout << str.replace(0, 3, "new") << endl;
    // cout << str.size() << endl;


    // reverse(v.begin(), v.end());
    // sort(v.begin(), v.end());
    // max(a,b);
    // count(v.begin(), v.end(), value);
    int c = min(3,6);
    cout << c;
    


    return 0;
}