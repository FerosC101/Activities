#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> queue;

public:
    void enqueue(int val) {
        queue.push_back(val);
        printQueue();
    }       

    void dequeue() {
        if (queue.empty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        queue.erase(queue.begin());
        printQueue();
    }

    void peek() {
        if (queue.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << queue.front() << endl;
    }

    void printQueue() {
        if (queue.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int val : queue) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.peek();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    return 0;
}
