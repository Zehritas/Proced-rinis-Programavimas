#include <stdio.h>


int main()
{
  int s, n, x, index = 0, size;

  //input
  printf("Please input 2 whole numbers s and n. \nS is the product of multiplication from pairs of n positive numbers.\n");

  while (scanf("%d %d", &s, &n) != 2 || (n < 0))
  {
    printf("Please input whole numbers! N cannot be less than 0!\n");
    while(getchar() != '\n')
    {

    }
  }

  int array[n];
  size = n;
  while (n != 0)
  {
    while (scanf("%d", &x) != 1 || x < 0)
    {
      printf("Please input whole numbers! Array elements have to be positive!\n");
      while(getchar() != '\n')
      {

      }
    }

    --n;
    array[index] = x;
    ++index;
  }
  printf("The pairs which product equals to s: \n");
  //main algorithm and output
  for (int i = 0; i < size; ++i)
  {
    for (int j = i + 1; j < size; ++j) // j = i +1 makes pairs not repeat
    {
      if (array[i] * array[j] == s)
      {
        printf("(%d, %d)", array[i], array[j]);
      }
    }
  }
}
