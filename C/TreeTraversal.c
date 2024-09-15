/*
 *    Author: Shaik Faizan Roshan Ali
 *    Date: 18th January 2020
 *    Email: alsahercoder@gmail.com
 *    Description: Tree Traversal method implementation in C.
 */

#include <stdio.h>
#include <malloc.h>

struct node {
    
    struct node *left;
    int data;
    struct node *right;
} *root = NULL;

struct node *newNode(int payload) {
    
    struct node *newChild = (struct node *)malloc(sizeof(struct node));
    
    newChild -> data = payload;
    newChild -> right = NULL;
    newChild -> left = NULL;
    
    return newChild;
}

void preOrderTraverse(struct node *node) {
    
    /*
     *  Approach:
     *        1. Print the current node.
     *        2. Recurse on the left.
     *        3. Recurse on the right.
     */
    if(node == NULL)
        return;
        
    printf("%d ", node -> data);
    
    preOrderTraverse(node -> left);
    preOrderTraverse(node -> right);
}
void postOrderTraverse(struct node *node) {
    
    /*
     *  Approach:
     *        1. Recurse on the left.
     *        2. Recurse on the right.
     *        3. Print the current node.
     */
    if(node == NULL)
        return;
    postOrderTraverse(node -> left);
    postOrderTraverse(node -> right);
    
    printf("%d ", node -> data);
}

void inOrderTraverse(struct node *node) {
    
    /*
     *  Approach:
     *        1. Recurse on the left.
     *        2. Print the current node.
     *        3. Recurse on the right.
     */
    if(node == NULL) 
        return;
        
    inOrderTraverse(node -> left);
    
    printf("%d ", node -> data);
    
    inOrderTraverse(node -> right);
}
int main() {
    
    root = newNode(1);
    root -> left  = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7); 
    
    
    printf("Pre Order Traverse in binary tree: \n");
    preOrderTraverse(root);
    
    printf("\nPost Order Traverse in binary tree: \n");
    postOrderTraverse(root);
    
    printf("\nIn Order Traverse in binary tree: \n");
    preOrderTraverse(root);
    return 0;    
}
