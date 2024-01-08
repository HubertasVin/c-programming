#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Function to insert a node at the beginning of the list */
int insert(int data, struct node **head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Nepavyko alokuoti atminties\n");
        return -1;
    }
    else
    {
        temp->data = data;
        temp->next = *head;
        *head = temp;
        return 0;
    }
}

/* Function to search for a node with given data */
int removeNode(int data, struct node **head)
{
    struct node *temp = *head;
    struct node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            // Element found, remove it from the list
            if (prev != NULL)
            {
                // Element is not at the head of the list
                prev->next = temp->next;
            }
            else
            {
                // Element is at the head of the list
                *head = temp->next;
            }
            free(temp);
            /* printf("The element with value %d was removed from the list.\n", data); */
            return 0;
        }
        prev = temp;
        temp = temp->next;
    }
    /* printf("The element with value %d does not exist in the list.\n", data); */
    return -1; /* 22 - Invalid argument */
}

int deleteList(struct node **head)
{
    if (*head == NULL)
    {
        return -1; // Return error code
    }

    struct node *temp = *head;

    while (temp != NULL)
    {
        struct node *current = temp;
        temp = temp->next;
        free(current);
    }
    *head = NULL;
    return 0;
}

void printList(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
