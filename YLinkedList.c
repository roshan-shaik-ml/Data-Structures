/*
 *    Author: Shaik Faizan Roshan Ali
 *    Date: 18th January 2020
 *    Email: alsahercoder@gmail.com
 *    Description: Find the node at which the intersection of two singly linked lists begins.
 *    Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *    Approach:
 *          - We need to compare the nodes of both linked lists. 
 *          - As the linked list can have different length, two pointer direct comparison can fail.
 *          - So, Count the total Nodes in each of the given two linked list.
 *          - We don't need the (bigger LL length - smaller LL length) nodes of the bigger linked list.
 *          - We adjust that by traversing the pointer (bigger LL length - smaller LL length) nodes ahead of the bigger linked list.
 *          - Now, we can directly compare them and return the node where both pointers match.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *next;
}*headOne = NULL, *headTwo = NULL, *ptr;

int countNodes(struct node *head) {
    
    int count = 0;
    for(ptr = head; ptr != NULL; ptr = ptr -> next) {
        
        count++
    }
    free(ptr);
    return count;
}

struct node *getNode(struct node *headOne, struct node *headTwo) {
    
    int nodesInOne = countNodes(head1);
    int nodesInTwo = countNodes(head2);
    
    struct node *ptr1 = headOne;
    struct node *ptr2 = headTwo;
    
    /* Increases one of the pointer of linked list to equal length */
    if(nodesInOne > nodesInTwo) {
        
        int changePtr = nodesInOne - nodesInTwo;
        while(changePtr--) {
            
            ptr1 = ptr1 -> next;
        }
    }
    
    else {
        
        int changePtr = nodesInTwo - nodesInOne;
        while(changePtr--) {
            
            ptr2 = ptr2 -> next;
        }
    }
    
    for(;ptr1 != NULL || ptr2 != NULL; ptr1 = ptr1 -> next, ptr2 = ptr2 -> next){
                    
        if(ptr1 != ptr2) {
            
            continue;
        }    
        
        else if (ptr1 == ptr2) {
            
            break;    
        }
    }
    
    return ptr1;
}

int main() {
    
    struct node *ptr = getNode(headOne, headTwo);
    return 0;
}
