struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root = nullptr;

    void insert(int data) {
        if (root == nullptr) {
            root = new Node{data, nullptr, nullptr};
        } else if (root->data < data && root->right == nullptr) {
            root->right = new Node{data, nullptr, nullptr};
        } else if (root->data > data && root->left == nullptr) {
            root->left = new Node{data, nullptr, nullptr};
        } else {
            Node* temp = root;
            while (temp != nullptr)
            {
               if (temp->data < data && temp->right != nullptr) {
                    temp = temp->right;
               } else if (temp->data > data && temp->left != nullptr) {
                    temp = temp->left;
               } else {
                    if (temp->data < data) {
                        temp->right = new Node{data, nullptr, nullptr};
                    } else {
                        temp->left = new Node{data, nullptr, nullptr};
                    }
                    break;
               }
            }
        }  
        }      


    Node* insertSecond(int data, Node* temp = nullptr) {
        if (temp == nullptr) {
            return new Node{data, nullptr, nullptr};
        }
        if (temp->data < data) {
            temp->right = insertSecond(data, temp->right);
        } else {
            temp->left = insertSecond(data, temp->left);
        }
        return temp;
    }


    void deleteNode(int value) {  
        if (root == nullptr) {
            return;
        }
        inorderSearch(root, value);
    }


    void inorderDisplay(Node* root) {
        if (root == nullptr) 
            return;

        cout << root->data << " ";
        inorderDisplay(root->left);
        inorderDisplay(root->right);
    }

    void inorderSearch(Node* root, int data) {
        if (root == nullptr) {
            cout << "Not found" << endl;
            return;
        }

        if (root->data == data) {
            cout << "Found: " << root->data << endl;
            return;
        }

        inorderSearch(root->left, data);
        inorderSearch(root->right, data);     
    }
};