#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(char ch) {
        Node* newNode = new Node();
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
        cout << ch << " pushed into the stack.\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! No elements to pop.\n";
            return;
        }
        cout << top->data << " popped from the stack.\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty! No top element.\n";
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    int choice;
    char ch;

    do {
        cout << "\nStack Menu:\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a character to push: ";
            cin >> ch;
            s.push(ch);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
