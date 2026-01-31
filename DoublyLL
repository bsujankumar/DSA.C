#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

void addFirst(Node **head, int val){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode -> next = *head;
    *head = newNode;
}

void addLast(Node **head, int val){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
}

void deleteFirst(Node **head){
    if(*head == NULL){
        printf("LL is empty \n");
        return;
    }
    Node *temp = *head;
    *head = (*head) -> next;
    free(temp);
}

void deleteLast(Node **head){
    if(*head == NULL){
        printf("LL is empty \n");
        return;
    }
    if((*head) -> next == NULL){
        Node *temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    Node *temp = *head;
    Node *prev;
    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
}

void display(Node *head){
    if(head == NULL){
        printf("LL is empty \n");
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL \n");
}

int main(){
    Node * head = NULL;
    addFirst(&head,3);
    addFirst(&head,2);
    addFirst(&head,1);
    addLast(&head,4);
    addLast(&head,5);
    addLast(&head,6);
    display(head);
    deleteFirst(&head);
    display(head);
    deleteLast(&head);
    display(head);
}
