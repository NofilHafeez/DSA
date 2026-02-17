#include <iostream>
using namespace std;

class closeHashing {
public:
    static constexpr int TABLE_SIZE = 13;
    int table[TABLE_SIZE];
    int flag[TABLE_SIZE];
    int countElements = 0;

    closeHashing() {
        for (int i = 0; i < TABLE_SIZE; i++)
            // table[i] = -1;  
            flag[i] = 0;  
            countElements = 0;
    }

    unsigned int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insertLinear(int key) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (hashFunction(key) + i) % TABLE_SIZE;

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


    double getLoadFactor() {
        return (double)countElements / TABLE_SIZE;
    }


    void insertQuadratic(int key) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (hashFunction(key) + i*i) % TABLE_SIZE;

            if (getLoadFactor() >= 0.5) {
                cout << "Load factor too high, resize table first\n";
                return;
            }

            if (table[probe] == -1) {
                table[probe] = key;
                countElements++;
                cout << "Inserted " << key << " | Load factor: " << getLoadFactor() << endl;
                return;
            } 
            if (table[probe] == key) {
                cout << "Duplicate\n";
                return;
            }
        }
        cout << "Hash table is full\n";
    }

     void flageInsertQuadratic(int key) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (hashFunction(key) + i*i) % TABLE_SIZE;

            // if (getLoadFactor() >= 0.5) {
            //     cout << "Load factor too high, resize table first\n";
            //     return;
            // }'

            cout << key <<endl;

            if (flag[probe] == 0) {
                table[probe] = key;
                flag[probe] = 1;
                countElements++
                return;
            } 
            if (table[probe] == key) {
                cout << "Duplicate\n";
                return;
            }
        }
        cout << "Hash table is full\n";
    }


   bool searchQuadratic(int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int probe = (hashFunction(key) + i*i) % TABLE_SIZE;

        if (flag[probe] == 0) {
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