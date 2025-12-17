#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Insert at Beginning
    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at End
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at Position
    void insertAtPosition(int val, int pos) {
        if (pos <= 1) {
            insertBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++)
            temp = temp->next;

        if (!temp || !temp->next) {
            insertEnd(val);
            return;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete from Beginning
    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    // Delete from End
    void deleteEnd() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    // Delete at Position
    void deleteAtPosition(int pos) {
        if (!head) return;
        if (pos == 1) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos; i++)
            temp = temp->next;

        if (!temp) return;

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp == tail) tail = temp->prev;
        delete temp;
    }

    // Search an element
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

   
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    DoublyLinkedList dll;
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
                dll.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dll.insertEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                dll.insertAtPosition(value, position);
                break;
            case 4:
                dll.deleteBeginning();
                break;
            case 5:
                dll.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                dll.deleteAtPosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (dll.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 8:
                dll.display();
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
