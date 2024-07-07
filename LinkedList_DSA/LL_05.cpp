#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

bool detectAndRemoveCycle(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return false; 
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;

    return true;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    bool hasCycle = detectAndRemoveCycle(head);

    if (hasCycle) {
        cout << "Cycle detected and removed.\n";
    } else {
        cout << "No cycle detected.\n";
    }

    printList(head);

    return 0;
}
