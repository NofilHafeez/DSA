#include <stack>
using namespace std;

stack<int> reversed;

stack<int> reverse(stack<int> s) {
    if (s.size() == 0) {
            return reversed;
        }
    int topEle = s.top();
    reversed.push(topEle);
    s.pop();
    reversed = reverse(s);
    return reversed;
}