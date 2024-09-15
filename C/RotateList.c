/*
 *    Author: Shaik Faizan Roshan Ali
 *    Date: 17th January 2020
 *    Email: alsahercoder@gmail.com
 *    Description: Rotate a linked list to the right by K places.
 *    Source: https://leetcode.com/problems/rotate-list/
 *    Approach:
 *          - Count the totalNodes and change the linked list to circular linked list.
 *          - Traverse a pointer to the (K + 1)th node from the end of the list.
 *          - Change the head to pointer's next node.
 *          - Now, finally change the pointer's next to NULL, to open the circular linked list.
 *
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
    
    if(head == NULL) {
        
        return head;
    }
    
    struct ListNode *ptr = head;
    int totalNodes = 0;
    int reachNode = 0;
 
    while(ptr -> next != NULL) {
        
        ptr = ptr -> next;
        totalNodes++;
    }
    totalNodes++; 
    /* Counting includes the last node */    
    
    /* Cases where the list doesn't need to rotate */
    if (k == totalNodes || k == 0 || totalNodes == 1) {
        
        return head;
    }
    
    else {
        
        k = k % totalNodes;
        reachNode = totalNodes - k - 1; 
    }
    
    if(totalNodes != 1) {
        
        ptr -> next = head;
        /* It is a circular linked list */
    }
    ptr = head;
    
    while(reachNode--) {
        
        ptr = ptr -> next;
    }
    head = ptr -> next;
    ptr -> next = NULL;
    free(ptr);
    
    return head;
}
