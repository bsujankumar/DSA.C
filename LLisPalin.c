//Palindrom using Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

//function to add elements 
void addFirst(Node **head, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode -> next = *head;
    *head = newNode;
}

//function to find middle element
Node * getMid(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(fast != NULL){        //for odd number of elements 
        slow = slow -> next;
    }
    return slow;
}

//function to check palindrome
int isPalin(Node *head){
    Node *mid = getMid(head);
    Node *prev = NULL;
    Node *cur = mid;
    Node *next;
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    Node *Right = prev;
    Node *Left = head;
    while(Right != NULL){
        if(Left -> data != Right -> data){
            return 0;
        }
        Right = Right -> next;
        Left = Left -> next;
    }
    return 1;

}

int main(){
    Node *head = NULL;
    addFirst(&head, 1);       //inserting the elements 
    addFirst(&head, 2);  
    addFirst(&head, 3);   
    addFirst(&head, 4);  
    addFirst(&head, 3);  
    addFirst(&head, 2);  
    addFirst(&head, 1);  
    if(isPalin(head)){
        printf("LL is Palindrome");
    }
    else{
        printf("LL is not a palidrome");
    }
}