#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 1000

int main()
{
  int array[CAPACITY], a, b, c;
  srand(time(NULL));

  //input
  printf("Input 3 whole numbers a, b, c. Program will print out c numbers in interval [a;b]!\n");
  while (scanf("%d %d %d", &a, &b, &c) != 3 || (c < 0 || a >= b))
  {
    printf("Please input whole numbers! C cannot be less than 0. A has to be less than b!\n");
    while(getchar() != '\n')
    {

    }
  }

  //main algorithm
  for (int i = 0; i < c; ++i)
  {
    if (a == 0)
    {
        array[i] = a + (rand() % (b + 1)); //if a is 0, algorithm breaks (still fits the [a;b] requirements, but is actually [a;b) )
    }
    else
    {
        array[i] = a + (rand() % b);
    }
  }

  //output
  for (int i = 0; i < c; ++i)
  {
    printf("%d\n", array[i]);
  }

}
