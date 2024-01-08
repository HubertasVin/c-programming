#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x;
    double y;
} Point;

typedef struct Stack
{
    Point *p;
    int size;
} Stack;

double getDistance(Point b);
void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point p);
Point top(Stack *stack);
Point pop(Stack *stack);

int main()
{
    Stack stack;
    Point p1, p2, p3, p4, p5;
    stack.size = 0;
    Point p;

    p1.x = 1.0; p1.y = -2.0;
    p2.x = 2.0; p2.y = 7.0;
    p3.x = 3.0; p3.y = -12.0;
    p4.x = 4.0; p4.y = 3.0;
    p5.x = 5.0; p5.y = 8.0;
    initStack(&stack);
    push(&stack, p1);
    push(&stack, p2);
    push(&stack, p3);
    push(&stack, p4);
    push(&stack, p5);
    printStack(&stack);

    return 0;
}

void a(char A[], char b, long c)
{

}

void initStack(Stack *stack)
{
    (*stack).p = malloc((sizeof(Point) * (*stack).size));
    for (int i = 0; i < (*stack).size; ++i)
    {
        (*stack).p[i].x = 0.0;
        (*stack).p[i].y = 0.0;
    }
}

void printStack(Stack *stack)
{
    for (int i = 0; i < (*stack).size; ++i)
    {
        printf("X: %.2lf Y: %.2lf\nDistance to (0, 0) = %.2lf\n\n", (*stack).p[i].x, (*stack).p[i].y, getDistance((*stack).p[i]));
    }
}

int getStackSize(Stack *stack)
{
    return (*stack).size;
}

void push(Stack *stack, Point p)
{
    (*stack).p = realloc((*stack).p, ((*stack).size * sizeof(Point)) + sizeof(Point));
    (*stack).p[(*stack).size].x = p.x;
    (*stack).p[(*stack).size].y = p.y;
    ++(*stack).size;
}

Point top(Stack *stack)
{
    Point failedP;
    failedP.x = 0.0;
    failedP.y = 0.0;

    if ((*stack).size != 0)
    {
        return (*stack).p[(*stack).size - 1];
    }
    else
    {
        return failedP;
    }
}

Point pop(Stack *stack)
{
    Point result;
    result.x = 0.0;
    result.y = 0.0;

    if ((*stack).size != 0)
    {
        result = top(stack);
        --(*stack).size;
    }

    return result;
}

double getDistance(Point b)
{
    return sqrt(pow(b.x-0, 2.0) + pow(b.y-0, 2.0));
}