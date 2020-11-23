#include <stdio.h>

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
    
    for(int index = top; index >= 0; index--) {
        
        printf("%d\n", stack[index]);
    }
}

int main() {

    push(10);
    push(15);
    push(17);
    pop();
    display();    
}
