#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* create_node(int newdata){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = newdata ;
    newNode -> link = NULL;
    return newNode;
}
struct Node* insert_at_end(struct Node* ptr,int data){

    struct Node* newNode = create_node(data);
    ptr -> link = newNode;
    printf("Node inserted\n");
    return newNode;

}
int main(){
    struct Node* head = create_node(2);
    struct Node* ptr = head;
    ptr  = insert_at_end(ptr,3);
    ptr  = insert_at_end(ptr,4);
    ptr  = insert_at_end(ptr,5);
    ptr  = insert_at_end(ptr,6);

    printf("linked list are: \n");
    struct Node*temp = head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp -> link;
    }
}