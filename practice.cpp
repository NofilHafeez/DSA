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
#include "stack/staticStack.cpp"


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

    staticStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    stack.peek();
    stack.print(); 
    // stack.searching(30);
    





    return 0;
}