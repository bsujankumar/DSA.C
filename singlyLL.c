#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;      //head is a pointer , *head is a Node that head points to
Node *tail = NULL;

void addFirst(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL){           //if Linked List is initially empty then head = tail = newNode
        head = tail = newNode;
        return;
    }
    newNode -> next = head;
    head = newNode;
}

void addLast(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL){          //if Linked List is initially empty then head = tail = newNode
        head = tail = newNode;
        return;
    }
    tail -> next = newNode;
    tail = newNode;
}

void addMiddle(int idx, int value){
    if(idx == 0){                        //adding at the first Node
        addFirst(value);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    Node *temp = head;
    int i = 0;
    while(i < idx - 1 && temp != NULL){  //getting the previous Node
        temp = temp -> next;
        i++;
    }
    if(temp == NULL){
        printf("Index out of range \n");
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    if(newNode -> next == NULL){     //adding at the last
        tail = newNode;
    }
}

void display(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("NULL");
}

int main(){
    addFirst(30);
    addFirst(20);
    addFirst(10);
    addLast(50);
    addLast(60);
    addLast(70);
    addMiddle(3,40);  //addMiddle(idx,value);
    display();
}