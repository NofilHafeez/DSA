#include <iostream>
using namespace std;

class closeHashing {
public:
    static constexpr int TABLE_SIZE = 10;
    int table[TABLE_SIZE];

    closeHashing() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;   // -1 means empty
    }

    unsigned int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        for (int i = 0; i < TABLE_SIZE; i++) {  
            unsigned int probe = (hashFunction(key) + i) % TABLE_SIZE;

            if (table[probe] == -1) {
                table[probe] = key;
                return;
            }

            if (table[probe] == key) {
                cout << "Duplicate\n";
                return;
            }
        }
         cout << "Hash table is full\n";
    }



   bool search(int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int probe = (hashFunction(key) + i) % TABLE_SIZE;

        if (table[probe] == -1) {
            return false;
        }

        if (table[probe] == key) {
            return true;
        }
    }
    return false;
}

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << table[i] << endl;
        } 
    }
};