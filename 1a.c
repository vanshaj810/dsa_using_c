#include <stdio.h>

int gcd(int a, int b);

int main()
{

  int a, b;

  printf("Let's calculate GCD=>\n\nEnter first number: ");
  scanf("%d", &a);
  printf("Enter second number: ");
  scanf("%d", &b);

  printf("GCD: %d", gcd(a, b));
  printf("\n");
  return 0;
}

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}