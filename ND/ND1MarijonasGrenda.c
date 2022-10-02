//This program was made by Marijonas Grenda
//This file contains a C program, which takes input (whole numbers)
//And outputs the quantity of uneven sums of the entered numbers
#include <stdio.h>
#include <stdlib.h>

int main ()
{
  //variables
  int answerNumber = 0;
  long long int number = 1;
  long long int tmp, numberSum;
  //input
  printf("This program takes sequences of whole numbers and calculates the sum of its digits,\n");
  printf("output of the program is the quantity of uneven sums! To end the sequence enter 0.\n");
  printf("Input the number sequence:\n");
  while (number != 0)
  {
    //foolproof 
    while (scanf("%lld", &number) != 1 || (getchar() != '\n'))
    {
        printf("Only whole numbers allowed!\n");
        while(getchar() != '\n')
          {

          }
    }

    //set up variables for math
    tmp = abs(number);
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
