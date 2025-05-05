#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
    struct Node* prev;
    int data;
    struct Node* next;

}Node;

Node* createNode(int newdata){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> prev = NULL;
    newNode -> data = newdata;
    newNode -> next = NULL;
    return newNode;
}

Node* insertAtBegining(Node* head,int data){
    Node* newNode = createNode(data);
    if (head!=NULL){
        newNode -> next = head;
        head -> prev = newNode;
        
    }
    printf("node is inserted at begin.\n");
    head = newNode;
    return head;
}
Node* insertAtEnd(Node* head,int data){

    Node* newNode = createNode(data);

    if (head==NULL) return newNode; 
    
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
    printf("node is inserted at end.\n");
    return head;

}
Node* insertAtPosition(Node* head,int data,int position){
    Node *temp = head;
    Node* newNode = createNode(data);
    int pos = position;

    if (position < 1){
        printf("invalid position !");
        return head;
    }
    if (position == 1) return insertAtBegining(head,data);

    else{
        for (int i = 1; temp != NULL && i < position-1; i++) {
        temp = temp->next;
    }
    if (temp == NULL){
        printf("position out of bound!");
        free(newNode);
        return head;
    }

    Node* current = temp -> next;

    if (current == NULL){
        head = insertAtEnd(head,data);
    }
    else{
        temp -> next = newNode;
        current -> prev = newNode;
        newNode -> prev = temp;
        newNode -> next = current;
    }
    printf("node is inserted at position %d.\n",pos);
    return head;

    }  

}
Node* deleteFromBeginning(Node* head){
    if (head == NULL) {
        printf("list is empty!");
        return head;
    } 
    else{
        head = head -> next;
        free(head->prev);
        head -> prev = NULL;
        printf("Node deleted from the beginning.\n");
        return  head;
    }
    
}  
Node* deleteFromEnd(Node* head){
    if (head == NULL) {
        printf("list is empty!");
        return head;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;

    }
    Node* previous =  temp->prev;
    if (previous!=NULL){
        previous -> next = NULL;
    }
    else{
        head = NULL;
    }
    free(temp);
    temp = NULL;
    printf("Node deleted from the End.\n");
    return head;
}
Node* deleteFromPosition(Node* head, int position){

    Node *temp = head;

    int pos = position;
    if (head == NULL || position <=0){
        printf("Invalid position or empty list \n");
        return head;

    }
    else if (position == 1) return deleteFromBeginning(head);

    else{
         for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    else{
        Node* previous = temp -> prev;
        previous -> next = temp -> next;
        temp -> next -> prev = previous;
        free(temp);
        temp = NULL;
        printf("node is deleted of position %d.\n",pos);
        return head;
  
    }
  
}

void displayList(Node* head){
    if (head==NULL){
        printf("Empty Linked List!\n");
        return;
    } 
    else{
        Node* temp = head;
        printf("Doubly Linked List are: \n");
        while(temp != NULL){
            printf("%d <-> ",temp->data);
            temp = temp -> next;

        }
        printf("NULL\n");
    }
    

}
int main (){
    Node* head = NULL;
    int data,choice,position;
    while(1){
        printf("\nMenu:\n");
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

        switch(choice){
           
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBegining(head,data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}