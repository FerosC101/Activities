#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    void enqueue(int val) {
        s1.push(val);
        printQueue();
    }

    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        s2.pop();
        printQueue();
    }

    void front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << s2.top() << endl;
    }

    void printQueue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        stack<int> temp1 = s1;
        stack<int> temp2 = s2;
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        while (!temp1.empty()) {
            temp2.push(temp1.top());
            temp1.pop();
        }
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.front();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    return 0;
}
