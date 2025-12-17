#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};


Node* createNode(char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


Node* insert(Node* root, char value) {
    if (!root) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}


void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


bool search(Node* root, char key) {
    if (!root) return false;
    if (root->data == key) return true;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}


int main() {
    Node* root = nullptr;
    int choice;
    char value;
    
    do {
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                preorder(root);
                cout << endl;
                break;
            case 3:
                inorder(root);
                cout << endl;
                break;
            case 4:
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                cout << (search(root, value) ? "Found\n" : "Not Found\n");
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
