#include <iostream>
using namespace std;
#include <string>

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

    unsigned int hashFunctionFloat(float key) {
        return static_cast<int>(key * 1000) % TABLE_SIZE;
        // instead of taking floor or ceil which makes the chances of collision higher, we can multiply 
        // the float by a power of 10 to preserve the decimal part and then take modulo with table size.
        // this way we can get a better distribution of hash values for float keys.


        // ex: floor(16.42) % 13 = 3
        // ex: floor(16.32) % 13 = 3 
        // ex: floor(16.12) % 13 = 3 // same leading more collision

        
        // cout <<  static_cast<int>(16.42 * 1000) << endl; // 16420
        // cout <<  static_cast<int>(16.32 * 1000) << endl; // 16320
        // cout <<  static_cast<int>(16.12 * 1000) << endl; // 16120

    }

    unsigned int hashFunctionString(string key) {
        unsigned int hash = 0;

        for(char c : key)
            hash = hash * 31 + c; // hash = c1 × 31^(n−1) + c2 × 31^(n−2) + ...
            // but 31 usually gives better hash distribution. to avoid chances of collision we can use prime number as multiplier
            // like ab -> 'a' * 31^1 + 'b' * 31^0 = 3105
            // and ba ->  'b' * 31^1 + 'a' * 31^0 = 3135
            // 31 is commonly used for string distribution

        return hash % TABLE_SIZE;
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