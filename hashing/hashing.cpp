#include <iostream>
#include <vector>
using namespace std;

class hashing {
public:
    static constexpr int TABLE_SIZE = 10;
    vector<int> table[TABLE_SIZE];

    unsigned int hashFunction(int key) {
        v
    }

    void insert(int key) {
        unsigned int index = hashFunction(key);
        for (int val : table[index]) {    
            if (val == key) {
                cout << "duplicate\n";
                return;
            }
        }
        table[index].push_back(key);
    }

    bool search(int key) {
        unsigned int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key)
                return true;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (int val : table[i]) {
                    cout << i << " -> " << val << endl;
            }
        } 
    }
};