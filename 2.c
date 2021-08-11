#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int[], int);
void selectionSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int);
void mergeSort(int[], int, int);
void radixSort(int[], int);

int main()
{
  int n, arr[100];
  int i;
  int op, cont;
  do
  {
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter values of array:\n");
    for (i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }
    printf("Enter sorting algorithm to use:\n1: Bubble\n2: Insertion\n3: Quick sort\n4: Merge sort\n5: Selection sort\n6: Radix sort\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      bubbleSort(arr, n);
      break;
    case 2:
      insertionSort(arr, n);
      break;
    case 3:
      quickSort(arr, 0, n - 1);
      break;
    case 4:
      mergeSort(arr, 0, n - 1);
      break;
    case 5:
      selectionSort(arr, n);
      break;
    case 6:
      radixSort(arr, n);
      break;
    default:
      printf("Invalid option!");
    }
    for (i = 0; i < n; i++)
    {
      printf("%d ", arr[i]);
    }
    printf("\nContinue? 1/0:\t");
    scanf("%d", &cont);
  } while (cont == 1);

  return 0;
}

void bubbleSort(int arr[], int size)
{
  int i, j, temp;
  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        //swap
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void selectionSort(int arr[], int size)
{
  int i, j, temp;
  for (i = 0; i < size - 1; i++)
  {
    for (j = i + 1; j < size; j++)
    {
      if (arr[i] > arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void insertionSort(int arr[], int size)
{
  int i, j, key;
  for (i = 1; i < size; i++)
  {
    key = arr[i];
    for (j = i; j > 0 && arr[j - 1] > key; j--)
    {
      arr[j] = arr[j - 1];
    }
    arr[j] = key;
  }
}

int partition(int arr[], int offset, int size)
{
  int x = arr[size];
  int i = offset - 1;
  int j;
  int temp;
  for (j = offset; j < size; j++)
  {
    if (arr[j] <= x)
    {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[size];
  arr[size] = temp;
  return i + 1;
}

void quickSort(int arr[], int offset, int size)
{
  int pivot;
  if (offset < size)
  {
    pivot = partition(arr, offset, size);
    quickSort(arr, offset, pivot - 1);
    quickSort(arr, pivot + 1, size);
  }
}

void merge(int arr[], int offset, int mid, int size)
{
  int n1 = mid - offset + 1;
  int n2 = size - mid;
  int *l = (int *)calloc(n1 + 1, sizeof(int));
  int *r = (int *)calloc(n2 + 1, sizeof(int));
  int i, j, k;
  for (i = 0; i < n1; i++)
  {
    *(l + i) = arr[offset + i];
  }
  for (j = 0; j < n2; j++)
  {
    *(r + j) = arr[mid + j + 1];
  }
  *(l + n1) = 32767;
  *(r + n2) = 32767;
  i = j = 0;
  for (k = offset; k <= size; k++)
  {
    if (*(l + i) <= *(r + j))
    {
      arr[k] = *(l + i);
      i++;
    }
    else
    {
      arr[k] = *(r + j);
      j++;
    }
  }
  free(l);
  free(r);
}

void mergeSort(int arr[], int offset, int size)
{
  if (offset < size)
  {
    int mid = (offset + size) / 2;
    mergeSort(arr, offset, mid);
    mergeSort(arr, mid + 1, size);
    merge(arr, offset, mid, size);
  }
}

int largest(int arr[], int size)
{
  int large = arr[0], i;
  for (i = 1; i < size; i++)
  {
    if (large < arr[i])
      large = arr[i];
  }
  return large;
}

void radixSort(int arr[], int size)
{
  int bucket[10][10], bucket_count[10];
  int i, j, k, remainder, NOP = 0, divisor = 1, large, pass;

  large = largest(arr, size);
  while (large > 0)
  {
    NOP++;
    large /= 10;
  }

  for (pass = 0; pass < NOP; pass++)
  {
    for (i = 0; i < 10; i++)
    {
      bucket_count[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
      remainder = (arr[i] / divisor) % 10;
      bucket[remainder][bucket_count[remainder]] = arr[i];
      bucket_count[remainder] += 1;
    }

    i = 0;
    for (k = 0; k < 10; k++)
    {
      for (j = 0; j < bucket_count[k]; j++)
      {
        arr[i] = bucket[k][j];
        i++;
      }
    }
    divisor *= 10;
  }
}
