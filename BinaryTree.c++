#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in BST
Node* insertNode(Node* root, int data) {
    if (root == nullptr) return createNode(data);
    if (data < root->data) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

// Function to delete a node from BST
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder Traversal (Recursive)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Recursive)
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Recursive)
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Inorder Traversal (Non-recursive)
void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Preorder Traversal (Non-recursive)
void preorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* temp = s.top(); s.pop();
        cout << temp->data << " ";
        if (temp->right) s.push(temp->right);
        if (temp->left) s.push(temp->left);
    }
}

// Postorder Traversal (Non-recursive)
void postorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* temp = s1.top(); s1.pop();
        s2.push(temp);
        if (temp->left) s1.push(temp->left);
        if (temp->right) s1.push(temp->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    Node* root = nullptr;
    int choice, num, key;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert multiple nodes\n";
        cout << "2. Delete a node\n";
        cout << "3. Inorder Traversal (Recursive)\n";
        cout << "4. Preorder Traversal (Recursive)\n";
        cout << "5. Postorder Traversal (Recursive)\n";
        cout << "6. Inorder Traversal (Non-recursive)\n";
        cout << "7. Preorder Traversal (Non-recursive)\n";
        cout << "8. Postorder Traversal (Non-recursive)\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> num;
                cout << "Enter elements: ";
                for (int i = 0; i < num; i++) {
                    int val;
                    cin >> val;
                    root = insertNode(root, val);
                }
                break;
            case 2:
                cout << "Enter node to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            case 3:
                inorder(root);
                cout << endl;
                break;
            case 4:
                preorder(root);
                cout << endl;
                break;
            case 5:
                postorder(root);
                cout << endl;
                break;
            case 6:
                inorderIterative(root);
                cout << endl;
                break;
            case 7:
                preorderIterative(root);
                cout << endl;
                break;
            case 8:
                postorderIterative(root);
                cout << endl;
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 9);
    return 0;
}
