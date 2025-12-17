#include <iostream>
#include <stack>
using namespace std;

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty(); // If stack is empty, it's balanced
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\nMenu:\n1. Check Balance\n2. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                getline(cin, expression);

                if (isBalanced(expression)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are NOT balanced.\n";
                }
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}
