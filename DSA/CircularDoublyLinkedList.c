#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;  // Circular links
    return newNode;
}

Node* addToEmpty(int data) {
    Node* newNode = createNode(data);
    printf("Node inserted in empty list.\n");
    return newNode;
}

Node* insertAtBeginning(Node* tail, int data) {
    if (tail == NULL) {
        return addToEmpty(data);
    } else {
        Node* newNode = createNode(data);
        newNode->next = tail->next;      // New node points to the first node
        newNode->prev = tail;            // Tail points back to the new node
        tail->next->prev = newNode;      // First node points back to the new node
        tail->next = newNode;            // Tail's next points to the new node
        printf("Node inserted at beginning.\n");
    }
    return tail;
}

Node* insertAtEnd(Node* tail, int data) {
    if (tail == NULL) {
        return addToEmpty(data);
    } else {
        Node* newNode = createNode(data);
        newNode->next = tail->next;     // New node points to head (circular)
        newNode->prev = tail;           // Tail points to new node
        tail->next->prev = newNode;     // Head points back to the new node
        tail->next = newNode;           // Tail's next points to the new node
        tail = newNode;                 // New node becomes the tail
        printf("Node inserted at end.\n");
    }
    return tail;
}

Node* insertAtPosition(Node* tail, int data, int position) {
    if (position == 1) {
        return insertAtBeginning(tail, data);
    }

    if (tail == NULL) {
        return addToEmpty(data);
    }

    Node* newNode = createNode(data);
    Node* temp = tail->next;  // Start from the head

    for (int i = 1; i < position - 1 && temp != tail; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;      // New node points to the next node
    newNode->prev = temp;            // Previous node points to the new node
    temp->next->prev = newNode;      // Next node points back to the new node
    temp->next = newNode;            // Previous node's next points to the new node

    if (temp == tail) {
        tail = newNode;  // Update tail if insertion is at the end
    }

    printf("Node inserted at position %d.\n", position);
    return tail;
}

Node* deleteFromBeginning(Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node* temp = tail->next;  // Head node

    if (tail == tail->next) {  // Only one node in the list
        free(tail);
        tail = NULL;
    } else {
        tail->next = temp->next;    // Tail's next points to the second node
        temp->next->prev = tail;    // Second node's previous points to the tail
        free(temp);
    }

    printf("Node deleted from beginning.\n");
    return tail;
}

Node* deleteFromEnd(Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node* temp = tail;

    if (tail == tail->next) {  // Only one node in the list
        free(tail);
        tail = NULL;
    } else {
        tail = tail->prev;        // Tail moves to the previous node
        tail->next = temp->next;  // New tail's next points to the head
        temp->next->prev = tail;  // Head's previous points to the new tail
        free(temp);
    }

    printf("Node deleted from end.\n");
    return tail;
}

Node* deleteFromPosition(Node* tail, int position) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (position == 1) {
        return deleteFromBeginning(tail);
    }

    Node* temp = tail->next;

    for (int i = 1; i < position && temp != tail; i++) {
        temp = temp->next;
    }

    //Node* previous = temp -> prev;

    if (temp == tail->next) {  // Position out of bounds
        printf("Position out of bounds!\n");
        return tail;
    }
    
    temp->prev->next = temp->next;    // Previous node's next points to the next node
    //previous -> next = temp -> next;
    temp->next->prev = temp->prev;    // Next node's previous points to the previous node

    if (temp == tail) {
        tail = temp->prev;  // Update tail if the deleted node was the tail
    }

    free(temp);
    printf("Node deleted from position %d.\n", position);
    return tail;
}

// Function to display the list
void display(Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = tail->next;  // Start from the head
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);  // Stop when it circles back to the head
    printf("head\n");
}

int main() {
    int choice, data, position;
    Node* tail = NULL;

    while (1) {
        printf("\nCircular Doubly Linked List Operations:\n");
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
                tail = insertAtBeginning(tail, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                tail = insertAtEnd(tail, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                tail = insertAtPosition(tail, data, position);
                break;
            case 4:
                tail = deleteFromBeginning(tail);
                break;
            case 5:
                tail = deleteFromEnd(tail);
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                tail = deleteFromPosition(tail, position);
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
 