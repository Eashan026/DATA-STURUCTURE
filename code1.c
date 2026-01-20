#include <stdio.h>
#include <stdlib.h> // For exit(0)

int main() {
    int choice, arr[10], element, n = 0, i, pos; // Initialize n = 0

    while (1) { // Added loop so you can perform multiple operations
        printf("\nCHOOSE:\n");
        printf("1. INSERTION\n");
        printf("2. DELETION\n");
        printf("3. DISPLAYING\n");
        printf("4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n < 10) {
                    printf("Enter element: ");
                    scanf("%d", &element);
                    arr[n] = element; 
                    n++; 
                    printf("Inserted successfully.\n");
                } else {
                    printf("Array is full!\n");
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Array is already empty!\n");
                } else {
                    printf("Enter position to delete (0 to %d): ", n - 1);
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= n) {
                        printf("Invalid position!\n");
                    } else {
                        // Shifting elements to fill the gap
                        for (i = pos; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--; // Reduce count
                        printf("Element deleted.\n");
                    }
                }
                break;

            case 3:
                if (n == 0) {
                    printf("The array is currently empty.\n");
                } else {
                    printf("Elements in the array: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                exit(0); // Closes the program

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
