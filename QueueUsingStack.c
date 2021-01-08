/*
    Name: Shaik Faizan Roshan Ali
    Date: 8th December 2021
    Email: alsahercoder@gmail.com
    
    This program is an implementation of Queue functions using Stack operations with two arrays.
*/

#include <stdio.h>

int maxSize = 10;
int arr[10], arr1[10];
int top = -1, top1 = -1;

/* top pointers for changing the top values as Global Variable */

int *topPtr, *topPtr1;
int chooseStack = 0;

void push(int num, int arr[], int *topPointer) {
    
    if(*topPointer == maxSize) {
        
        printf("Stack Overflow Error\n");
    }
    
    else {
        
        *topPointer = *topPointer + 1;
        arr[*topPointer] = num;
    }
}

int pop(int array[], int *topPointer) {
    
    int num = array[*topPointer];
    
    if(*topPointer < 0) {
        
        printf("Stack Underflow Error\n");
    }
    
    else {
        
        *topPointer = *topPointer - 1;
        return num;
    }
}


void printStack(int arr[], int *topPointer) {
    
    for(int index = *topPointer; index >= 0; index--) {
        
        printf("%d  ", arr[index]);
    }
    printf("\n\n");
}

void reverseStack(int arr[], int *topPtr) {
    
    for(int indexFront = 0, indexBack = *topPtr; indexFront < indexBack; indexFront++, indexBack--) {
        
        int temp = arr[indexFront];
        arr[indexFront] = arr[indexBack];
        arr[indexBack] = temp;
    }
}
int main() {
    
    int op;
    topPtr = &top;
    topPtr1 = &top1;
    
    do {
        
        printf("1. Enqueue\n2. Dequeue\n3. PrintStack\n 4.Exit\n");
        scanf("%d", &op);
        
        if(op == 1) {
            
            int data;
            printf("Enter the number: ");
            scanf("%d", &data);
            if(chooseStack == 0) {
                
                push(data, arr, topPtr);
            }
            
            else {
                
                push(data, arr1, topPtr1);
            }
        }
        
        else if (op == 2) {
            
            if(chooseStack == 0) {

                for(int transfers = *topPtr; transfers > 0; transfers--) {

                    int num = pop(arr, topPtr);
                    push(num, arr1, topPtr1);
                }
                printf("dequeue %d\n", arr[*topPtr]);
                pop(arr, topPtr);
                
                reverseStack(arr1, topPtr1);
                chooseStack = 1;
            }
            
            else if (chooseStack == 1) {
                
                for(int transfers = *topPtr1; transfers > 0; transfers--) {
                    
                    int num = pop(arr1, topPtr1);
                    push(num, arr, topPtr);
                }
                
                reverseStack(arr, topPtr);
                chooseStack = 0;
            }
        }
          
        else if (op == 3) {
            
            printf("Choose Stack %d\n\n", chooseStack);
            if(chooseStack == 0) {
                
                printStack(arr, topPtr);
            }
            
            else if(chooseStack == 1) {
                
                printStack(arr1, topPtr1);
            }
        }    
        
        else {
          
            break;
        }
    } while(1);
}
