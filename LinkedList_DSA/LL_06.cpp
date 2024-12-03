#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseKGroup(Node *head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *prev = dummy, *curr = head;
    int count = 0;

    while (curr != nullptr) {
        count++;
        if (count % k == 0) {
            prev = reverse(prev, curr->next);
            curr = prev->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy->next;
}

Node* reverse(Node *prev, Node *next) {
    Node *last = prev->next;
    Node *curr = last->next;

    while (curr != next) {
        last->next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = last->next;
    }

    return last;
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
    head->next->next->next->next = new Node(5);

    int k = 2; 
    Node *reversed = reverseKGroup(head, k);
    printList(reversed);

    return 0;
}
