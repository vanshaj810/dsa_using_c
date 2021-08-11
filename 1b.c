#include <stdio.h>
#include <stdlib.h>

void traverseElement(int arr[], int *ptr)
{
  int n = *ptr;

  printf("\nArray Traversal: ");

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}

void insertElement(int arr[], int *ptr)
{
  int num, a, pos;
  int n = *ptr;

  printf("Enter the number you want to input: ");
  scanf("%d", &num);

  printf("Where to insert the number?\n1. Start\n2. End\n3. Middle(Choose index)\nChoice : ");
  scanf("%d", &a);

  if (a == 1)
  {
    pos = 0;
  }
  else if (a == 2)
  {
    pos = n;
  }
  else
  {
    int r = 0;
    while (r == 0)
    {
      printf("\nChoose index between 1-%d  : ", n);
      scanf("%d", &pos);

      if (pos < 1 || pos > n)
      {
        printf("Wrong input!!\n");
      }
      else
      {
        r = 1;
      }
    }
    --pos;
  }
  n++;
  // 5 4 1 3 2
  for (int i = n - 1; i >= pos; i--)
  {
    arr[i + 1] = arr[i];
  }

  arr[pos] = num;
  *ptr = n;
}

void deleteElement(int arr[], int *ptr)
{
  int vp, num, f = 0, index;
  int n = *ptr;

  printf("Delete number by value or position?\n1. Value\n2. Position\nChoice : ");
  scanf("%d", &vp);

  if (vp == 1)
  {

    while (f == 0)
    {
      printf("Enter number : ");
      scanf("%d", &num);

      for (int i = 0; i < n; i++)
      {
        if (num == arr[i])
        {
          index = i;
          f = 1;
          continue;
        }
      }
      if (f != 0)
      {
        continue;
      }
      printf("Number not found!! Try again.");
    }

    for (int i = index; i < n - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
  }
  else if (vp == 2)
  {
    f = 0;

    while (f == 0)
    {
      printf("\nEnter positon of the number (between 1-%d): ", n);
      scanf("%d", &num);

      if (num > 0 && num <= n)
      {
        f = 1;
      }
      else
      {
        printf("Wrong input!! Try again\n");
      }
    }

    for (int i = num - 1; i < n - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
  }

  *ptr = n - 1;
}

void searchElement(int arr[], int *ptr)
{
  int num, index, f = 0;
  int n = *ptr;

  while (f == 0)
  {
    printf("\n-> Enter number: ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++)
    {
      if (num == arr[i])
      {
        printf("\n-----> %d found at %d position in the array <-----", num, i + 1);
        f = 1;
        continue;
      }
    }
    if (f != 0)
    {
      continue;
    }
    printf("Number not found!! Try again.");
  }
}

void bubbleSort(int arr[], int *ptr)
{
  int temp, i, j;
  int n = *ptr;

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("\nSorted array: ");

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}

int menu()
{
  int ch;

  printf("\n\nMENU :\n1. Array traversal\n2. Insert an element\n3. Delete an element\n4. Search an element\n5. Sort all elements\n6. EXIT\nChoice : ");
  scanf("%d", &ch);

  return ch;
}

void main()
{
  int arr[50];
  int ch, n;
  printf("How many numbers do you want to add?: ");
  scanf("%d", &n);

  printf("Enter %d numbers (separated by ENTER): \n", n);
  for (int i = 0; i < n; i++)
  {
    printf("%d. ", i + 1);
    scanf("%d", &arr[i]);
  }

  ch = menu();

  while (ch != 6)
  {
    switch (ch)
    {
    case 1:
      traverseElement(arr, &n);
      break;
    case 2:
      insertElement(arr, &n);
      break;
    case 3:
      deleteElement(arr, &n);
      break;
    case 4:
      searchElement(arr, &n);
      break;
    case 5:
      bubbleSort(arr, &n);
      break;
    default:
      printf("Not available yet");
      break;
    }

    ch = menu();

    if (ch == 6)
    {
      exit(0);
    }
  }
}