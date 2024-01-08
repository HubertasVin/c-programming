#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main()
{
    Stack stack;
    stack.size = 10;

    initStack(&stack);
    printStack(&stack);
    printf("%d\n", getStackSize(&stack));
    push(&stack, 11);
    push(&stack, 12);
    printStack(&stack);
    printf("%d\n", top(&stack));
    printf("%d\n", pop(&stack));
    printStack(&stack);
    destroyStack(&stack);

    return 0;
}

void initStack(Stack *stack)
{
    (*stack).arr = malloc((sizeof(int) * (*stack).size));
    for (int i = 0; i < (*stack).size; ++i)
    {
        (*stack).arr[i] = 0;
    }
}

void printStack(Stack *stack)
{
    for (int i = 0; i < (*stack).size; ++i)
    {
        printf("%d ", (*stack).arr[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack)
{
    return (*stack).size;
}

void push(Stack *stack, int value)
{
    (*stack).arr = realloc((*stack).arr, ((*stack).size * sizeof(int)) + sizeof(int));
    (*stack).arr[(*stack).size] = value;
    ++(*stack).size;
}

int top(Stack *stack)
{
    if ((*stack).size != 0)
    {
        return (*stack).arr[(*stack).size - 1];
    }
    else
    {
        return 0;
    }
}

int pop(Stack *stack)
{
    int result = 0;
    if ((*stack).size != 0)
    {
        result = top(stack);
        --(*stack).size;
    }

    return result;
}

void destroyStack(Stack *stack)
{
    free((*stack).arr);
    (*stack).size = 0;
}