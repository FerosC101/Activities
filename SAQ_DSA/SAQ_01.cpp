#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack;

public:
    void push(int val) {
        stack.push_back(val);
        printStack();
    }

    void pop() {
        if (stack.empty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        stack.pop_back();
        printStack();
    }

    void peek() {
        if (stack.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << stack.back() << endl;
    }

    void printStack() {
        if (stack.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int val : stack) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.peek();
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
