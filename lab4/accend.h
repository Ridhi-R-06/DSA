//C++ menu driven program to implement list ADT using Singly linked list
#include <cstdio>
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* gethead() { return head; }

public:
    List() : head(nullptr) {}

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

    void merge(List& other) {
        Node* current = other.gethead();
        while (current) {
            insertAscending(current->data);
            current = current->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
};

int main() {
    List list1, list2;
    int choice, val;
    while (true) {
        printf("\n1. Insert Ascending\n2. Merge\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                list1.insertAscending(val);
                break;
            case 2:
                printf("Enter values for second list (end with -1): ");
                while (true) {
                    scanf("%d", &val);
                    if (val == -1) break;
                    list2.insertAscending(val);
                }
                list1.merge(list2);
                break;
            case 3:
                printf("List: ");
                list1.display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
