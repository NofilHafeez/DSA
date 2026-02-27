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
        
        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            if (current->data == value) {
                Node* parentSucc;
                Node* successor = inorderSuccessor( current, parentSucc);
                // Node* predescessor = inoderPredecessor(current);


                // if (predescessor != nullptr) {
                //     current->data = predescessor->data;
                //     if (parent != nullptr) {
                //         parent->left = nullptr;
                //     }

                //     delete predescessor;
                //     predescessor = nullptr;
                //     break;
                // } else
                 if (successor != nullptr) {
                    Node* temp = current;
                    current->data = successor->data;
                    if (parentSucc->left == successor)
                        parentSucc->left = successor->right;
                    else
                        parentSucc->right = successor->right;

                    delete successor;
                    successor = nullptr;
                    break;
                } 

        } else if (current->data < value) {
                    parent = current;
                    current = current->right;

                    if (current->right == nullptr && current->left == nullptr) {
                        parent->right = nullptr;
                        delete current;
                        current = nullptr;
                        break;
                    }
                } else {
                    parent = current;
                    current = current->left;

                    if (current->right == nullptr && current->left == nullptr) {
                        parent->left = nullptr;
                        delete current;
                        current = nullptr;
                        break;
                    }
                }
            }
}


    void inorderDisplay(Node* root) {
        if (root == nullptr) 
            return;

        cout << root->data << " ";
        inorderDisplay(root->left);
        inorderDisplay(root->right);
    }

   Node* inorderSuccessor(Node* node, Node*& parentSucc) {
    parentSucc = node;
    Node* temp = node->right;

    if (temp == nullptr)
        return nullptr;

    while (temp->left != nullptr) {
        parentSucc = temp;
        temp = temp->left;
    }

    return temp;
}

    Node* inoderPredecessor(Node* node) {
        Node* temp = node->left;
         if (temp == nullptr) {
            return nullptr;
        }
        while (temp != nullptr && temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp;
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