#include <iostream>
using namespace std;

const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int* table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int tableSize) {
        size = tableSize;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = EMPTY;
        }
    }

    ~HashTable() {
        delete[] table;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        table[index] = key;
        cout << "Inserted " << key << " at index " << index << "\n";
    }

    void search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                cout << "Key " << key << " found at index " << index << "\n";
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        cout << "Key " << key << " not found.\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                cout << "Key " << key << " deleted from index " << index << "\n";
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        cout << "Key " << key << " not found for deletion.\n";
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; i++) {
            if (table[i] == EMPTY) {
                cout << i << ": [EMPTY]\n";
            } else if (table[i] == DELETED) {
                cout << i << ": [DELETED]\n";
            } else {
                cout << i << ": " << table[i] << "\n";
            }
        }
    }
};

int main() {
    int tableSize;
    cout << "Enter size of hash table: ";
    cin >> tableSize;

    HashTable ht(tableSize);
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu ---\n";
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
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
 