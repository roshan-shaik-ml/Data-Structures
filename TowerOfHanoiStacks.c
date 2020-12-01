/*
    Author : Shaik Faizan Roshan Ali
    Title : Tricky Tower (CTD Project)
    Date : 30th November 2020
    Contact: alsahercoder@gmail.com
    
    This is the most infamous Tower of Hanoi problem with 3 discs.
*/

/*

    Note : The minimum number of steps to solve 'n' discs TOH is pow(2, n) - 1.
    
    Algorithm for Tower of Hanoi (iterative)
    Step 1: Count the minimum number of moves using the formula (mentioned in note).
    Step 2:    If the number of disks are even exchange the Auxillary and destination peg.
    Step 3: for move = 1 to minimum Moves
            
                if move % 3 == 1:
                    legal move b/w source & destination peg.
                else if move % 3 == 2:
                    legal move b/w source & auxillary peg.
                else if move % 3 == 1:
                    legal move b/w auxillary & destination peg.
                
                [end if conditon]
                
            [end loop] 
    step 4: exit.
    -------------------------------------------------------------------------------------------
        
    Algorithm for Tower of Hanoi (Recursive)
    Step 1 : We need to move n-1 discs to auxillary.
    Step 2 : Move the nth disc to destination peg.
    Step 3 : Now, move the n-1th disc to dest using source as auxillary.
    Step 4 : This process repeats until the 1st disc reaches destination.
    
*/

#include <stdio.h>
#include <math.h>

/* 
        	Global Variables 
        
    Stacks and their respective top declarations.
    Using the pointer we change the top values of three stacks.
*/

int src[3] = {3, 2, 1}, dest[3], aux[3];
int topSrc = 2, topDest = -1, topAux = -1;

int *srcTop, *destTop, *auxTop; 

/* Function for add, delete and move element. */
int delete(int arr[], int *top);
void add(int data, int stack[], int *top);
void move(int stack1[], int *, int stack2[], int *);

int main() {
    
    int discs = 3;
    int totalMoves = pow(2,discs) - 1;
    
    /* Asssign the top values to pointers for updating them regularly. */
    srcTop = &topSrc; 
    destTop = &topDest; 
    auxTop = &topAux;

    for(int mov = 1; mov <= totalMoves; mov++) {
        
        if(mov % 3 == 1) {
            
            move(src, srcTop, dest, destTop);
            printf("Source --> Destination\n\n");
        }
            
        else if(mov % 3 == 2) {
            
            if(mov < 3) {
                
                move(src, srcTop, aux, auxTop);
                printf("Source --> Auxillary\n\n");    
            }
            else {
                
                move(aux, auxTop, src, srcTop);
                printf("Auxillary --> Source\n\n");
            }
            
        }
        
        else if(mov % 3 == 0) {
            
            if(mov == 3) {
                
                move(dest, destTop, aux, auxTop);
                printf("Destination --> Auxillary\n\n");
            }
            else {
                
                move(aux, auxTop, dest, destTop);
                printf("Auxillary --> Destination\n\n");
            }
                        
        }   
    }
    printf("Destination Peg Final Result\n");
    printf("\t%d\n\t%d\n\t%d\n", dest[2], dest[1], dest[0]);
}

void add(int data, int dest[], int *top) {
    
    if(*top == 3)
        printf("Stack Overflow\n");

    else {
        
        *top = *top + 1;
        dest[*top] = data;    
    }    
}

int delete(int arr[], int *top) {
    
    int data;
    if(*top == -1)
        printf("Stack Underflow Error\n");
	
    else {
        
        data = arr[*top];
        *top = *top - 1;
        return data;    
    }
}

void move(int stack1[], int *topStk1, int stack2[], int *topStk2) {
    
    /*
        Deletes an element from stack1 and decrements top values of stack1.
        Using the return data of stack1.
        Now, we move the data to Stack2 and increment top values.
    */
    
    int data = delete(stack1, topStk1);
    add(data, stack2, topStk2);
    
    /* Change in respective stack top values and move instruction. */
    printf("SP1 Top =  %d SP2 Top =  %d SP3 Top = %d\n", *srcTop, *destTop, *auxTop);
    printf("Move disc %d from ", data);
}
