#include <stdio.h>
#include <string.h>

/* Stack variable declaration */
char string[10000];
int maxSize = 10000;
int top = -1;

void push(char ch) {
    
    if(top == maxSize) {
        
        printf("Stack Overflow\n");
    }
    
    else {
        
        top++;
        string[top] = ch;
    }
}

void pop() {
    
    if(top == -1) {
        
        printf("Stack Underflow\n");
    }
    
    else {
        
        top--;
    }
}

char peek() {
    
    return string[top];
}

char getCheckFor() {
    
    char ch = peek();
    char checkFor = '0';
    
    if(ch == '{') 
        checkFor = '}';
        
    else if(ch == '(') 
        checkFor = ')';
    
    else if(ch == '[') 
        checkFor = ']';
        
    return checkFor;
}

void checkParentheses(char string[]) {
    
    int stringLength = strlen(string);
    char checkFor = '0'; /* Random intialization */
    for(int index = 0; index < stringLength; index++) {
        
        if(string[index] == '(') {
            
            checkFor = ')';
            push('(');    
        }
        
        else if (string[index] == '{') {
            
            checkFor = '}';
            push('{');    
        }
        
        else if (string[index] == '[') {
            
            checkFor = ']';
            push('[');
        }
        
        else {
            
            if ( string[index] == ')' && checkFor == ')') {
                
                pop();
                checkFor = getCheckFor();
            }
            
            else if ( string[index] == '}' && checkFor == '}') {
                
                pop();
                checkFor = getCheckFor();
            }
            
            else if ( string[index] == ']' && checkFor == ']') {
                
                pop();
                checkFor = getCheckFor();
            }
        }    
    }
    
    if(top == -1) {
        
        printf("true");
    }
    
    else {
        
        printf("false");
    }
}

int main() {

    char str[10000];
    scanf("%s", str);
        
    checkParentheses(str);
}
