/* createChild, searchChild, deleteChild */
#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data;
	struct node *nextSibling;
	struct node *nextChild;
}*root = NULL, *ptr = NULL;

struct node *createChild(struct node *parentNode, int payload) {
	
	/* Insert it as newNode at the head in LL */
	
	struct node *newChild = (struct node *)malloc(sizeof(struct node));
	newChild -> data = payload;
	
	newChild -> nextSibling = parentNode -> nextChild;
	parentNode -> nextChild = newChild;
	newChild -> nextChild = NULL; 
	
	return newChild;
}

struct node *searchChild(struct node *parentNode, int searchValue) {

	for(ptr = parentNode -> nextChild; ptr != NULL; ptr = ptr -> nextSibling) {
		
		if(ptr -> data == searchValue) 
			break;
		
		else 
			continue;
	}
	
	return ptr;
}

void deleteChild(struct node *parentNode, int deleteValue) {
	
	for(ptr = parentNode -> nextChild; ptr != NULL; ptr = ptr -> nextSibling) {
		
		if(ptr -> nextSibling -> data == deleteValue) 
			break;
	}
	
	struct node *deleteNode = ptr -> nextSibling;
	ptr -> nextSibling = deleteNode -> nextSibling;
	free(deleteNode);
}

void addSibling(struct node *broNode, int siblingData) {
	
	struct node *siblingNode = (struct node*)malloc(sizeof(struct node));
	broNode -> nextSibling = siblingNode;
	siblingNode -> data = siblingData;
	siblingNode -> nextSibling = NULL;
}

int main() {
	
	
	return 0;
}
