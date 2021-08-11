#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertStart(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->data = new_data;

  new_node->next = (*head_ref);
  new_node->prev = NULL;

  if ((*head_ref) != NULL)
    (*head_ref)->prev = new_node;

  (*head_ref) = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
  if (prev_node == NULL)
  {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  new_node->data = new_data;

  new_node->next = prev_node->next;

  prev_node->next = new_node;

  new_node->prev = prev_node;

  if (new_node->next != NULL)
    new_node->next->prev = new_node;
}

void insertEnd(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  struct Node *last = *head_ref;

  new_node->data = new_data;

  new_node->next = NULL;

  if (*head_ref == NULL)
  {
    new_node->prev = NULL;
    *head_ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;

  new_node->prev = last;

  return;
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

void deleteNode(struct Node **head_ref, struct Node *del)
{
  if (*head_ref == NULL || del == NULL)
    return;

  if (*head_ref == del)
    *head_ref = del->next;

  if (del->next != NULL)
    del->next->prev = del->prev;

  if (del->prev != NULL)
    del->prev->next = del->next;

  free(del);
}

void deleteNodeAt(struct Node **head_ref, int n)
{
  if (*head_ref == NULL || n <= 0)
    return;

  struct Node *current = *head_ref;
  int i;

  for (int i = 1; current != NULL && i < n; i++)
    current = current->next;

  if (current == NULL)
    return;

  deleteNode(head_ref, current);
}

int main()
{
  struct Node *head = NULL;

  insertEnd(&head, 6);
  insertStart(&head, 7);
  insertStart(&head, 1);
  insertEnd(&head, 4);
  insertAfter(head->next, 8);

  printf("DLL after initializing: ");
  traverseForward(head);

  deleteNode(&head, head);
  printf("DLL after first deletion: ");
  traverseForward(head);
  deleteNodeAt(&head, 2);
  printf("DLL after second deletion: ");
  traverseForward(head);

  return 0;
}
