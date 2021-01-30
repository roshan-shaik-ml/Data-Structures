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

int getChildren(struct treeNode *currentNode) {
    
    int count = 0;
    if(currentNode -> right != NULL)
        count++;
    if(currentNode -> left != NULL)
        count++;
        
    return count;
}

struct treeNode *deleteLeafNode(struct treeNode *parentNode, struct treeNode *toDeleteNode, int payload) {
    
    if(parentNode -> right -> data == payload) {
        
        parentNode -> right = NULL;
        free(toDeleteNode);
    }

    else if(parentNode -> left -> data == payload) {
        
        parentNode -> left = NULL;
        free(toDeleteNode);
    }
    
    return parentNode;
}

struct treeNode *deleteOneChildNode(struct treeNode *toDeleteNode, int payload) {
    
    /* change the data of the to Delete Node with its child Node*/
    
    if(toDeleteNode -> left != NULL) {
        
        toDeleteNode -> data = toDeleteNode -> left -> data;
        toDeleteNode -> left = NULL;
        free(toDeleteNode);
    }    
    
    if(toDeleteNode -> right != NULL) {
        
        toDeleteNode -> data = toDeleteNode -> right -> data;
        toDeleteNode -> right = NULL;
        free(toDeleteNode);
    }
    
    return toDeleteNode;
} 

struct treeNode *deleteTwoChildNode(struct treeNode *parentNode, struct treeNode* toDeleteNode, int payload) {
    
    
    return parentNode;
}
void deleteNode(struct treeNode *root, int payload) {
    
    /*
     *  Case 1: Delete Node at leaf. 
     *    Case 2: Delete Node with One child.
     *    Case 3: Delete Node with two Children.
     */
     
    struct treeNode *parentNode = root;
    struct treeNode *toDeleteNode;
    
    /* toDeleteNode intialization */
    if(payload >= parentNode -> data) {
        
        toDeleteNode = parentNode -> right;
    }
    
    else if (payload < parentNode -> data) {
        
        toDeleteNode = parentNode -> left;
    }
    
    while (toDeleteNode -> data != payload) {

        if(payload < toDeleteNode -> data) {
            
            /* Checking if my next left in not NULL */
            if (toDeleteNode -> left != NULL) {
                        
                parentNode = toDeleteNode;
                toDeleteNode = toDeleteNode -> left;    
            }
            
            else {
                
                printf("Delete node not found at 172\n");
                return;    
            }
        }
        
        else if (payload >= toDeleteNode -> data) {
            
            if (toDeleteNode -> right != NULL) {
                
                parentNode = toDeleteNode;
                toDeleteNode = toDeleteNode -> right;
            }
            
            else {
                
                printf("Delete node not found at 186\n");
                return;
            }
        }
    }
    
    /* The above steps are for traversing to the specified delete Node */
    int children = getChildren(toDeleteNode);
    
    if(children == 0) {
        
        parentNode = deleteLeafNode(parentNode, toDeleteNode, payload);
    }
    
    else if (children == 1) {
        
        toDeleteNode = deleteOneChildNode(toDeleteNode, payload);
    }
    else if (children == 2) {
        
        deleteTwoChildNode(parentNode, toDeleteNode, payload);
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
    
    /* Level 3 */
    struct treeNode *Node7 = addRightChild(Node6, 140);
    
    inOrderTraversal(root);
    deleteNode(root, 130);
    printf("\n");
    inOrderTraversal(root);
    return 0;
}
