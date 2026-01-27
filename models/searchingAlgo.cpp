#include <iostream>
using namespace std;

class searchingAlgo
{
public:

    void linearSearch(int valueToSearch) {
        int arr[10] = {1, 3 ,42 ,52 ,131 , 42, 134, 44, 12, 31};
        bool flag = false;
        for (int i = 0; i < 10; i++)
        {
            if (valueToSearch == arr[i]) {
                cout << "value: \n";
                cout << arr[i]<<"\n";
                flag = true;
            }
        }

        if (!flag) {
            cout << "not found";
        }
    }

    string binarySearch(int valueToSearch) {
        int arr[10] = {3, 3 ,3 , 52, 131, 134, 400, 400, 700, 700};
        int l = 0;
        int r = 9;
        int mid = 0;
        // int count = 1;
        
        while (l <=r) {
            mid = (l + r) / 2;
            
            if (valueToSearch == arr[mid]) {

                int counter = mid + 1;

                while (counter <= 9) //goes right from mid
                {
                    int value1 = arr[counter];
                    if (valueToSearch == value1) {
                        cout << "duplicate value: "<< value1 << " found at: "<< counter <<"\n";
                    } 
                    counter++;
                }
                
                counter = mid - 1;
                while (counter >= 0) //goes left from mid
                {
                    int value1 = arr[counter];
                    if (valueToSearch == value1) {
                        cout << "duplicate value: "<< value1 << " found at: "<< counter <<"\n";
                    } 
                    counter--;

                }
                
                cout << "value: "<< arr[mid]<<" found at: "<< mid <<"\n";
                break;
            }
            if (valueToSearch > arr[mid]) {
                    // updates the left side with l = m + 1 and searches to right side
                l = mid + 1;
            } 
            
            if (valueToSearch < arr[mid]) { 
                // updates the right side with r = m - 1 and searches to left side
                r = mid - 1;
            }

        }

        return "not found";


    }


    void recursiveBinarySearch(int arr[], int value, int l = 0, int r = 9) {
        if (l > r) {
            cout << "not found\n";
            return;
        }

        int mid = 0;

        mid = (l + r) / 2;
        if (value == arr[mid]) {
            // l = mid - 1;
            // r = mid + 1;

            // if (value == arr[r]){
            //     cout << "found duplicate at index: " << r << "\n";
            // } else if (value = arr[l]) {
            //     cout << "found duplicate at index: " << l << "\n";
            // }

            cout << "found at index: " << mid << "\n";
            return;
        }
        if (value > arr[mid]) {
            l = mid + 1;
            recursiveBinarySearch(arr, value, l, r);
        } else {
            r = mid - 1;
            recursiveBinarySearch(arr, value, l, r);
        }
            // The recurrence relation for this algorithm is:
            // T(n)=T(n/2)+O(1)
            // Notation is O(log n)
            // Once size becomes 1, recursion ends. 

    }

};

