/*
    Name: Floyd's Cycle Detection Algorithm 
    Author: Shaik Faizan Roshan Ali
    Date: 14th January 2021
    Description: To detect a loop in single Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *next;
}*head = NULL;
struct node *checkCycleLL(struct node *head) {
    
    struct node *tortoise = head;
    struct node *hare = head;
    
    while(hare -> next != NULL || hare -> next -> next != NULL) {
        
        if(tortoise == hare)    {
            
            printf("Cycle exists in the Linked List");
            return head;
        }
        hare = hare -> next -> next;
        tortoise = tortoise -> next;
    }
    
    printf("Cycle doesn't exists in the Linked List");
    return head;    
}
int main() {
    
    head = checkCycleLL(head);
    return 0;
}
