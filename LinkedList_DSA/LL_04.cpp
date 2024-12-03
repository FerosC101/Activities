#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeSortedLists(Node *l1, Node *l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != nullptr) tail->next = l1;
    if (l2 != nullptr) tail->next = l2;

    Node *mergedList = dummy->next;
    delete dummy;
    return mergedList;
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
    Node *l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    Node *l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    Node *mergedList = mergeSortedLists(l1, l2);
    printList(mergedList);

    return 0;
}
