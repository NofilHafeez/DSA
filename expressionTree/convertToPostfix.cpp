#include <string>
#include <iostream>
using namespace std;

int precedence(char opr) {
    switch (opr) {
        case '!':
            return 5;   // highest

        case '*':
        case '/':
        case '%':
            return 4;

        case '+':
        case '-':
            return 3;

        case '<':
        case '>':
            return 2;

        case '&':
            return 1;

        case '|':
            return 0;   // lowest

        default:
            return -1;  // not an operator
    }
}

    
string convert(string infix, staticStack s) {
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '!' || infix[i] == '&' || infix[i] == '<' || infix[i] == '>' || infix[i] == '%' || infix[i] == '|') {
            s.push(infix[i]);
            if (precedence(infix[i]) <= precedence(s.peek(2)) && s.top != 1) {
                while (s.top >= 1 && precedence(infix[i]) <= precedence(s.peek()))
                {
                    s.pop(); // remove current opr push
                    if (precedence(infix[i]) <= precedence(s.peek())) {
                        postfix += s.peek(); // add to postfix
                    }
                }
                s.push(infix[i]); // again add current opr
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



string convertWithBrackets(string infix, staticStack s) {
    string postfix = "";
    bool insideBrackets = false;
    int bracAt = 0;
    
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '!' || infix[i] == '&' || infix[i] == '<' || infix[i] == '>' || infix[i] == '%' || infix[i] == '|' || infix[i] == '(' || infix[i] == ')') {


            if (infix[i] != ')') {
                s.push(infix[i]);
                if (infix[i] == '(') {
                    s.pop(); // remove ( from stack
                    bracAt = s.top + 1;
                    insideBrackets = true;
                    continue;
                }
            } else if (infix[i] == ')') {
                insideBrackets = false;
                while (s.top >= bracAt)
                {
                    cout << s.peek() << "last opr"<< endl;
                    postfix += s.peek();
                    s.pop();
                }
                continue;
            }
            // 1 2 3 4
            // + * - +   
            if (insideBrackets == true) {
                if (precedence(infix[i]) <= precedence(s.peek(2)) && s.top != bracAt) {
                        while (s.top > bracAt  && precedence(infix[i]) <= precedence(s.peek()))
                        {
                            s.pop(); // remove current opr push
                            if (precedence(infix[i]) <= precedence(s.peek())) {
                                postfix += s.peek(); // add to postfix
                                s.pop();
                                cout << s.peek() << endl;
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
                    s.pop(); // remove current opr push
                    if (precedence(infix[i]) <= precedence(s.peek())) {
                        postfix += s.peek(); // add to postfix
                    }
                }
                s.push(infix[i]); // again add current opr
            }

        } else {
            postfix += infix[i];
        }
    }

    // add remaining opr in stack to postfix
    while (s.top >= 1)
    {
        postfix += s.peek();
        s.pop();
    }
    
    return postfix;
}