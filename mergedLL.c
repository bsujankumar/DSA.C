#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void addFirst(Node **head, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = value;
    new_node -> next = NULL;
    if(*head == NULL){
      *head = new_node;
      return;
    }
    new_node -> next = *head;
    *head = new_node;
}

void display(Node *head){
    Node *temp = head;
    while(temp!= NULL){
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

Node * mergeSort(Node *head1, Node *head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node mergedhead ;
    mergedhead.next = NULL;
    Node *temp = &mergedhead;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            temp -> next = head1;
            head1 = head1 -> next;
            temp = temp -> next;
        }
        else{
            temp -> next = head2;
            head2 = head2 -> next;
            temp = temp -> next;
        }
    }
    while(head1 != NULL){
        temp -> next = head1;
        head1 = head1 -> next;
        temp = temp -> next;
    }
    while( head2 != NULL){
        temp -> next = head2;
        head2 = head2 -> next;
        temp = temp -> next;
    }
    return mergedhead.next;

}

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;

    addFirst(&head1, 40);
    addFirst(&head1, 20);
    addFirst(&head1, 10);

    addFirst(&head2, 70);
    addFirst(&head2, 60);
    addFirst(&head2, 50);
    addFirst(&head2, 30);

    display(head1);
    display(head2);

    Node *head = mergeSort(head1, head2);
    display(head);
}