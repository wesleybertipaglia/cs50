#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full!\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Pushed %d\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Popped %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    push(4);
    push(5);
    push(6); // This will show "Stack is full!"
    display();
    return 0;
}
