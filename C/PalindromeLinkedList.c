/*
 *    Author: Shaik Faizan Roshan Ali
 *    Date: 20th January 2020
 *    Email: alsahercoder@gmail.com
 *    Description: Given a singly linked list, determine if it is a palindrome.
 *    Source: https://leetcode.com/problems/palindrome-linked-list/
 *    Approach:
 *          - We need to compare the first half and second half of the linked lists. 
 *          - Count the total number of nodes while simultaneously finding the middle node and tail node of Linked List.
 *          - Reverse the second half of the Linked list using the middle node.
 *          - Now, compare the front pointer and back pointer while traversing through the list moving towards the middle node.
 *          - When, front pointer val is not equal to back pointer, return false.
 *          - else, return true.
 */



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverseLinkedList(struct ListNode *backNode, struct ListNode *currentNode) {
    /* Reverse the second half of the Linked List only */
    
    struct ListNode *backPtr;
    struct ListNode *currentPtr;
    struct ListNode *frontPtr;
    
    backPtr = backNode;
    currentPtr = currentNode;
    frontPtr = NULL;
    
    while(currentPtr != NULL) {
        
        frontPtr = currentPtr -> next;
        currentPtr ->next = backPtr;
        backPtr = currentPtr;
        currentPtr = frontPtr;
        
    }
    backPtr = frontPtr = currentPtr = NULL;
    free(backPtr);
    free(currentPtr);
    free(frontPtr);
}

bool isPalindrome(struct ListNode* head){

    struct ListNode *frontPtr = head;
    struct ListNode *backPtr = NULL;
    
    int totalNodes = 0;
    for(frontPtr = head; frontPtr != NULL; frontPtr = frontPtr -> next) {
        
        totalNodes++;
        backPtr = frontPtr; 
    }

    if(totalNodes == 0 || totalNodes == 1  || head == NULL) 
        return true;
    else if(totalNodes == 2 && head -> val != head -> next -> val)
        return false;
    else if(totalNodes == 2 && head -> val == head -> next -> val)
        return true;

    totalNodes = totalNodes / 2;
    
    frontPtr = head;
    for(int reachMiddle = 0; reachMiddle < totalNodes; reachMiddle++) {
        
        frontPtr = frontPtr -> next;
    }
    
    reverseLinkedList(frontPtr, frontPtr -> next);
    
    frontPtr = head;
    
    while(totalNodes--) {
        
        if(frontPtr -> val == backPtr -> val) {
            
            frontPtr = frontPtr -> next;
            backPtr = backPtr -> next;
        } 
        
        else {
            
            backPtr = NULL;
            frontPtr = NULL;
            free(backPtr);
            free(frontPtr);
            return false;
        }
            
    }
    backPtr = NULL;
    frontPtr = NULL;
    free(backPtr);
    free(frontPtr);
    
    return true;
}
