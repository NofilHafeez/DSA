#include <iostream>
using namespace std;

class sortingAlgo
{

public:
    void bubbleSort() {
        int arr[10] = {42, 525, 43, 12, 5, 23, 1, 90, 34, 76};
        int greater = 0;
        int lesser = 0;
        bool flag = true;

        for (int i = 0; i < 10; i++)
        {
            flag = false;
            for (int j = 0; j < 9; j++)
            {
               if (arr[j] > arr[j + 1]){ // fix needed the program is looping more extra.
                    flag = true;
                    greater = arr[j];
                    lesser = arr[j + 1];
                    arr[j + 1] = greater;
                    arr[j] = lesser;
                }
                
            }
              if (flag == false){
                cout << "array is sorted at loop: " << i << endl;
                break;
            }
            
        }

        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << endl;
        }    
    }


    void selectionSort() {
        int arr[10] = {42 , 525 , 43 , 12 , 5 , 23 , 1 , 90 , 34 , 76};
        int min = 0;
        int n = 10;
        // int selected = 0;

        for (int i = 0; i < n - 1; i++)
        {
            min = i;
            // cout << "selected index: " << selected << endl;
           for (int j = i + 1; j < n; j++)
           {
                if (arr[j] < arr[min])
                {
                    min = j;
                    cout << "min found at index: " << min << endl;
                }
                
           }
            int temp = arr[i];
            cout << "swapping " << arr[i] << " and " << arr[min] << endl;
            arr[i] = arr[min];
            arr[min] = temp;

           
        }

        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << endl;
        }  
        
    }


    void insertionSort() { //{42, 43, 525, 12}
        int arr[10] = {42 , 525 , 43 , 12 , 5 , 23 , 1 , 90 , 34 , 76};
        int n = 10;
        for (int i = 1; i < n ; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(arr[i] < arr[j]) {
                    // swap arr[i] and arr[j]
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            
        }

         for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << endl;
        } 
        
    }
    
};


