#include <iostream>
#include <list>
#include <algorithm> 
using namespace std;

class HashTable {
private:
    int size;
    list<int>* table;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) {
        size = s;
        table = new list<int>[size];
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << key << " inserted at index " << index << ".\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key);

        if (it != table[index].end()) {
            table[index].erase(it);
            cout << key << " deleted from index " << index << ".\n";
        } else {
            cout << key << " not found.\n";
        }
    }

    void search(int key) {
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key);

        if (it != table[index].end()) {
            cout << key << " found at index " << index << ".\n";
        } else {
            cout << key << " not found.\n";
        }
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; ++i) {
            cout << i << " --> ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL\n";
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    int size, choice, key;
    cout << "Enter the size of hash table: ";
    cin >> size;

    HashTable ht(size);

    while (true) {
        cout << "\n--- Hash ADT Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
