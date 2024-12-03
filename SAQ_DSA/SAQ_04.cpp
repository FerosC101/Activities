#include <iostream>
#include <vector>

using namespace std;

class CircularQueue {
private:
    vector<int> queue;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) : front(-1), rear(-1), size(0), capacity(cap) {
        queue.resize(cap);
    }

    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = val;
        size++;
        printQueue();
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        printQueue();
    }

    void printQueue() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue(3);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.dequeue();
    queue.enqueue(40);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    return 0;
}
