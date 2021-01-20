  
/*
 *    Author: Shaik Faizan Roshan Ali
 *    Date: 20th January 2020
 *    Email: alsahercoder@gmail.com
 *    Description: Delete a node in a Linked list (guaranteed not at the end), access to the head is restricted.
 *    Source: https://leetcode.com/problems/delete-node-in-a-linked-list/
 *    Approach:
 *          - We need two pointer (backPtr and frontPtr). Back Pointer at the given node and front pointer to its subsequent node.
 *          - We copy the next -> node val to the current node -> val.
 *          - The above step is repeated until the front pointer reaches the final node.
 *          - Once it is done, we do a final copy and change the back pointer's next value to NULL & free the front pointer's memory.
 */
 
 /*
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     struct ListNode *next;
  * };
  */
void deleteNode(struct ListNode* node) {
    
    struct ListNode *frontPtr = node -> next;
    struct ListNode *backPtr = node;
    
    for(;frontPtr -> next != NULL; 
                    frontPtr = frontPtr -> next, backPtr = backPtr -> next) {
        
        backPtr -> val = frontPtr -> val;
    }
    backPtr -> val = frontPtr -> val;
    backPtr -> next = NULL;
    backPtr = backPtr -> next;
    free(frontPtr); 
    free(backPtr);
}
