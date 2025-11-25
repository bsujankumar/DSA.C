#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void addFirst(Node **head, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = value;
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

void deleteFirst(Node **head){
    if(*head == NULL){
        printf("The Linked list is empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head) -> next;
    free(temp);
}

void deleteLast(Node **head){
    if(*head == NULL){
        printf("The Linked list is empty\n");
    }
    else if((*head) -> next == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        Node *temp = *head;
        Node *prev = NULL;
        while(temp -> next != NULL){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        free(temp);
    }
}

void display(Node *head){
    Node *temp = head;
    while(temp!= NULL){
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void itrSearch(Node **head , int key){
    if(*head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    Node *temp = *head;
    while(temp != NULL){
        if(temp -> data == key){
            printf("Key is found\n");
            return;
        }
        temp = temp -> next;
    }
    printf("Key not found\n");
}

int sizeOf(Node *head){
    if(head == NULL){
        printf("Linked list is empty\n");
        return 0;
    }
    Node *temp = head;
    int size = 1;
    while(temp -> next != NULL){
        size += 1;
        temp = temp -> next;
    }
    return size;
}

int main(){
    Node *head = NULL;
    addFirst(&head,20);
    addFirst(&head,10);
    addLast(&head,40);
    addLast(&head,50);
    display(head);
    deleteFirst(&head);
    display(head);
    deleteLast(&head);
    display(head);
    deleteFirst(&head);
    display(head);
    itrSearch(&head, 80);
    printf("%d\n",sizeOf(head));
    deleteLast(&head);
    display(head);
}