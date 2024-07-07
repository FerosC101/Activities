#include <iostream>
#include <limits>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAfter(int after, int data);
    void deleteNode(int data);
    void traverse();

private:
    Node* head;
};

void LinkedList::insertAtBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::deleteNode(int data) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next == nullptr) return;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void LinkedList::insertAfter(int after, int data) {
    Node* temp = head;
    while (temp != nullptr && temp->data != after) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with data " << after << " not found." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::traverse() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}


int main() {
    LinkedList list;
    int choice, data, after;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at After Certain Position\n";
        cout << "4. Delete a node\n";
        cout << "5. Traverse Scott\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid choice, please enter a valid option (1-6): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter node data to insert after: ";
                cin >> after;
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAfter(after, data);
                break;
            case 4:
                cout << "Enter data to delete: ";
                cin >> data;
                list.deleteNode(data);
                break;
            case 5:
                cout << "Linked List: ";
                list.traverse();
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
        }
    } while (true);

    return 0;
}