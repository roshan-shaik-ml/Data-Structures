#include <stdio.h>
#include <stdlib.h>

struct ListNode {

    int val;
    struct ListNode *next;
 }*head = NULL, *ptr = NULL;

struct ListNode *createLL(struct ListNode *head) {
    
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    
    while(num != -1) {
        
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode -> val = num;
        if(head == NULL) {
            
            head = newNode;
        }
        
        else {
        
            ptr = head;
            while(ptr -> next = NULL) {
                
                ptr = ptr -> next;
            }
            
            ptr -> next = newNode;
        }
        
        newNode -> next = NULL;
        printf("Enter the number: ");
        scanf("%d", &num);
    }
    return head;
}
struct ListNode* deleteDuplicates(struct ListNode* head){
    
    static int freqMap[201];
    
    while(ptr != NULL) {
        
        freqMap[ptr -> val + 100]++;
        ptr = ptr -> next;
    }
    
    free(ptr);
    struct ListNode *currentPtr = head -> next;
    struct ListNode *prevPtr = head;
    
    while(currentPtr != NULL) {
        
        if(prevPtr == head && freqMap[prevPtr -> val + 100] > 1) {
            
            ptr = head;
            head = head -> next;
            prevPtr = head;
            currentPtr = currentPtr -> next;
            free(ptr);
        }
        
        else if ( freqMap[currentPtr -> val + 100] > 1){
            
            prevPtr -> next = currentPtr -> next;
            ptr = currentPtr;
            currentPtr = currentPtr -> next;
            free(ptr);
        }
        
        else {
            
            prevPtr = prevPtr -> next;
            currentPtr = currentPtr -> next;
        }
    }
    
    ptr = head;
    while(ptr != NULL) {
        
        printf("%d ", ptr -> val);
        ptr = ptr -> next;
    }
    
    return head;
}

int main() {
    
    head = createLL(head);
    head = deleteDuplicates(head);
}
