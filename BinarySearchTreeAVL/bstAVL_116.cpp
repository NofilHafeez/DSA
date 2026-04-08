#include <algorithm>
#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

class BST {
public:
    AVLNode* root = nullptr;

    AVLNode* insertSecond(int data, AVLNode* temp = nullptr) {
        if (temp == nullptr)
            return new AVLNode{data, nullptr, nullptr, 1};

        if (temp->data < data)
            temp->right = insertSecond(data, temp->right);
        else
            temp->left = insertSecond(data, temp->left);

        int leftH  = temp->left  ? temp->left->height  : 0;
        int rightH = temp->right ? temp->right->height : 0;
        temp->height = max(leftH, rightH) + 1;

        int bf = leftH - rightH;

        if (bf < -1) {
            int rightLeftH  = temp->right->left  ? temp->right->left->height  : 0;
            int rightRightH = temp->right->right ? temp->right->right->height : 0;
            if (rightRightH >= rightLeftH) {
                cout << "SR rotateLeft on " << temp->data << endl;
                temp = rotateLeft(temp);
            } else {
                cout << "DRL rotateRightLeft on " << temp->data << endl;
                temp = rotateRightLeft(temp);
            }
        }

        if (bf > 1) {
            int leftLeftH  = temp->left->left  ? temp->left->left->height  : 0;
            int leftRightH = temp->left->right ? temp->left->right->height : 0;
            if (leftLeftH >= leftRightH) {
                cout << "SL rotateRight on " << temp->data << endl;
                temp = rotateRight(temp);
            } else {
                cout << "DLR rotateLeftRight on " << temp->data << endl;
                temp = rotateLeftRight(temp);
            }
        }

        return temp;
    }

    AVLNode* rotateLeft(AVLNode* temp) {
        AVLNode* newRoot = temp->right;
        temp->right = newRoot->left;
        newRoot->left = temp;

        int leftH  = temp->left  ? temp->left->height  : 0;
        int rightH = temp->right ? temp->right->height : 0;
        temp->height = max(leftH, rightH) + 1;

        int newLeftH  = newRoot->left  ? newRoot->left->height  : 0;
        int newRightH = newRoot->right ? newRoot->right->height : 0;
        newRoot->height = max(newLeftH, newRightH) + 1;

        cout << "rotateLeft running on " << temp->data << endl;
        return newRoot;
    }

    AVLNode* rotateRight(AVLNode* temp) {
        AVLNode* newRoot = temp->left;
        temp->left = newRoot->right;
        newRoot->right = temp;

        int leftH  = temp->left  ? temp->left->height  : 0;
        int rightH = temp->right ? temp->right->height : 0;
        temp->height = max(leftH, rightH) + 1;

        int newLeftH  = newRoot->left  ? newRoot->left->height  : 0;
        int newRightH = newRoot->right ? newRoot->right->height : 0;
        newRoot->height = max(newLeftH, newRightH) + 1;
        
        cout << "rotateRight running on " << temp->data << endl;
        return newRoot;
    }

    AVLNode* rotateRightLeft(AVLNode* temp) {
        AVLNode* rightChild = temp->right;
        AVLNode* rightLeftChild = rightChild->left;

        rightChild->left = rightLeftChild->right;
        rightLeftChild->right = rightChild;
        temp->right = rightLeftChild;

        int rLeftH  = rightChild->left  ? rightChild->left->height  : 0;
        int rRightH = rightChild->right ? rightChild->right->height : 0;
        rightChild->height = max(rLeftH, rRightH) + 1;

        int rlLeftH  = rightLeftChild->left  ? rightLeftChild->left->height  : 0;
        int rlRightH = rightLeftChild->right ? rightLeftChild->right->height : 0;
        rightLeftChild->height = max(rlLeftH, rlRightH) + 1;

        AVLNode* newRoot = temp->right;
        temp->right = newRoot->left;
        newRoot->left = temp;

        int leftH  = temp->left  ? temp->left->height  : 0;
        int rightH = temp->right ? temp->right->height : 0;
        temp->height = max(leftH, rightH) + 1;

        int newLeftH  = newRoot->left  ? newRoot->left->height  : 0;
        int newRightH = newRoot->right ? newRoot->right->height : 0;
        newRoot->height = max(newLeftH, newRightH) + 1;

        cout << "rotateRightLeft on " << temp->data << endl;
        return newRoot;
    }

    AVLNode* rotateLeftRight(AVLNode* temp) {
        AVLNode* leftChild = temp->left;
        AVLNode* leftRightChild = leftChild->right;

        leftChild->right = leftRightChild->left;
        leftRightChild->left = leftChild;
        temp->left = leftRightChild;

        int rLeftH  = leftChild->left  ? leftChild->left->height  : 0;
        int rRightH = leftChild->right ? leftChild->right->height : 0;
        leftChild->height = max(rLeftH, rRightH) + 1;

        int rlLeftH  = leftRightChild->left  ? leftRightChild->left->height  : 0;
        int rlRightH = leftRightChild->right ? leftRightChild->right->height : 0;
        leftRightChild->height = max(rlLeftH, rlRightH) + 1;

        AVLNode* newRoot = temp->left;
        temp->left = newRoot->right;
        newRoot->right = temp;

        int leftH  = temp->left  ? temp->left->height  : 0;
        int rightH = temp->right ? temp->right->height : 0;
        temp->height = max(leftH, rightH) + 1;

        int newLeftH  = newRoot->left  ? newRoot->left->height  : 0;
        int newRightH = newRoot->right ? newRoot->right->height : 0;
        newRoot->height = max(newLeftH, newRightH) + 1;

        cout << "rotateLeftRight on " << temp->data << endl;
        return newRoot;
    }

    AVLNode* deleteNode(AVLNode* node, int value) {
        if (node == nullptr)
            return nullptr;

        // Search
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Found — perform deletion

            // Case 1: leaf
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: one child
            else if (node->left == nullptr || node->right == nullptr) {
                AVLNode* child = node->left ? node->left : node->right;
                delete node;
                return child;
            }
            // Case 3: two children  replace with in-order successor
            else {
                AVLNode* successor = node->right;
                while (successor->left != nullptr)
                    successor = successor->left;

                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data);
            }
        }

        // Update height
        int leftH  = node->left  ? node->left->height  : 0;
        int rightH = node->right ? node->right->height : 0;
        node->height = max(leftH, rightH) + 1;

        int bf = leftH - rightH;

        // Rebalance right-heavy
        if (bf < -1) {
            int rightLeftH  = node->right->left  ? node->right->left->height  : 0;
            int rightRightH = node->right->right ? node->right->right->height : 0;
            if (rightRightH >= rightLeftH) {
                cout << "SR rotateLeft on " << node->data << endl;
                node = rotateLeft(node);
            } else {
                cout << "DRL rotateRightLeft on " << node->data << endl;
                node = rotateRightLeft(node);
            }
        }

        // Rebalance left-heavy
        if (bf > 1) {
            int leftLeftH  = node->left->left  ? node->left->left->height  : 0;
            int leftRightH = node->left->right ? node->left->right->height : 0;
            if (leftLeftH >= leftRightH) {
                cout << "SL rotateRight on " << node->data << endl;
                node = rotateRight(node);
            } else {
                cout << "DLR rotateLeftRight on " << node->data << endl;
                node = rotateLeftRight(node);
            }
        }

        return node;
    }

    
    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void inorderDisplay(AVLNode* node) {
        if (node == nullptr) return;
        inorderDisplay(node->left);
        cout << node->data << " ";
        inorderDisplay(node->right);
    }

    void preorderDisplay(AVLNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderDisplay(node->left);
        preorderDisplay(node->right);
    }

 
    void inorderSearch(AVLNode* node, int data) {
        if (node == nullptr) {
            cout << "Not found" << endl;
            return;
        }
        if (node->data == data) {
            cout << "Found: " << node->data << endl;
            return;
        }
        if (data < node->data)
            inorderSearch(node->left, data);
        else
            inorderSearch(node->right, data);
    }
};