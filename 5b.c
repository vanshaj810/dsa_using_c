#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top;

void push()
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  printf("ENTER ELEMENT : ");
  scanf("%d", &new->data);
  new->next = top;
  top = new;
}

void pop()
{
  struct node *new;
  if (top == NULL)
  {
    printf("\nStack Underflow\n");
    exit(1);
  }
  else
  {
    new = top;
    top = top->next;
    new->next = NULL;
    free(new);
  }
}

void is_empty()
{
  struct node *new;

  if (top == NULL)
  {
    printf("\nStack is empty\n");
  }
  else
  {
    printf("\nNot empty\n");
  }
}

void display()
{
  struct node *new;
  if (top == NULL)
  {
    printf("\nStack is empty\n");
    exit(1);
  }
  else
  {
    new = top;
    printf("ELEMENTS ARE :\n");
    while (new != NULL)
    {
      printf("%d\n", new->data);
      new = new->next;
    }
    printf("TOP : %d\n", top->data);
  }
}

int main()
{
  int ch;
  while (1)
  {
    printf("1. PUSH\n2. POP\n3. DISPLAY\n4. IS Empty?\n5. EXIT\nENTER YOUR CHOICE:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
      push();
      break;
    }
    case 2:
    {
      pop();
      break;
    }
    case 3:
    {
      display();
      break;
    }
    case 4:
    {
      is_empty();
      break;
    }
    case 5:
    {
      exit(0);
    }
    default:
    {
      printf("WRONG CHOICE \n");
    }
    }
  }
}