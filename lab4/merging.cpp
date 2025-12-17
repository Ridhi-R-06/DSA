#include "insacend.h"
#include <cstdio>
#include <cstdlib>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class List {
    Node* head;
public:
    List() : head(nullptr) {}
    Node* gethead() { return head; }
    void insertAscending(int val) {
        Node* newNode = new Node(val);
        if (!head || val < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void merge(Node* a, Node* b) {
        while (a && b) {
            insertAscending((a->data < b->data) ? a->data : b->data);
            (a->data < b->data) ? (a = a->next) : (b = b->next);
        }
        while (a) { insertAscending(a->data); a = a->next; }
        while (b) { insertAscending(b->data); b = b->next; }
    }
    void display() {
        for (Node* temp = head; temp; temp = temp->next) printf("%d->", temp->data);
        printf("NULL\n");
    }
};

int main() {
    List list1, list2, list3;
    int choice, val;
    while (true) {
        printf("\n1. Insert List1\n2. Insert List2\n3. Merge into List3\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value for List1: "); scanf("%d", &val); list1.insertAscending(val); break;
            case 2: printf("Enter value for List2: "); scanf("%d", &val); list2.insertAscending(val); break;
            case 3: list3.merge(list1.gethead(), list2.gethead()); printf("Lists merged into List3.\n"); break;
            case 4: printf("List1: "); list1.display(); printf("List2: "); list2.display(); printf("List3: "); list3.display(); break;
            case 5: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
