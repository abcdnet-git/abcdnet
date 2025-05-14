#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    
    Node(int data) {
        this->data = data;
        this->prev = this->next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node *head, *tail;
    
public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }
    
    void insertNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Node inserted: " << data << endl;
    }
    
    void findEvenNodes() {
        Node* temp = head;
        cout << "Even nodes: ";
        bool found = false;
        while (temp != nullptr) {
            if (temp->data % 2 == 0) {
                cout << temp->data << " ";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "None";
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, data, numElements;
    
    cout << "Enter the number of initial elements: ";
    cin >> numElements;
    cout << "Enter the elements: ";
    for (int i = 0; i < numElements; i++) {
        cin >> data;
        dll.insertNode(data);
    }
    
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Find Even Nodes" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                dll.insertNode(data);
                break;
            case 2:
                dll.findEvenNodes();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}
