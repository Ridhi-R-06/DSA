#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
private:
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() { return top == SIZE - 1; }
    bool isEmpty() { return top == -1; }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << ch << endl;
        } else {
            arr[++top] = ch;
            cout << ch << " pushed into the stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! No elements to pop.\n";
        } else {
            cout << arr[top--] << " popped from the stack.\n";
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
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
