#include <iostream>
using namespace std;
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
};


class Tree
{
public:
    Node* topRoot = nullptr;
    vector<float> arr;  

    Node* insertBst(Node* root,int value) {
        if (root == nullptr) {
            topRoot = new Node{ value, nullptr, nullptr };
            cout << "root: " <<topRoot->data << endl;
            return topRoot;
        } 
        else if (value < root->data) {
            root->left =  insertBst(root->left, value);
            cout << "left" << endl;
            return root;
        } else {
            root->right = insertBst(root->right, value);
            cout << "right" << endl;
            return root;

        }
        return nullptr;
    };

    void inorder(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    };


    void binary (float value) {
        arr.push_back(value);
    }

    void mirror() {
        // 89 122 12 75  99  68
        // 89 12 122 75  99  68

        // 89 12 122 68  99  75
        // 1  2   3   4  5   6


        
     // 1 2 3 4 5 6 7

        for (int i = 1; i <= arr.size() ; i ++)
        {
            int child1, child2;
            if (i == 1) {
                child1 = 2 * i ;
                child2 = 2 * i + 1;
            }
            if (i > 1) {
                child1 = 2 * i ;
                if (arr.size() % 2 == 1) {
                child2 = 2 * (i + 1)  ;
                    
                } else {
                child2 = 2 * (i + 1)  + 1;

                }
            }
            if (child1 >= arr.size() || child2 >= arr.size()) {
                cout << "child1: " << child1 << " child2: " << child2 << endl;  
                break;
            }
            cout << "child1: " << child1 << " child2: " << child2 << endl;
            swap (arr[child1], arr[child2]);

        }

        for (int i = 1; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        
    }

};


int main () {
    Tree tree = Tree();

    // Node* root = tree.insertBst(tree.topRoot, 10);
    
    // tree.insertBst(root, 20);
    // tree.insertBst(root, 40);
    // tree.insertBst(root, 9);


    // tree.inorder(root);


    // tree.binary(0);
    // tree.binary(1);
    // tree.binary(2);
    // tree.binary(3);
    // tree.binary(4);
    // tree.binary(5);
    // tree.binary(6);
    // tree.binary(7);


    // tree.binary(0);
    // tree.binary(15);
    // tree.binary(20);
    // tree.binary(10);
    // tree.binary(25);
    // tree.binary(8);
    // tree.binary(22);
    tree.mirror();
    // 15 10 20


};

