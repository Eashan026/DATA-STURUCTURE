#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void insert(int item)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->info = item;
    newnode->prev = NULL;
    newnode->next = start;

    if (start != NULL)
    {
        start->prev = newnode;
    }

    start = newnode;

    printf("Item inserted\n");
}

void delete_node()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("Underflow\n");
        return;
    }

    temp = start;
    start = start->next;

    if (start != NULL)
    {
        start->prev = NULL;
    }

    printf("Deleted item: %d\n", temp->info);

    free(temp);
}

void display()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = start;

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            insert(item);
            break;

        case 2:
            delete_node();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
