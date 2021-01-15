/*
 *  Name: Two Stack in single array.
 *  Email: alsahercoder@gmail.com 
 *  Author: shaik Faizan Roshan Ali
 *  Date: 15-01-21 
 *  Description: Manage two stack in one Array. 
 *  
 *  Approach :
 *      - Stack One top is assigned to start index of array.
 *      - Stack two top is assigned to end index of array.
 *      - Push element in stack One is as usual.
 *      - Push element in stack Two is done in reverse.
 *      - At any point stack one top value shouldn't cross stack two top.
*/

#include <stdio.h>

int size = 10;
int arr[10];
int top1 = -1;
int top2 = 10;

void pushStackOne(int num) {
    
    if(top1 + 1 >= top2) {
        
        printf("Stack One Overflow\n");
    }
    
    else {
        
        top1++;
        arr[top1] = num;
        printf("Pushed %d in Stack One\n", num);
    }
}

void pushStackTwo(int num) {
    
    if(top2 - 1 <= top1) {
        
        printf("Stack two Overflow\n");
    }    
    
    else {
        
        top2--;
        arr[top2] = num;
        printf("Pushed %d in Stack Two\n", num);
    }    
}

void popStackOne() {
    
    if(top1 == -1) {
        
        printf("Stack One underflow\n");
    }
    
    else {
        
        printf("Poped the number %d\n", arr[top1]);
        top1--;
    }
}

void popStackTwo() {
    
    if(top2 == size) {
        
        printf("Stack Two underflow\n");
    }
    
    else {
        
        printf("Poped the number %d\n", arr[top2]);
        top2++;
    }
}

void peekOne() {
    
    printf("%d\n", arr[top1]);
}

void peekTwo() {
    
    printf("%d\n", arr[top2]);
}

int main() {
    
    while (1) {
        
        printf("********MENU*********\n");
        printf("1. Push Stack One\n2. Push Stack Two\n");
        printf("3. Pop Stack One\n4. Pop Stack two\n");
        printf("5. Peek Stack One\n6. Peek Stack Two\n7. Exit\n");
        printf("Enter the number: ");
        int op;
        scanf("%d", &op);
        
        if(op == 1 || op == 2) {
            
            int num;
            printf("Enter the number: ");
            scanf("%d", &num);
            
            if(op == 1) {
                
                pushStackOne(num);
            }
            
            else {
                
                pushStackTwo(num);
            }    
        }
        
        else if (op == 3) 
            popStackOne();
        
        else if (op == 4) 
            popStackTwo();
        
        else if (op == 5)
            peekOne();
        
        else if (op == 6) 
            peekTwo();
            
        else
            break;
    }
        
    return 0;
}
