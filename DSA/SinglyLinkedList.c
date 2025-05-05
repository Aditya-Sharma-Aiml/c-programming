#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertAtStart(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* insertAtPosition(struct Node* head, int data, int position);
struct Node* deleteAtStart(struct Node* head);
struct Node* deleteAtEnd(struct Node* head);
struct Node* deleteAtPosition(struct Node* head, int position);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at start\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                head = insertAtStart(head, data);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteAtStart(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the start of the list
struct Node* insertAtStart(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) {
        return head;
    }
    newNode->next = head;
    printf("Node with value %d inserted at the start.\n", data);
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) {
        return head;
    }

    if (head == NULL) {
        printf("Node with value %d inserted at the end.\n", data);
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node with value %d inserted at the end.\n", data);
    return head;
}

// Function to insert a node at a specific position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        return insertAtStart(head, data);
    }

    struct Node* newNode = createNode(data);
    if (!newNode) {
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node with value %d inserted at position %d.\n", data, position);
    return head;
}

// Function to delete a node at the start of the list
struct Node* deleteAtStart(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    struct Node* temp = head;
    head = temp->next;
    free(temp);
    printf("Node deleted at the start.\n");
    return head;
}
// Function to delete a node at the end of the list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        printf("Node deleted at the end.\n");
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Node deleted at the end.\n");
    return head;
}

// Function to delete a node at a specific position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("The list is empty or invalid position.\n");
        return head;
    }

    if (position == 1) {
        return deleteAtStart(head);
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted at position %d.\n", position);
    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
