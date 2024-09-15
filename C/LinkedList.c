#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *createLL(struct node *start) {
    
    int num;
    printf("Enter the data for LL:\n");
    scanf("%d", &num);

    while( num != -1) {
        
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        struct node *ptr;
        newNode->data = num;
        
        if( start == NULL) {
            
            /* First node is created now */
            newNode -> next = NULL;
            start = newNode;
        }
        
        else {
            
            /* We are adding new node at the end of the list */
            ptr = start;
            /* While loop breaks when the pointer reaches last node whose next value is NULL */
            while( ptr->next != NULL) {
                
                ptr = ptr -> next;
            }
            ptr -> next = newNode;
            newNode -> next = NULL;
        }
        printf("Enter the next number\n");
        scanf("%d", &num);
    }    
    return start;
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

struct node *countNodeLL(struct node *start) {
    
    struct node *ptr;
    ptr = start;
    int count = 0;
    
    while(ptr != NULL) {
        
        count++;
        ptr = ptr -> next;    
    }
    printf("Total Number of nodes %d", count);
    return start;
}

struct node *deleteStart(struct node *start) {
    
    struct node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
        
}

struct node *deleteEnd(struct node *start) {
    
    struct node *ptr1;
    struct node *ptr2;
    ptr1 = start;
    
    for(ptr1 = start; ptr1 -> next != NULL; ptr1 = ptr1 -> next) {
        
        ptr2 = ptr1;
    }
    ptr2->next = NULL;
    free(ptr1);
    return start;
}

int main() {
    
    int option;
    
    do {
        
        printf("\n\n *****MAIN MENU *****");
         printf("\n 1. Create a list\n");
         printf("\n 2. Display the Linked List\n");
         printf("\n 3. Count the nodes Linked List\n");
         printf("\n 4. Delete node at Beginning of Linked List\n");
         printf("\n 5. Delete node at End of Linked List\n\n")
         printf("Please enter your option: ");

         scanf("%d", &option);
         
         switch(option) {
        
            case 1: start = createLL(start); break;
            case 2: start = displayLL(start); break;
            case 3: start = countNodeLL(start); break;
            case 4: start = deleteStart(start); break;
            case 5: start = deleteEnd(start); break;
        }
        
    }while (option != 6);
}
