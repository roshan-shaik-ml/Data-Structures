#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *next;
}*head = NULL, *ptr;

struct node *displayLL(struct node *head) {
    
    for(ptr = head; ptr != NULL; ptr = ptr -> next) {
        
        int num = ptr -> data;
        printf("%d  ", num);
    }
    printf("\n");
    return head;
}

struct node *insertEndLL(struct node *head) {
    
    int num;
    printf("Please enter the number: ");
    scanf("%d", &num);
        
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = num;
        
    if(head == NULL) {
        
        head = newNode;
    }
        
    else {
            
    for(ptr = head; ptr -> next != NULL; ptr = ptr -> next);
            
        ptr -> next = newNode;
    }
    newNode -> next = NULL;
    return head;
}

struct node *deleteBegLL(struct node *head) {
    
    
    ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

int main(){
    
    while(1) {
        
        int op;
        printf("**********MENU*********\n");
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue \n4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &op);
        printf("\n\n");
        
        if(op == 1) {
            
            head = insertEndLL(head);
        }
        else if (op == 2) {
            
            head = deleteBegLL(head);
        }
        else if (op == 3) {
            
            head = displayLL(head);
        }
        else if(op == 4) {
            
            exit(0);
        }
        
        else {
            
            printf("Enter the right operation\n");
        }    
    }
}
