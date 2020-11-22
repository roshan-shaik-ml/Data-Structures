/*
  create a linked list, 

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *link;
};

int main() {
	
	  struct node *head = (struct node *)malloc(sizeof(struct node));
	  head -> data = 45;
	  head -> link = NULL;
	
	  struct node *current = (struct node *)malloc(sizeof(struct node));
	  current -> data = 95;
	  current -> link = NULL;
	  head -> link = current;
	
    current = (struct node *)malloc(sizeof(struct node));
    current -> data = 30;
    current -> link = null;
    head -> link -> link = current;
    
    /*
        (head)[null | addr1]->[data1 | addr2] -> [data2 | addr3] -> [data3 | null];
        head -> link -> link gives us data2;
    */
	
	return 0;
}
