#include <stdio.h>
#define CAPACITY 1000

int main()
{
  int number = 0, size = 1, array[CAPACITY], check, check1;

  //input
  printf("This program finds the prime numbers from given whole numbers.\nTo end the input enter a negative number!\n");
  while (number >= 0)
  {
    //foolproof(validation)
    while (scanf("%d", &number) != 1 || (getchar() != '\n'))
    {
      printf("Only whole numbers allowed!\n");
      while(getchar() != '\n')
      {

      }
    }
    if (number >= 0)
    {
      check1 = 0;

      //Check if a repeating number
      for(int i = 0; i < size; ++i)
      {
        if (array[i] == number)
        {
          check1 = 1;
        }
      }
      if(check1 != 1)
      {
        array[size - 1] = number;
        ++size;
      }
    }
  }

  printf("These are the prime numbers from the given elements!\n");

  //main algorithm to find prime numbers
  for (int i = 0; i < size; ++i)
  {
    check = 0;
    if (array[i] == 0 || array[i] == 1)
    {
        check = 1;
    }

    for (int j = 2; j <= array[i] / 2; ++j)
    {
      if (array[i] % j == 0)
      {
        check = 1;
        break;
      }
    }

    //output
    if (check == 0)
    {
      printf("%d\n", array[i]);
    }
  }

}
