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
    int arr[10] = {3, 3, 3, 52, 131, 134, 400, 400, 700, 700};
    int l = 0;
    int r = 9;
    int mid = 0;

    while (l <= r) {
        mid = (l + r) / 2;

        if (valueToSearch == arr[mid]) {
            int counter = mid + 1;

            while (counter <= 9) {              // scan right
                if (arr[counter] == valueToSearch) {
                    cout << "duplicate value: " << arr[counter] << " found at: " << counter << "\n";
                    counter++;
                } else break;
            }

            counter = mid - 1;
            while (counter >= 0) {              // scan left
                if (arr[counter] == valueToSearch) {
                    cout << "duplicate value: " << arr[counter] << " found at: " << counter << "\n";
                    counter--;
                } else break;
            }

            cout << "value: " << arr[mid] << " found at: " << mid << "\n";
            return "found";  // ← fix for Bug 1
        }

        if (valueToSearch > arr[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;        // cleaner: use else instead of second if
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
            cout << "found at index: " << mid << "\n";

            // scan right
            int counter = mid + 1;
            while (counter <= 9 && arr[counter] == value) {
                cout << "duplicate found at index: " << counter << "\n";
                counter++;
            }

            // scan left
            counter = mid - 1;
            while (counter >= 0 && arr[counter] == value) {
                cout << "duplicate found at index: " << counter << "\n";
                counter--;
            }

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

