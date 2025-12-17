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
    }

    char pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    char peek() {
        if (top == nullptr) return '\0';
        return top->data;
    }

    bool isEmpty() { return top == nullptr; }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
