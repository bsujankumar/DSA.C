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

void addLast(Node **head, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = value;
    new_node -> next = NULL;
    if(*head == NULL){
      *head = new_node;
      return;
    }
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp -> next = new_node;
}

void addPos(Node **head, int pos, int value){
    if(pos == 1){
        addFirst(head, value);
        return;
    }
    Node *temp = *head;
    int i = 1;
    while(i < pos - 1 && temp -> next != NULL){
        temp = temp -> next;
        i++;
    }
    if(i < pos -1){
        printf("Position out of range \n");
        return;
    }
    if(temp -> next == NULL){
        addLast(head, value);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void addOrder(Node **head , int key){
    if(*head == NULL){
        addFirst(head, key);
        return;
    }
    Node *temp = *head;
    int i = 1;
    while(temp != NULL){
        if(key <= temp -> data){
            addPos(head, i, key);
            return;
        }
        temp = temp -> next;
        i++;
    }
    addPos(head, i, key);
}

void display(Node **head){
    Node *temp = *head;
    while(temp!= NULL){
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    Node *head = NULL;
    //10, 5, 8,11
    addOrder(&head, 10);
    display(&head);
    addOrder(&head, 5);
    display(&head);
    addOrder(&head, 8);
    display(&head);
    addOrder(&head, 11);
    display(&head);
    addOrder(&head, 9);
    display(&head);
    addOrder(&head, 15);
    display(&head);
}


