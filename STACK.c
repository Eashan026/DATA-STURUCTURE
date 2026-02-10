
#include <stdio.h>
#include <stdlib.h>

void main() {
    int option, num, top = -1, value, n = 10, stack[10];
    int i;

    while (1) {
        printf("\nCHOOSE WHAT TO DO \n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");

        scanf("%d", &option);

        switch (option) {

            case 1:
                printf("enter the value: ");
                scanf("%d", &value);

                if (top == n - 1) {
                    printf("stack overflow\n");
                } else {
                    top++;
                    stack[top] = value;
                    printf("%d pushed into stack\n", value);
                }
                break;

            case 2:
                if (top == -1) {
                    printf("stack underflow\n");
                } else {
                    printf("%d popped out from stack\n", stack[top]);
                    top--;
                }
                break;

            case 3:
                if (top == -1) {
                    printf("stack is empty\n");
                } else {
                    printf("stack elements are:\n");
                    for (i = top; i >= 0; i--) {
                        printf("%d\n", stack[i]);
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("invalid choice\n");
        }
    }
}
