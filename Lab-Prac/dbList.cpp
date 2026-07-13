using namespace std;
#include <iostream>

class DoubleNode {
public:
    int data; // data part of the node
    int index;
    DoubleNode* next; // pointer to the next node
    DoubleNode* prev; // pointer to the previous node

    DoubleNode(int value, int index) {
        data = value; // initialize data
        index = index; // initialize index
        next = nullptr; // set next to nullptr initially
        prev = nullptr; // set prev to nullptr initially
    }
};


class DoubleLinkedList
{
public:

   DoubleNode* head;
   DoubleNode* tail;
   int totalIndex = 0;

    DoubleLinkedList() {
        head =  nullptr;
        tail = nullptr;
    }

    void insertAtHead(int value) {
    DoubleNode* newNode = new DoubleNode(value, totalIndex++);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}



  void insertAtTail(int value) {
    DoubleNode* newNode = new DoubleNode(value, totalIndex++);

    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}



    void printForward() {
        DoubleNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void printBackward() {
    DoubleNode* temp = tail;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->prev != nullptr)
            cout << " <- ";
        temp = temp->prev;
    }
    cout << endl;
}

    void remove(int value) {
        if (head == nullptr) return;

        DoubleNode* temp = head;
        while (temp->next != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == head){
            head = temp->next;
            // if (head != nullptr) head->prev = nullptr;
        } else {
            temp->prev->next = temp->next;
        }   

        if (temp == tail) {
            tail = temp->prev;
            // if (tail != nullptr) tail->next = nullptr;
        } else {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
    
     void searching(int value) {
        DoubleNode* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Value " << value << " found in the list.\n";
                return;
            }
            current = current->next;
        }
        cout << "Value " << value << " not found in the list.\n";
    }

    DoubleNode* getNodeAt(int index) {
        DoubleNode* current = head;
        int currentIndex = 0;

        while (current != nullptr) {
            if (currentIndex == index) {
                return current;
            }
            current = current->next;
            currentIndex++;
        }
        return nullptr; // Return nullptr if index is out of bounds
    }


    void swap(DoubleNode* a, DoubleNode* b) {
        if (a == nullptr || b == nullptr) return;

        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }


    void quickSort(DoubleLinkedList& list, int left, int right) {
        if (left > right)
            return;

        int pivot = partition(list, left, right);

        quickSort( list, left, pivot - 1);
        quickSort( list, pivot + 1, right);   

    }

        int partition(DoubleLinkedList& list, int left, int right) {
            DoubleNode* pivotNode = list.getNodeAt(left);
            int i = left;
            int j = right + 1;  
            

            while (i < j) {
                do
                {
                i++;  
                } while ( i <= right && list.getNodeAt(i)->data < pivotNode->data);

                do
                {
                j--;
                } while (list.getNodeAt(j)->data > pivotNode->data);

                if (i < j) {
                    swap(list.getNodeAt(i), list.getNodeAt(j));
                }   
            }

            swap(list.getNodeAt(left), list.getNodeAt(j));
            return j;
        }

        DoubleNode* reverse(DoubleNode* head)
        {
            if (head == nullptr)
                return nullptr;

            DoubleNode* temp = head->next;
            head->next = head->prev;
            head->prev = temp;

            if (head->prev == nullptr)
                return head;

            return reverse(head->prev);
        }


        // 1->2->3->4->null

        // 4->3->null

        // 4->3->2->1->null


        


};


int main () {
    DoubleLinkedList list;
    list.insertAtHead(5);
    list.insertAtHead(3);
    list.insertAtTail(7);
    list.insertAtTail(1);
    list.printForward();

    list.quickSort(list, 0, list.totalIndex - 1);
    list.printForward();
    list.head = list.reverse(list.head);
    list.printForward();



    // return 0;
}

