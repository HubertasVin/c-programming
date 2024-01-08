#ifndef LIST_H
#define LIST_H

struct node {
    int data;
    struct node *next;
};

int insert(int data, struct node **head);
int removeNode(int data, struct node **head);
int deleteList(struct node **head);
void printList(struct node *head);

#endif