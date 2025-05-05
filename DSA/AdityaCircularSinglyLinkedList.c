#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* addToEmpty(int data) {
    Node* newNode = createNode(data);
    newNode->next = newNode; 
    printf("Node inserted in empty list.\n");
    return newNode; 
}
Node* insertAtBeginning(Node* tail, int data) {
    if (tail == NULL) {
        return addToEmpty(data);
    } else {
        Node* newNode = createNode(data);
        newNode -> next = tail -> next;
        tail -> next = newNode;
        printf("node is inserted at begin.\n");
    }
    
    return tail; 
}
 Node* insertAtEnd( Node* tail, int data) {
    if (tail == NULL) {
        return addToEmpty(data);
    } else {
        Node* newNode = createNode(data);
        newNode->next = tail->next; 
        tail->next = newNode; 
        tail = newNode; 
        printf("node is inserted at end.\n");
    }
    return tail; 
}

struct Node* insertAtPosition(struct Node* tail, int data, int position) {
    int pos = position;
    if (position == 1) {
        return insertAtBeginning(tail, data);
    }

    if (tail == NULL) {
        return addToEmpty(data);
    }

    struct Node* newNode = createNode(data);

    struct Node* temp = tail->next; 

    for (int i = 1; i < position - 1 && temp != tail; i++) {
        temp = temp->next; 
    } 
    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail) {
        tail = newNode; 
    }
    printf("node is inserted of position %d.\n",pos);
    return tail; 

}

Node* deleteFromBeginning(Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    Node* temp = tail->next; 

    if (tail == tail->next) { 
        free(tail);
        tail = NULL;
    } else {
        tail->next = temp->next; 
        free(temp);
        
    }
    printf("Node is deleted from begining.\n");
    return tail; 
}
struct Node* deleteFromEnd(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = tail->next; 
    if (tail == tail->next) { 
        free(tail);
        tail = NULL;
    } else {
        while (temp->next != tail) { 
            temp = temp->next;
        }
        temp->next = tail->next; 
        free(tail);
        tail = temp;
        
        printf("Node is deleted from end.\n");
    }

    return tail; 
}
struct Node* deleteFromPosition(struct Node* tail, int position) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    if (position == 1) {
        return deleteFromBeginning(tail);
    }

    struct Node* temp = tail->next; 
    struct Node* prev = NULL;

    for (int i = 1; i < position && temp != tail; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == tail->next) { 
        printf("Position out of bounds!\n");
        return tail;
    }

    prev->next = temp->next;

    if (temp == tail) {
        tail = prev; 
    }
    free(temp);
    printf("Node is deleted of position: %d \n",position);
    return tail; 
}
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = tail->next; 
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("head\n");
}


int main() {
    int choice, data, position;
    Node* tail = NULL; 

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
