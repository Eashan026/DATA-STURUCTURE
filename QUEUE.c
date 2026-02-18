#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int item;

    if (rear == MAX - 1) {
        printf("OVERFLOW! Queue is full.\n");
        return;
    }

    printf("Enter item to insert: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    rear = rear + 1;
    queue[rear] = item;

    printf("Item inserted successfully.\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("UNDERFLOW! Queue is empty.\n");
        return;
    }

    printf("Deleted item: %d\n", queue[front]);
    front = front + 1;

    if (front > rear) {
        front = rear = -1;  // Reset queue
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int num;

    while (1) {
        printf("\nChoose an Option:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
