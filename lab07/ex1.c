#include <stdio.h>

int isInRange(int number, int low, int high);

int main()
{
  int number, low, high;
  printf("Enter a number and a interval(number, [low;high])\n");
  scanf("%d %d %d", &number, &low, &high);
  if (isInRange(number, low, high))
    printf("Input is correct and in the interval!\n");
  else
    printf("Input is incorrect!\n");

}

int isInRange(int number, int low, int high)
{
  if (low > high)
  {
    return 0;
  }

  else if(number >= low && number <= high)
  {
    return 1;
  }

  else
  {
    return 0;
  }
}
