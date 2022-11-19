#include <stdio.h>

void swap(int *a, int *b);

int main()
{
   int x = 5, y = 6;
   printf("x is %d y is %d\n", x, y);
   swap(&x, &y);
   printf("x is %d y is %d\n", x, y);

}

void swap(int *a, int *b)
{
   int temporaryValue;
   temporaryValue = *a;
   *a = *b;
   *b = temporaryValue;
}
