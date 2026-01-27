#include <iostream>
using namespace std;
// #include "models/searchingAlgo.cpp"
// #include "models/sortingAlgo.cpp"
#include "include/linkedList.h"
// #include "linkedList/double/linkedList.cpp"
// #include "linkedList/circular/linkedList.cpp"
// #include "linkedList/multist/linkedList.cpp"
#include "heap/heap.cpp"
// #include <GL/freeglut.h>


// Display callback function
// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);   // Clear screen

//     glBegin(GL_TRIANGLES);          // Start drawing
//         glVertex2f(-0.5f, -0.5f);
//         glVertex2f( 0.5f, -0.5f);
//         glVertex2f( 0.0f,  0.5f);
//     glEnd();

//     glFlush();                      // Render
// }



    // struct Node {
    //     int data;
    //     Node* next;
    // };

int main(int argc, char** argv) {

    //  glutInit(&argc, argv);                          // Initialize GLUT
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Display mode
    // glutInitWindowSize(500, 500);                   // Window size
    // glutCreateWindow("FreeGLUT Example");           // Window

    // glutDisplayFunc(display); 
    
    // linkedList list;

    // list.insert(4);
    // list.insert(1);
    // list.insert(1);

    // list.insert(1);

    // list.insert(2);
    // list.insert(2);
    // list.insert(5);
    // list.insert(5);
    // list.insert(3);
    // list.insert(3);
    // list.insert(0);
    // list.insert(0);

    // list.remove(4);

    // list.searching(5);                      // Register display callback

    // glutMainLoop();                                 // Start loop

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

    


    // list.print();

    


    // // list.remove(20);

    // list.print();
    // list.printBackward();
    // sa.binarySearch(400);
    // sa.linearSearch(42);

    //    sortingAlgo sa;
    //    sa.bubbleSort();
        // sa.selectionSort();
        // sa.insertionSort();

    // Heap h({50, 30, 20 , 15, 10, 8, 16});
    Heap h({10, 20, 15, 30 ,40});

    // h.insert(60);
    // h.deleteRoot(60);
    h.print();  
    

    // string a = "apple";
    // string b = a;
    // a = "banna";
    // cout << a << b;

    return 0;
}