#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

// Implementation of Circular Queue
class CircularQueue {
private:
    int *arr;
    int front, rear, size;
    int capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) // First element insertion
            front = rear = 0;
        else if (rear == capacity - 1 && front != 0)
            rear = 0;
        else
            rear++;

        arr[rear] = value;
        cout << "Inserted " << value << endl;
    }

    void enqueueMultiple(string input) {
        stringstream ss(input);
        int value;
        while (ss >> value) {
            if (isFull()) {
                cout << "Queue is full! Stopping insertion.\n";
                break;
            }
            enqueue(value);
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int data = arr[front];
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else if (front == capacity - 1)
            front = 0;
        else
            front++;

        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Circular Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < capacity; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Reversing a Stack using a Queue
void reverseStack(stack<int> &stk) {
    queue<int> q;
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
    while (!q.empty()) {
        stk.push(q.front());
        q.pop();
    }
}

void displayStack(stack<int> stk) {
    cout << "Stack elements (top to bottom): ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    int queueSize;
    cout << "Enter the size of the Circular Queue: ";
    cin >> queueSize;
    cin.ignore();  // Clear the buffer

    CircularQueue cq(queueSize);

    int choice;
    string input;
    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue multiple values\n2. Dequeue\n3. Display Queue\n4. Exit Queue Operations\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter space-separated values to enqueue: ";
                getline(cin, input);
                cq.enqueueMultiple(input);
                break;
            case 2:
                cout << "Dequeued: " << cq.dequeue() << endl;
                break;
            case 3:
                cq.display();
                break;
            case 4:
                goto stackOperations;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }

stackOperations:
    stack<int> stk;
    while (true) {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Display Stack\n4. Reverse Stack\n5. Exit Program\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stk.push(value);
                break;
            case 2:
                if (!stk.empty()) {
                    cout << "Popped: " << stk.top() << endl;
                    stk.pop();
                } else {
                    cout << "Stack is empty!\n";
                }
                break;
            case 3:
                displayStack(stk);
                break;
            case 4:
                reverseStack(stk);
                cout << "Stack reversed.\n";
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}

