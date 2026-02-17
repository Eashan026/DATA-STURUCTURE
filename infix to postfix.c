#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char item) {
  
        stack[++top] = item;
}


char pop() {
    stack[top--];
}

// Function to check precedence
int precedence(char symbol) {
    if (symbol == '+' || symbol == '-')
        return 1;
    if (symbol == '*' || symbol == '/')
        return 2;
    if (symbol == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char symbol;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        
        else if (symbol == '(') {
            push(symbol);
        }
        
        else if (symbol == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
        
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

