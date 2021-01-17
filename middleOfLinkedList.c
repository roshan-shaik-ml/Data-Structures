/*
 *    Author: Shaik Faizan Roshan Ali
 *    Date: 17th January 2020
 *    Email: alsahercoder@gmail.com
 *    Description: Return the middle node of a Linked List.
 *    Source: https://leetcode.com/problems/middle-of-the-linked-list/
 *    Approach:
 *          - Count the totalNodes
 *          - Traverse a pointer to middle node of the linked list. 
 *          - In case the number is even, return the second node of the middle two nodes.
 *          - else, return the middle nodes.
 *
 */
struct ListNode* middleNode(struct ListNode* head){
    
    struct ListNode *ptr = head;
    int count = 0;
    int nodeIs = 0;
    
    while(ptr -> next != NULL) {
        
        count++;
        ptr = ptr -> next;
    }
    
    if (count % 2 == 0) {
        
        nodeIs = count / 2;
    }
    
    else {
        
        nodeIs = count / 2 + 1;
    }
    
    ptr = head;
    count = 0;
    while(count != nodeIs) {
        
        count++;
        ptr = ptr -> next;
    }
    
    return ptr;
}
