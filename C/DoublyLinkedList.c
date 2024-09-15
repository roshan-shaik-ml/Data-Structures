#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *prev;
    struct node *next;
}*head = NULL, *ptr, *tail = NULL;

struct node *createLL(struct node *head) {
    
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);    
    
    while(num != -1) {
        
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> data = num;
        
        if(head == NULL) {
            
            head = newNode;    
            newNode -> prev = NULL;
            newNode -> next = NULL;    
            tail = newNode;
        }
        
        else {
            
            for(ptr = head; ptr -> next != NULL; ptr = ptr -> next);
            ptr -> next = newNode;
            newNode -> prev = ptr;
            tail = newNode;
        }
        newNode -> next = NULL;
        printf("Enter the number: ");
        scanf("%d", &num);    
    }
    return head;
}

struct node *display(struct node *head) {
    
    for(ptr = head; ptr != NULL; ptr = ptr -> next) {
        
        printf("%d  ", ptr -> data);
    }
    printf("\n");
    return head;
}

struct node *insertBegLL(struct node *head) {
    
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
        
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = num;
    
    newNode -> next = head;
    head = newNode;
    newNode -> prev = NULL;

    return head;
}


struct node *insertEndLL(struct node *head) {
        
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    newNode -> data = num;

    /* Using tail pointer for end insertion */
    tail -> next = newNode;
    newNode -> prev = tail;
    newNode -> next = NULL;
    tail = tail -> next;
    return head;
}

struct node *deleteBegLL(struct node *head) {
    
    ptr = head;
    head = head -> next;
    ptr -> prev = head;
    free(ptr);
    return head; 
}

struct node *deleteEndLL(struct node *head) {
    
    /* Edge case when tail = head */
    if(tail == head) {
        
        free(tail);
    }
    
    /* Changing the next value of last but one node to NULL */
    else {
        
        tail -> prev -> next = NULL;  
        ptr = tail;
        tail = tail -> prev;
        free(ptr);    
    }
    
    return head;
}

int main() {
    
    head = createLL(head);
    head = display(head);
    
    head = insertEndLL(head);
    head = display(head);
    
    head = insertBegLL(head);
    head = display(head);
    
    head = deleteBegLL(head);
    head = display(head);
}
