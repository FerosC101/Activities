#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    void push(int val) {
        q2.push(val);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        printStack();
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        q1.pop();
        printStack();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    void printStack() {
        if (q1.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(10);
    stack.push(20);
    stack.top();
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
