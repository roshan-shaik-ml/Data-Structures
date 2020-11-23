#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *link;
};

void countOfNodes(struct node *head) {
    
    int count = 0;
    if (head = NULL)
        printf("Linked list is empty");
        
    struct node *ptr = NULL;
    while (ptr != NULL) {
        
        count++;
        ptr = ptr -> link;
    }
    printf("%d", count);
}

int main() {
    
    countOfNodes(head);
    struct node *head = NULL;
    head = (struct node*) malloc(sizeof(struct node));
}
