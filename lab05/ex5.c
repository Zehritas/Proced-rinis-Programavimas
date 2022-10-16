#include <stdio.h>
#include <string.h>
#define CAPACITY 1000

int main()
{
  int array[CAPACITY] = {0}, numberArray[CAPACITY], length, xLength = 0;
  long long int x, tmp;

  printf("Input the x number!\n");
  while (scanf("%lld", &x) != 1 || (getchar() != '\n'))
  {
    printf("Only whole numbers allowed!\n");
    while(getchar() != '\n')
    {

    }
  }

  tmp = x;
  do
  {
    numberArray[xLength] = tmp % 10;
    tmp /= 10;
    xLength++;
  } while(tmp != 0);

  printf("%d\n", xLength);
  for (int i = 0; i < xLength; ++i)
  {
    printf("%d\n", numberArray[i]);
  }

  printf("Input n, the length of your array.\n");
  while ((scanf("%d", &length) != 1 || (getchar() != '\n')) || length < 1)
  {
    printf("Only whole numbers allowed! N can not be less than 1!\n");
    while(getchar() != '\n')
    {

    }
  }
  printf("%d\n", length);
  if (xLength < length)
  {
    printf("No, it is not possible!\n");
    return 0;
  }

  printf("Please enter the array (1 digit numbers): \n");
  for(int i = 0; i < length; ++i)
  {
    while (scanf("%d", &array[i]) != 1 || (getchar() != '\n'))
    {
      printf("Only whole, one digit numbers allowed!\n");
      while(getchar() != '\n')
      {

      }
    }
  }

  int sizeArr = xLength;

  for (int i = 0; i < xLength; ++i)
  {
    for (int j = 0; j < sizeArr; ++j)
    {
      if (numberArray[i] == array[j])
      {
        for (int k = j ; k <= sizeArr - 1; ++k)
        {
          array[k] = array[k + 1];
        }

        --sizeArr;
        break;
      }
    }
  }

  for (int i = 0; i < xLength; ++i)
  {
    if (array[i] != 0)
    {
      printf("No, it is not possible\n");
      return 0;
    }
  }

  printf("Yes, it is possible!\n");

}
