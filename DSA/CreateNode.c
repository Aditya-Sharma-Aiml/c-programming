#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int new_data) {
    struct Node* new_node = 
       (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Given the head of a list and an int, appends
// a new node at the end and returns the head.
struct Node* append(struct Node* head, int new_data) {
  
    // Create a new node
    struct Node* new_node = createNode(new_data);

    // If the Linked List is empty, make
    // the new node as the head and return
    if (head == NULL) {
        return new_node;
    }

    // Store the head reference in a temporary variable
    struct Node* last = head;

    // Traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next pointer of the last node 
    // to point to the new node
    last->next = new_node;

    // Return the head of the list
    return head;
}

// This function prints the contents 
// of the linked list starting from the head
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

// Driver code
int main() {
  
    // Create a hard-coded linked list: 
    // 2 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(6);

    printf("Created Linked list is:");
    printList(head);

    // Example of appending a node at the end
    head = append(head, 1);

    printf("\nAfter inserting 1 at the end:");
    printList(head);

    return 0;
}