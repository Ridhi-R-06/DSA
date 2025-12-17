#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert at Beginning
    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // Insert at End
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at Position
    void insertAtPosition(int val, int pos) {
        if (pos <= 1 || !tail) {
            insertBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = tail->next;
        for (int i = 1; i < pos - 1 && temp != tail; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail)
            tail = newNode;
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (!tail) return;

        Node* temp = tail->next;
        if (tail == tail->next) {
            tail = nullptr;
        } else {
            tail->next = temp->next;
        }
        delete temp;
    }

    // Delete from End
    void deleteEnd() {
        if (!tail) return;

        Node* temp = tail->next;
        if (tail == tail->next) {
            delete tail;
            tail = nullptr;
            return;
        }

        while (temp->next != tail)
            temp = temp->next;

        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    // Delete at Position
    void deleteAtPosition(int pos) {
        if (!tail) return;
        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = tail->next;
        Node* prev = nullptr;

        for (int i = 1; i < pos && temp != tail; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == tail) {
            deleteEnd();
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Search an Element
    bool search(int key) {
        if (!tail) return false;
        Node* temp = tail->next;
        do {
            if (temp->data == key)
                return true;
            temp = temp->next;
        } while (temp != tail->next);
        return false;
    }

    // Display the List
    void display() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(HEAD)\n";
    }

    
    ~CircularLinkedList() {
        if (!tail) return;
        Node* temp = tail->next;
        while (temp != tail) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete tail;
    }
};


int main() {
    CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n";
        cout << "5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cll.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                cll.insertEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                cll.insertAtPosition(value, position);
                break;
            case 4:
                cll.deleteBeginning();
                break;
            case 5:
                cll.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                cll.deleteAtPosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (cll.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 8:
                cll.display();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
