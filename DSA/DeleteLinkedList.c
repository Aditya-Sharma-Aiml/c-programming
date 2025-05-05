#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data; 
    struct Node* link;

};
struct Node* create_node(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = data; 
    newNode -> link = NULL;
    return newNode;
}
struct Node* insert(struct Node*head,int data){
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
void delete_list(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        temp = temp -> link;
        free(head);
        head = temp;
    }
    printf("Whole list deleted...");

}
int main (){
    struct Node* head = NULL;
    int data , choice;
    while(1){
        printf("options\n");
        printf("1: insertion\n");
        printf("2: delete whole linked list\n");
        printf("3: Exit..\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
         switch(choice){
        case 1: 
            printf("Enter the data: ");
            scanf("%d",&data);
            head = insert(head,data);
            break;
        case 2:
            delete_list(head);
            break;
        case 3:
            printf("Exiting...");
            return 0;
        default: 
            printf("invalid choice!");
            break;
    }
        }
   
}
