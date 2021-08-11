#include <stdio.h>
#include <stdlib.h>

#define N 5
int top = -1;
int stack[N];

void push()
{
  int data;
  if (top == N - 1)
  {
    printf("\nStack is full or in overflow condion");
  }
  else
  {
    printf("Enter the element to be insert in stack: ");
    scanf("%d", &data);
    top = top + 1;
    stack[top] = data;
    printf("\nElement inserted in the stack");
  }
}

void pop()
{
  if (top == -1)
  {
    printf("\nStack is empty or stack is underflow state");
  }
  else
  {
    printf("\nremoved item is : %d", stack[top]);
    printf("\npop operation is  successfully ");
    top = top - 1;
  }
}

void display()
{
  if (top == -1)
  {
    printf("\nStack is empty or underflow state");
  }
  else
  {
    printf("\nall elements of stack ");
    for (int i = top; i >= 0; i--)
    {
      printf("\n%d", stack[i]);
    }
  }
}

void full_or_empty()
{
  if (top == -1)
  {
    printf("\nStack is Empty\n");
  }
  else if (top == N - 1)
  {
    printf("\nStack is Full\n");
  }
}

void main()
{
  int option;
  while (1)
  {
    printf("\nChoose option\n 1. Push\n 2. Pop\n 3. Stack full or empty?\n 4. Display\n 5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      full_or_empty();
      break;
    case 4:
      display();
      break;
    case 5:
      exit(1);
    default:
      printf("\ninvalid choice \n");
    }
  }
}