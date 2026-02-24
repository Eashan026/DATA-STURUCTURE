#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;


void push(int item) {
    stack[++top] = item;
}
int pop() {
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int i, result;
    char symbol;
    
    for (i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];
        
       
        if (isdigit(symbol)) {
            push(symbol - '0');  // Convert char to int
        }
        else {
            int operand2 = pop();
            int operand1 = pop();
            
            switch (symbol) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '^':
                    {
                        int power = 1;
                        for (int k = 0; k < operand2; k++) {
                            power *= operand1;
                        }
                        push(power);
                    }
                    break;
            }
        }
    }
    return stack[top];
}

int main() {
    char postfix[MAX];
    
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}
