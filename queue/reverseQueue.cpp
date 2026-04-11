queue<int> reverse(queue<int> q, int k, int count = 0) {

    if (count == k || q.empty()) {
        return q;
    }

    static stack<int> reversedStack;   
    static queue<int> newQueue;

    count++;

    int frontEle = q.front();
    q.pop();

    reversedStack.push(frontEle);

    q = reverse(q, k, count);   

    if (count == k) {
        while (!reversedStack.empty()) {
            newQueue.push(reversedStack.top());
            reversedStack.pop();
        }

        while (!q.empty()) {
            newQueue.push(q.front());
            q.pop();
        }

        return newQueue;
    }

    return q;
}