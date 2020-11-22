#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *link;
    /*
      Here we are creating a struct member.
      Whose datatype is struct node * and member name is link.
    
    */
};

int main() {
	
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	
	head -> data = 45;
	head -> link = NULL;
	
	printf("%d", head->data);
	return 0;
}
