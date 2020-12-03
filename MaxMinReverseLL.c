#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *maxElement(struct node *head) {
    
    struct node *ptr;
    ptr = head;
    int max = 0;
    
    for(ptr= head; ptr->next != NULL; ptr = ptr->next) {
        
        if(ptr->data > max)
            max = ptr->data;
        else 
            continue;
    }
    printf("\nThe maximum element in LL: %d\n", max);
    return head;
}


struct node *minElement(struct node *head) {
    
    struct node *ptr;
    ptr = head;
    int max = ptr -> data;
    
    for(ptr= head; ptr->next != NULL; ptr = ptr->next) {
        
        if(ptr->data < max)
            max = ptr->data;
        else 
            continue;
    }
    printf("\nThe minimum element in LL: %d\n", max);
    return head;
}

struct node *createLL(struct node *head) {
    
    struct node *newNode, *ptr;
    int num = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    
    while ( num != -1) {
        

        
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        struct node *ptr;
        newNode->data = num;
        
        if(head == NULL) {
            
            head = newNode;
            newNode -> next = NULL;            
        }
        
        else {
            
            ptr = head;
            while(ptr -> next != NULL) {
                
                ptr = ptr -> next;
            }
            ptr->next = newNode;
            newNode -> next = NULL;
        }
        printf("Enter the number: ");
        scanf("%d", &num);
    }
    return head;
}

struct node *reverseLL(struct node *head) {
    
    struct node *backPtr;
    struct node *currentPtr;
    struct node *frontPtr;
    
    backPtr = NULL;
    currentPtr = head;
    frontPtr = NULL;
    
    while(currentPtr != NULL) {
        
        frontPtr = currentPtr -> next;
        currentPtr ->next = backPtr;
        backPtr = currentPtr;
        currentPtr = frontPtr;
        
    }
    head = backPtr;
    return head;
    
}
struct node *displayLL(struct node *start) {
    
    struct node *ptr;
    ptr = start;
    
    while (ptr != NULL) {
        
        printf("%d\t", ptr->data);
        ptr = ptr -> next;
    }
    return start;
}
int main() {
    
    head = createLL(head);
    head = maxElement(head);
    head = minElement(head);
    head = reverseLL(head);
    head = displayLL(head);
    
}
