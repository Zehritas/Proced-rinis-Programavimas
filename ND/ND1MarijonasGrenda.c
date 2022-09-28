//Dokumentacija liko
#include <stdio.h>

int main ()
{
  //variables
  int answerNumber = 0;
  int number = 1;
  int tmp, numberSum;
  //input
  printf("This program takes sequences of whole numbers and calculates the sum of its digits,\n");
  printf("output of the program is the quantity of uneven sums!\n");
  printf("Input the number sequence:\n");
  while (number != 0)
  {
    //foolproof   (liko int length suziureti)
    while (scanf("%d", &number) != 1 || (getchar() != '\n'))
    {
        printf("Only whole numbers allowed!\n");
        while(getchar() != '\n')
          {

          }
    }

    //set up variables for math
    tmp = number;
    numberSum = 0;

    //main algorithms
    while (tmp != 0)
    {
      numberSum += (tmp % 10);
      tmp /= 10;
    }

    if ((numberSum % 2) == 1)
    {
      ++answerNumber;
    }

  }

  //output
  printf("Number of digits whose sum is uneven: %d\n", answerNumber);

}
