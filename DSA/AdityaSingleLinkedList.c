#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;

};
struct Node* create_node(int newdata){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=newdata;
    newNode->link=NULL;
    return newNode;
}
struct Node* insertion_at_end(struct Node*head,int data){

    struct Node *newNode = create_node(data);

    if (!newNode) {
        return head;
    }

    if (head == NULL) {
        printf("Node with value %d inserted.\n", data);
        return newNode;
    }

    struct Node* temp=head;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = newNode;
    printf("Node with value %d inserted at the end.\n", data);
    return head;

}
struct Node* insertion_at_start(struct Node*head,int data){
    struct Node* newNode = create_node(data);
    if (!newNode) {
        return head;
    }
    newNode->link = head;
    printf("Node with value %d inserted at the start.\n", data);
    // newNode = head;
    // return head;
    return newNode;
}
struct Node* insertion_at_position(struct Node* head,int data,int position){

     if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1) {
        return insertion_at_start(head, data);
    }

    struct Node* newNode = create_node(data);

    if (!newNode) {
        return head;
    }
    
    struct Node* temp = head;

    for (int i = 1; temp != NULL && i < position - 1; i++) 
    {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }
    ////imp////
    newNode->link = temp->link;
    temp->link = newNode;
    printf("Node with value %d inserted at position %d.\n", data, position);
    return head;
    /////
}
struct Node* deletion_at_end(struct Node*head){
   if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    if (head->link == NULL) {
        free(head);
        printf("Node deleted at the end.\n");
        return NULL;
    }

    // struct Node* temp = head;
    // struct Node* prev = NULL;
    // while (temp->link != NULL) {
    //     prev = temp;
    //     temp = temp->link;
        // prev->link = NULL;
        // free(temp);
        // printf("Node deleted at the end.\n");
        // return head;

        //using one pointer:
        struct Node* temp = head;
        while(temp -> link -> link != NULL){
            temp = temp -> link;
        }
        free(temp -> link);
        temp -> link = NULL;
        printf("Node deleted at the end.\n");
        return head;
    }

struct Node* deletion_from_start(struct Node*head){

    if (head == NULL){
        printf("Empty linked list.....!\n");
        
    }
    else{
        struct Node* temp = head;
        head = head -> link;
        free(temp);
        temp = NULL;
        printf("Node deleted at the start.\n");
    }
    
    return head;
}
struct Node* deletion_at_position(struct Node* head , int position){
    int pos = position;
    struct Node* prev = head;
    struct Node* current = head;

    if (position == 1 ) return deletion_from_start(head);

    else if (head == NULL || position < 1){
        printf("linked list empty or invalid position...!");
    }
    
    else
    {   
        
        while(position!=1){
            prev = current;
            current = current -> link ;
            position--;
        }
         if ( current == NULL) {
        printf("Position out of bounds.\n");
        return head;
        }
        prev -> link = current -> link;
        free(current);
        current = NULL;
        printf("Node deleted at position %d.\n", pos);
}    

    return head;
}
void display_list(struct Node*head){
    if (head == NULL) {
            printf("The list is empty.\n");
            return;
        }
    printf("Linked List are: \n");
    
    struct Node*temp = head;

    while(temp!=NULL){
        printf("%d -> ",temp -> data);
        temp = temp -> link;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head =NULL;
    int choice,data,position;

    while(1){
        printf("\noptions\n");
        printf("1 : Enter for insertion at end\n");
        printf("2 : Enter for insertion at start\n");
        printf("3 : Enter for insertion at position\n");
        printf("4 : Enter for deletion at end\n");
        printf("5 : Enter for deletion at start\n");
        printf("6 : Enter for deletion at position\n");
        printf("7 : Display the list\n");
        printf("8 : Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);

    
    switch(choice){
        case 1:
            printf("Enter the data: ");
            scanf("%d",&data);
            head = insertion_at_end(head,data);
            break;
        case 2: 
            printf("Enter the data: ");
            scanf("%d",&data);
            head = insertion_at_start(head,data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d",&data);
            printf("Enter the position: ");
            scanf("%d",&position);
            head = insertion_at_position(head,data,position);
            break;

        case 4:
            head = deletion_at_end(head);
            break;

        case 5:
            head = deletion_from_start(head);
            break;

        case 6:
            printf("Enter the postion to delete:");
            scanf("%d",&position);
            head = deletion_at_position(head,position);

        case 7:
            display_list(head);
            break;
        case 8:
            printf("Exiting the program...");
            return 0;

        default:
            printf("invalid choice");
            break;
    }

    }
    }