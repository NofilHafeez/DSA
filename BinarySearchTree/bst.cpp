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

    if (root == nullptr)
        return;

    Node* parent = nullptr;
    Node* current = root;

    //  SEARCH NODE
    while (current != nullptr && current->data != value) {
        parent = current;

        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr)
        return; // not found


    //  CASE 1: LEAF NODE
    if (current->left == nullptr && current->right == nullptr) {

        if (current == root)
            root = nullptr;
        else if (parent->left == current)
            parent->left = nullptr;
        else
            parent->right = nullptr;

        delete current;
    }

    //  CASE 2: ONE CHILD
    else if (current->left == nullptr || current->right == nullptr) {

        Node* child;

        if (current->left != nullptr)
            child = current->left;
        else
            child = current->right;

        if (current == root)
            root = child;
        else if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;

        delete current;
    }

    //  CASE 3: TWO CHILDREN
    else {

        Node* parentSucc = current;
        Node* successor = current->right;

        while (successor->left != nullptr) {
            parentSucc = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (parentSucc->left == successor)
            parentSucc->left = successor->right;
        else
            parentSucc->right = successor->right;

        delete successor;
    }
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