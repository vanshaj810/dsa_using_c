#include "stdio.h"
#include "stdlib.h"

struct Node
{
  int data;
  struct Node *next;
};
struct Node *front, *rear;

void enqueue(int x)
{
  struct Node *temp;

  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;

  if (front == NULL && rear == NULL)
  {
    front = rear = temp;
    return;
  }
  rear->next = temp;
  rear = temp;
}

void dequeue()
{
  struct Node *temp = front;

  if (front == NULL)
  {
    printf("Error : QUEUE is empty!!");
    return;
  }
  if (front == rear)
    front = rear = NULL;

  else
    front = front->next;

  free(temp);
}

void traverseForward(struct Node *node)
{
  struct Node *last;
  while (node != NULL)
  {
    printf(" %d ", node->data);
    last = node;
    node = node->next;
  }
  printf("\n");
}

int main()
{
  front = NULL;
  rear = NULL;

  enqueue(2);
  printf("\nenqueue 2: ");
  traverseForward(front);
  enqueue(3);
  printf("\nenqueue 3: ");
  traverseForward(front);
  enqueue(5);
  printf("\nenqueue 5: ");
  traverseForward(front);
  dequeue();
  dequeue();
  printf("\nqueue after 2 dequeue: ");
  traverseForward(front);
  printf("\n");
}