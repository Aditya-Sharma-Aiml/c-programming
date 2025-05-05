#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add the first node to an empty list
struct Node* addToEmpty(struct Node* tail, int data) {
    struct Node* newNode = createNode(data);
    tail = newNode;
    newNode->next = newNode; // Point to itself
    return tail; // Return the updated tail
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* tail, int data) {
    if (tail == NULL) {
        return addToEmpty(tail, data);
    } else {
        struct Node* newNode = createNode(data);
        newNode->next = tail->next; // New node points to the head
        tail->next = newNode; // Tail points to the new node
    }
    return tail; // Return the updated tail
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* tail, int data) {
    if (tail == NULL) {
        return addToEmpty(tail, data);
    } else {
        struct Node* newNode = createNode(data);
        newNode->next = tail->next; // New node points to the head
        tail->next = newNode; // Old tail points to the new node
        tail = newNode; // Update tail to the new node
    }
    return tail; // Return the updated tail
}

// Function to insert a node at a specific position
struct Node* insertAtPosition(struct Node* tail, int data, int position) {
    if (position == 1) {
        return insertAtBeginning(tail, data);
    }

    if (tail == NULL) {
        return addToEmpty(tail, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = tail->next; // Start from the head
    for (int i = 1; i < position - 1 && temp != tail; i++) {
        temp = temp->next; // Traverse to the desired position
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail) {
        tail = newNode; // Update tail if inserted at the end
    }

    return tail; // Return the updated tail
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = tail->next; // Head node
    if (tail == tail->next) { // Only one node in the list
        free(tail);
        tail = NULL;
    } else {
        tail->next = temp->next; // Tail points to the new head
        free(temp);
    }
    return tail; // Return the updated tail
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = tail->next; // Head node
    if (tail == tail->next) { // Only one node in the list
        free(tail);
        tail = NULL;
    } else {
        while (temp->next != tail) { // Traverse to the second last node
            temp = temp->next;
        }
        temp->next = tail->next; // Second last node points to head
        free(tail);
        tail = temp; // Update tail
    }
    return tail; // Return the updated tail
}

// Function to delete a node from a specific position
struct Node* deleteFromPosition(struct Node* tail, int position) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    if (position == 1) {
        return deleteFromBeginning(tail);
    }
    struct Node* temp = tail->next; // Head node
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != tail; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == tail->next) { // Position out of bounds
        printf("Position out of bounds!\n");
        return tail;
    }
    prev->next = temp->next;
    if (temp == tail) {
        tail = prev; // Update tail if last node is deleted
    }
    free(temp);
    return tail; // Return the updated tail
}

// Function to display the list
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = tail->next; // Start from the head
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(head)\n");
}

// Main function to interact with the user
int main() {
    int choice, data, position;
    struct Node* tail = NULL; // Initialize the tail pointer

    while (1) {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                tail = insertAtBeginning(tail, data); // Update tail
                break;

            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                tail = insertAtEnd(tail, data); // Update tail
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                tail = insertAtPosition(tail, data, position); // Update tail
                break;

            case 4:
                tail = deleteFromBeginning(tail); // Update tail
                break;

            case 5:
                tail = deleteFromEnd(tail); // Update tail
                break;

            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                tail = deleteFromPosition(tail, position); // Update tail
                break;

            case 7:
                display(tail);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
