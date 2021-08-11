#include <stdio.h>
#include <stdlib.h>

int max(int m, int n) { return (m > n) ? m : n; }

int *add(int A[], int B[], int m, int n)
{
  int size = max(m, n);
  int *sum = malloc(sizeof(size));

  for (int i = 0; i < m; i++)
  {
    sum[i] = A[i];
  }
  for (int i = 0; i < n; i++)
  {
    sum[i] += B[i];
  }

  return sum;
}

void printPoly(int poly[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d", poly[i]);
    if (i != 0)
      printf("x^%d", i);
    if (i != n - 1)
      printf(" + ");
  }
}

int main()
{
  int A[] = {3, 0, 10, 6};

  int B[] = {4, 1, 2, 4};
  int m = sizeof(A) / sizeof(A[0]);
  int n = sizeof(B) / sizeof(B[0]);

  printf("First polynomial is: \n");
  printPoly(A, m);
  printf("\nSecond polynomial is: \n");
  printPoly(B, n);

  int *sum = add(A, B, m, n);
  int size = max(m, n);

  printf("\nSum is: \n");
  printPoly(sum, size);
  printf("\n");

  return 0;
}
