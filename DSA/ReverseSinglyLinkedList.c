#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node** head_ref, int new_data) {
    /* 1 Allocate Node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 2 Put in the data */
    new_node->data = new_data;

    /* 3 Make next of new Node as head */
    new_node->next = (*head_ref);

    /* 4 Move the head to point to new Node */
    (*head_ref) = new_node;

    return *head_ref;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = push(&head, 20);
    head = push(&head, 4);
    head = push(&head, 15);
    head = push(&head, 85);
    head = push(&head, 100);

    printf("Given linked list\n");
    printList(head);

    head = reverseList(head);

    printf("\nReversed linked list \n");
    printList(head);
    
    return 0;
}