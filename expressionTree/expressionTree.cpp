#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Expression {

public:

    struct ExpNode {
        char data;
        ExpNode* left;
        ExpNode* right;
    };

    //  CREATE TREE
    ExpNode* createNode(string postFix) {
        stack<ExpNode*> s;
        for (int i = 0; i < postFix.length(); i++) 
        {
            ExpNode* newNode  = new ExpNode{postFix[i], nullptr, nullptr};
            if (isalpha(postFix[i]) || isdigit(postFix[i])) {
                s.push(newNode);
            } else {
                newNode->right = s.top(); s.pop();
                newNode->left = s.top(); s.pop();
                s.push(newNode);
            }   
        }
        return s.top();
    }

    //  INORDER
    void inorder(ExpNode* root) {
        if (root == nullptr) return;

        if (!isalnum(root->data)) cout << "(";

        inorder(root->left);
        cout << root->data;
        inorder(root->right);

        if (!isalnum(root->data)) cout << ")";
    }

    //  PRECEDENCE
    int precedence(char opr) {
        switch (opr) {
            case '!': return 5;
            case '*':
            case '/':
            case '%': return 4;
            case '+':
            case '-': return 3;
            case '<':
            case '>': return 2;
            case '&': return 1;
            case '|': return 0;
            default: return -1;
        }
    }

    //  convert infix to postfix
    string convert(string infix) {
        string postfix = "";
        staticStack s;
        for (int i = 0; i < infix.length(); i++)
        {
            if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '!' || infix[i] == '&' || infix[i] == '<' || infix[i] == '>' || infix[i] == '%' || infix[i] == '|') {
                s.push(infix[i]);
                if (precedence(infix[i]) <= precedence(s.peek(2)) && s.top != 1) {
                    while (s.top >= 1 && precedence(infix[i]) <= precedence(s.peek()))
                    {
                        s.pop();
                        if (precedence(infix[i]) <= precedence(s.peek())) {
                            postfix += s.peek();
                        }
                    }
                    s.push(infix[i]);
                }
            } else {
                postfix += infix[i];
            }
        }
        while (s.top >= 1)
        {
            postfix += s.peek();
            s.pop();
        }
        
        return postfix;
    }

    // convertWithBracket
    string convertWithBrackets(string infix) {
        string postfix = "";
        bool insideBrackets = false;
        int bracAt = 0;
        staticStack s;

        
        for (int i = 0; i < infix.length(); i++)
        {
            if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '!' || infix[i] == '&' || infix[i] == '<' || infix[i] == '>' || infix[i] == '%' || infix[i] == '|' || infix[i] == '(' || infix[i] == ')') {

                if (infix[i] != ')') {
                    s.push(infix[i]);
                    if (infix[i] == '(') {
                        s.pop();
                        bracAt = s.top + 1;
                        insideBrackets = true;
                        continue;
                    }
                } else if (infix[i] == ')') {
                    insideBrackets = false;
                    while (s.top >= bracAt)
                    {
                        postfix += s.peek();
                        s.pop();
                    }
                    continue;
                }

                if (insideBrackets == true) {
                    if (precedence(infix[i]) <= precedence(s.peek(2)) && s.top != bracAt) {
                        while (s.top > bracAt  && precedence(infix[i]) <= precedence(s.peek()))
                        {
                            s.pop();
                            if (precedence(infix[i]) <= precedence(s.peek())) {
                                postfix += s.peek();
                                s.pop();
                            } 
                        }
                        s.push(infix[i]);
                        continue;
                    } else {
                        continue;
                    }
                }

                if (precedence(infix[i]) <= precedence(s.peek(2)) && s.top != 1) {
                    while (s.top >= 1 && precedence(infix[i]) <= precedence(s.peek()))
                    {
                        s.pop();
                        if (precedence(infix[i]) <= precedence(s.peek())) {
                            postfix += s.peek();
                        }
                    }
                    s.push(infix[i]);
                }

            } else {
                postfix += infix[i];
            }
        }

        while (s.top >= 1)
        {
            postfix += s.peek();
            s.pop();
        }
        
        return postfix;
    }

    //  postfix eval
    double postFixEval(string postFix) {
        string newPostfix = "";
        stack<double> s;

        for (int i = 0; i < postFix.length(); i++)
        {
            if (isalpha(postFix[i])) {
                cout << "Enter values: " << endl;
                string input;
                cin >> input;
                if (input.length() > 1) {
                    newPostfix += " " + input + " ";
                } else {
                    newPostfix += input;
                }
            } else {
                newPostfix += postFix[i];
            }
        }

        cout << newPostfix << endl;
        
        for (int i = 0; i < newPostfix.length(); i++)
        {
            double result;

            if (newPostfix[i] == ' ' && isdigit(newPostfix[i + 2])) {
                string doubleStr = "";
                for (int j = i + 1; j < 1000; j++) {
                    if (newPostfix[j] == ' ') break;
                    else if (isdigit(newPostfix[j])) {
                        doubleStr += newPostfix[j];
                    }
                }
                int num = stoi(doubleStr);
                s.push(num);
                i += doubleStr.length() + 1;

            } else if (isdigit(newPostfix[i])) {
                s.push(newPostfix[i] - '0');
            } else {
                double val1 = s.top(); s.pop();
                double val2 = s.top(); s.pop();

                if (newPostfix[i] == '*') s.push(val2 * val1);
                else if (newPostfix[i] == '/') s.push(val2 / val1);
                else if (newPostfix[i] == '+') s.push(val2 + val1);
                else if (newPostfix[i] == '-') s.push(val2 - val1);
            }
        }
        return s.top();
    }
};