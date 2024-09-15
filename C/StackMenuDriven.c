  
#include <stdio.h>
#include <stdlib.h>

int maxSize = 7;
int top = -1;
int stack[7];

int push(int data) {

    if(top == maxSize) {
        
        printf("StackOverflow\n");
    }
    else {
        
        top++;
        stack[top] = data;
    }
    
}

int pop() {
    
    int data;
    if(top == -1) {
           
           printf("Stack Underflow\n");
    }
   
    else {
        
        data = stack[top];
        top--;
        return data;
    }
    
}

int peek() {
    
    return stack[top];
}

int display() {
    
    printf("\nElement in the Queue");
    for(int index = top; index >= 0; index--) {
        
        printf("%d\n", stack[index]);
    }
}

int main() {

    int operation = 0;

    
    int temp = 0;
    do {
        
        printf("Enter your option for the Queue\n");
        printf(" 1. push \n 2. Push \n 3. Display\n 4. Exit\n");
        scanf("%d", &operation);
    
        switch(operation) {
        
            case 1 :    printf("please enter enqueue data\n");
                        scanf("%d", &temp); 
                        push(temp); break;
            case 2 :    pop(); break;
            case 3 :    display(); break;
            case 4 :    exit(0);break;
            default :   break;
            
        }
    } while(1);
}
