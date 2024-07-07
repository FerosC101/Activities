#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        printList();
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        printList();
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Circular Linked List: ";
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList() {
        if (head == nullptr) {
            return;
        }
        Node *temp = head;
        Node *next;
        do {
            next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    return 0;
}
