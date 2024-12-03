#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        printList();
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        printList();
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Linked List: ";
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->data == val) {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << val << " from the list.\n";
            printList();
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << val << " not found in the list.\n";
        } else {
            prev->next = curr->next;
            delete curr;
            cout << "Deleted " << val << " from the list.\n";
            printList();
        }
    }

    int search(int val) {
        int pos = 1;
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1; 
    }

    ~SinglyLinkedList() {
        Node *temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    list.deleteNode(20);
    list.deleteNode(5);
    list.deleteNode(40);

    cout << "Position of 30: " << list.search(30) << endl;
    cout << "Position of 15: " << list.search(15) << endl;

    return 0;
}
