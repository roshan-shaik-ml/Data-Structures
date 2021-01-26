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
}*head = NULL, *tail = NULL;

void enqueue(int num, struct node *Node) {
	
	/* insert in the end */
	struct QNode *enqueueNode = (struct QNode*)malloc(sizeof(struct QNode));
	enqueueNode -> treeNode = Node;
	enqueueNode -> data = num;
	enqueueNode -> next = NULL;
	if(tail == NULL && head == NULL) {
		
		head = enqueueNode;
		tail = enqueueNode;
		return;
	}
	
	else {
		
		tail -> next = enqueueNode;
		tail = tail -> next;	
	}
}

void dequeue(struct QNode *head) {
	
	/* remove the beginning node */
	struct QNode *ptr = head;
	head = ptr -> next;
	free(ptr);	
}

void printLevelOrder(struct node *root) {
	
	int flag = 0;
	struct QNode *parentNode = root;
	
	while(head != NULL && flag != 1) {
		
		flag = 1; /* To avoid the intial state of queue */
		enqueue(ptr -> data, ptr); 
		enqueue(ptr -> right -> data, ptr -> right);
		enqueue(ptr -> left -> data, ptr -> left);
		dequeue(head);
	}
}
int main() {
	
	return 0;
}
