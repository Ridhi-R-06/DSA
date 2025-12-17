#include <iostream>
#include <stack>
#include <cctype>
using namespace std;


struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};


Node* constructExpressionTree(string postfix) {
    stack<Node*> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {  
            st.push(new Node(ch));
        } else {  
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            Node* newNode = new Node(ch);
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    return st.top();  
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
        if (!isalnum(root->data)) cout << "("; 
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
        if (!isalnum(root->data)) cout << ")";
    }
}


void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    int choice;
    string postfix;

    do {
        cout << "\n1. Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                root = constructExpressionTree(postfix);
                cout << "Expression Tree Constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
