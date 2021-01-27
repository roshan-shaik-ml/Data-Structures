#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *right;
    struct node *left;
}*root = NULL;

struct QNode {
    
    int data;
    struct node *treeNode;
    struct QNode *next;
}*head = NULL, *tail = NULL, *QPtr = NULL;

struct node *newNode(int payload) {
    
    struct node *newChild = (struct node*)malloc(sizeof(struct node));
    newChild -> data = payload;
    newChild -> left = NULL;
    newChild -> right = NULL;
    
    return newChild;
}

struct QNode *enqueue(int num, struct node *Node) {
    
    /* insert in the end */
    if(Node == NULL)
        return head;
    
    struct QNode *enqueueNode = (struct QNode*)malloc(sizeof(struct QNode));
    enqueueNode -> treeNode = Node;
    enqueueNode -> data = num;
    enqueueNode -> next = NULL;
    
    if(tail == NULL && head == NULL) {
        
        head = enqueueNode;
        tail = enqueueNode;
    }
    
    else {
        
        tail -> next = enqueueNode;
        tail = tail -> next;
    }
    
    return head;
}

struct QNode *dequeue(struct QNode *head) {
    
    /* remove the beginning node */
    struct QNode *ptr = head;
    head = head -> next;
    printf("%d", ptr -> data);
    free(ptr);
    
    return head;    
}

void printLL(struct QNode *head) {
    
    struct QNode *ptr;
    
    for(ptr = head; ptr != NULL; ptr = ptr -> next) {
        
        printf("%d  ", ptr->data);
    }
    printf("\n");
}

void printLevelOrder(struct node *root, struct QNode *head) {

    struct node *parentNode = root;
    enqueue(parentNode -> data, parentNode); 
    printLL(head);
    QPtr = head;
    /* Enqueue my root node */
    
    do {

        head = enqueue(parentNode -> right -> data, parentNode -> right);
        head = enqueue(parentNode -> left -> data, parentNode -> left);
        QPtr = QPtr -> next;
        parentNode = QPtr -> treeNode;
        
        head = dequeue(head);
    } while(head != NULL);
}
int main() {

    root = newNode(1);
    root -> left  = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7); 
    printLevelOrder(root, head);
    return 0;
}
