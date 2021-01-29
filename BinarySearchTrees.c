#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    
    int data;
    struct treeNode *left;
    struct treeNode *right;
}*root = NULL;

struct treeNode *addLeftChild(struct treeNode *parentNode, int payload) {
    
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    parentNode -> left = newNode;
    
    /* Check binary search tree condition while adding */
    if(payload < parentNode -> data) 
        newNode -> data = payload;
    else
        printf("Payload value is greater than or equal to parentNode value\n");
        
    newNode -> right = NULL;
    newNode -> left = NULL;
    
    return newNode;
}

struct treeNode *addRightChild(struct treeNode *parentNode, int payload) {
    
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    parentNode -> right = newNode;
    
    if (payload >= parentNode -> data)
        newNode -> data = payload;
    else 
        printf("Payload value is less than parentNode value\n");
        
    newNode -> right = NULL;
    newNode -> left = NULL;
    
    return newNode;
}

void inOrderTraversal(struct treeNode *Node) {
    
    /* IN ORDER TRAVERSAL OF A BINARY SEARCH TREE GIVES SORTED VALUES */
    if (Node == NULL)
        return;
    
    inOrderTraversal(Node -> left);
    printf("%d  ", Node -> data);
    inOrderTraversal(Node -> right);
}

struct treeNode *searchPayload(struct treeNode *Node, int payload) {
    
    struct treeNode *currentNode = Node;
    
    while(currentNode -> data != payload || currentNode != NULL) {
        
        if( payload < currentNode -> data) {
            
            currentNode = currentNode -> left;
        }
        
        else if (payload > currentNode -> data) {
            
            currentNode = currentNode -> right;
        }
    }
}

struct treeNode *createRoot(struct treeNode *root, int payload) {
    
    root = (struct treeNode*)malloc(sizeof(struct treeNode));
    root -> data = payload;
    root -> left = NULL;
    root -> right = NULL;
    
    return root;
}

struct treeNode *deleteNode(struct treeNode *root, int payload) {
    
    struct treeNode *parentNode = root;
    struct treeNode *toDeleteNode;
    
    while (toDeleteNode -> data == payload || toDeleteNode != NULL) {
        
        if(payload < toDeleteNode -> data) {
            
            /* Checking if my next left in not NULL */
            if (toDeleteNode -> left != NULL) {
                        
                parentNode = toDeleteNode;
                toDeleteNode = toDeleteNode -> left;    
            }
            
            else {
                
                printf("Delete node not found\n");    
            }
        }
        
        else {
            
            if (toDeleteNode -> right != NULL) {
                
                parentNode = toDeleteNode;
                toDeleteNode = toDeleteNode -> right;
            }
            
            else {
                
                printf("Delete node not found\n");
            }
        }
        
        /* Delete Node still in progress */
    }
}

int main() {
    
    root = createRoot(root, 100);    
    
    /* Level 1 */
    struct treeNode *Node1 = addLeftChild(root, 80);
    struct treeNode *Node2 = addRightChild(root, 120);
    
    /* Level 2 */
    struct treeNode *Node3 = addLeftChild(Node1, 70);
    struct treeNode *Node4 = addRightChild(Node1, 90);
    
    struct treeNode *Node5 = addLeftChild(Node2, 110);
    struct treeNode *Node6 = addRightChild(Node2, 130);
    
    inOrderTraversal(root);
    return 0;
}
