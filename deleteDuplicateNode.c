#include <stdio.h>
#include <stdlib.h> 

struct node {
	
	int data;
	struct node *next;
}*head = NULL, *ptr = NULL;

struct node *createLL(struct node *head) {
	
	int num;
	printf("Enter the number: ");
	scanf("%d", &num);
	
	while(num != -1) {
		
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		newNode -> data = num;
		
		if(head == NULL) {
			
			head = newNode;
		}
		
		else {
			
			for(ptr = head; ptr -> next != NULL; ptr = ptr -> next);
			ptr -> next = newNode;

		}
		newNode -> next = NULL;
		printf("Enter the number: ");
		scanf("%d", &num);
	}
	
	return head;
}

struct node *printLL(struct node *head) {
	
	for(ptr = head; ptr != NULL; ptr = ptr -> next) {
		
		printf("%d  ", ptr -> data);
	}
	printf("\n");
	return head;
}

struct node *deleteNextNode(struct node *nodePtr) {
	
	/* Uses only current pointer as input */
	struct node *ptr = nodePtr -> next;
	
	if(nodePtr -> next != NULL) {
		
		nodePtr -> next = nodePtr -> next -> next;
	}
	
	free(ptr);
	return nodePtr;
}

struct node *deleteCurrentNode(struct node *backNode, struct node *currentNode, struct node *frontNode) {
	
	struct node *ptr = currentNode;
	if(backNode == NULL && currentNode == head) {

		currentNode = currentNode -> next;
		head = currentNode;
		free(currentNode);
	}
	
	else {
		
		backNode -> next = currentNode -> next;
		currentNode = currentNode -> next;
		free(ptr);	
	}

	return currentNode;
}

struct node *deleteDuplicates(struct node *head) {
	
	struct node *currentNode = head;
	struct node *frontNode = NULL;
	struct node *backNode = NULL;
	int deleteCurrentFlag = 0;
	
	if (head != NULL) 
		frontNode = head -> next;
	
	while(currentNode -> next != NULL) {
		
		if(currentNode -> data == frontNode -> data) {

			frontNode = frontNode -> next;
			/* front node is incremented as next node is deleted */
      
			currentNode = deleteNextNode(currentNode);
			/* returns current node after change its next value */
      
			deleteCurrentFlag = 1;
		}
		
		else {
			
			if(deleteCurrentFlag == 1) {
			
				currentNode = deleteCurrentNode(backNode, currentNode, frontNode);
				frontNode = frontNode -> next;
				deleteCurrentFlag = 0;
			}
			
			else {
				
				currentNode = currentNode -> next;
				frontNode = frontNode -> next;
				
				if(backNode == NULL && currentNode != head) 
					backNode = head;
				else
					backNode = backNode -> next;		
			}
		}
	}	

	return head;
} 

int main() {
	
	head = createLL(head);
	head = printLL(head);
	head = deleteDuplicates(head);
	head = printLL(head);
	return 0;
}
