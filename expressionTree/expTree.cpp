class Node {
    String value;  // stores "3", "+", "*"
    Node left, right;
}

class ExpTree
{
public:
    Node* root = nullptr;
    void insert(Node* root, String value) {
        int tokens = split(value);
        int i = 0;
        Node* temp = root;
        
        while (tokens.length() > i) {
                if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                    temp = new Node(tokens[i]);
                } else {
                    temp.left = new Node(tokens[i]);
                    temp.right = new Node(tokens[i+1]);
                }
        }
        
    }
   
    int[] split (String expression) {
        int arr[expression.length()];
        for (int i = 0; i< expression.length() - 1; i++) {
            arr[i] = (int)expression[i];
        }
        return arr;
    }
};

