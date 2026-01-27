#include <stdio.h>

int main() {
    int rows, col, i, j, n;

    printf("ENTER ROWS OF MATRIX: ");
    scanf("%d", &rows);

    printf("ENTER COLUMNS OF MATRIX: ");
    scanf("%d", &col);

    int a[rows][col], b[rows][col], sum[rows][col];

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("CHOOSE:\n1. ADDITION\n2. SUBTRACTION\n");
    printf("ENTER NUMBER");
    scanf("%d", &n);

    switch (n) {
        case 1:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < col; j++) {
                    sum[i][j] = a[i][j] + b[i][j];
                }
            }
            printf("Result (Addition):\n");
            break;

        case 2:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < col; j++) {
                    sum[i][j] = a[i][j] - b[i][j];
                }
            }
            printf("Result (Subtraction):\n");
            break;

        default:
            printf("Invalid choice");
            return 0;
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
