#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    
    char dir[100];
    struct node *next;
}*head = NULL, *ptr, *tail = NULL;

struct node *deleteBegLL(struct node *head) {
    
    if(head == NULL)
        return head;
        
    else {
        
        struct node *ptr;
        ptr = head;
        head = head -> next;
        free(ptr);
    }
    return head;    
}

struct node *insertBegLL(struct node *head, char *directory) {
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode -> dir, directory);
    
    if(head == NULL) {
        
        head = newNode;
        newNode -> next = NULL;
        tail = newNode;
    }
    
    else {
        
        newNode -> next = head;
        head = newNode;
    }
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

struct node *displayPathLL(struct node *head) {
    
    struct node *ptr;
    printf("/");
    for(ptr = head; ptr != NULL; ptr = ptr -> next ) {
        
        printf("%s/", ptr -> dir);
    }
    printf("\n");
}

void getPath(struct node* head, char string[]) {
    
    static char *temp;
    temp = (char *)malloc(100 * sizeof(char));
    
    for(int index = 1, tempIndex = 0; index < strlen(string); index++, tempIndex++) {
        
        if(string[index] != '/') {
            
            *(temp + tempIndex) = string[index];
        }
        
        else{
            
            if(strcmp(temp, "..") == 0) {
                
                head = deleteBegLL(head);
            }
            
            else if (strcmp(temp, ".") == 0) {
                
                continue;
            }
            
            else {
                
                head = insertBegLL(head, temp);
                free(temp);
                head = displayPathLL(head);
            }
            
            tempIndex = 0;
            index++;
        }
    }
    head = reverseLL(head);
    head = displayPathLL(head);
}

int main() {
    
    char string[1000];
    scanf("%s", string);
    getPath(head, string);
    return 0;
}
