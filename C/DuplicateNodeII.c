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
    struct ListNode *currentPtr = head;
    struct ListNode *prevPtr = NULL;

    while(currentPtr != NULL) {

        if(currentPtr == head && freqMap[prevPtr -> val + 100] > 1) {

            ptr = head;
            currentPtr = currentPtr -> next;
            head = currentPtr;

            free(ptr);
        }

        else if ( freqMap[currentPtr -> val + 100] > 1 && head != currentPtr){

            prevPtr -> next = currentPtr -> next;
            ptr = currentPtr;
            currentPtr = currentPtr -> next;
            free(ptr);
        }

        else {

            prevPtr = currentPtr;
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
