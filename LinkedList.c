#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Head pointer to the linked list

// Function to insert multiple elements into the linked list
void insertMultiple() {
    int n, value;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to insert at a given position from the front
void insertAtFrontPosition(int pos, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert at a given position from the end
void insertAtEndPosition(int pos, int value) {
    struct Node* temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }
    insertAtFrontPosition(length - pos + 2, value);
}

// Function to delete a node at a given position from the front
void deleteFromFrontPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to delete a node at a given position from the end
void deleteFromEndPosition(int pos) {
    struct Node* temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }
    deleteFromFrontPosition(length - pos + 1);
}

// Function to display the linked list
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, pos, value;
    do {
        printf("\nMenu:\n");
        printf("1. Insert elements in linked list\n");
        printf("2. Insert at given position from front\n");
        printf("3. Insert at given position from end\n");
        printf("4. Delete from given position from front\n");
        printf("5. Delete from given position from end\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertMultiple();
                break;
            case 2:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                insertAtFrontPosition(pos, value);
                break;
            case 3:
                printf("Enter position from end and value to insert: ");
                scanf("%d %d", &pos, &value);
                insertAtEndPosition(pos, value);
                break;
            case 4:
                printf("Enter position from front to delete: ");
                scanf("%d", &pos);
                deleteFromFrontPosition(pos);
                break;
            case 5:
                printf("Enter position from end to delete: ");
                scanf("%d", &pos);
                deleteFromEndPosition(pos);
                break;
            case 6:
                displayList();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}
