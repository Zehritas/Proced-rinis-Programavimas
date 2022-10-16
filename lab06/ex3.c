#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CAPACITY 100
#define NUMBER_COUNT 3
#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

int main()
{
  //variables
  char inputString[CAPACITY], fileName[CAPACITY];
  int length, digitValue = 10, numbers[NUMBER_COUNT] = {0}, numberCheck = 0, negative[NUMBER_COUNT] = {1, 1, 1}, signCheck = 0;
  FILE *outputFile;

  //input
  printf("Enter 3 numbers seperated by ';' symbol. This program will find the middle one (value).\n");
  gets(inputString);
  length = strlen(inputString);

  for (int i = 0; i < length; ++i)
  {
    if((isdigit(inputString[i]) != 0))
    {
      numbers[numberCheck] = (numbers[numberCheck] * digitValue) + ((int)(inputString[i]) - 48);
    }
    else if (inputString[i] == '-' )
    {
      if (signCheck > 0)
      {
        printf("Wrong input! One '-' sign per number.\n");
        return 1;
      }
      negative[numberCheck] = -1;
      signCheck++;
    }

    else if (inputString[i] == ';')
    {
      numberCheck++;
      signCheck = 0;
    }
    else
    {
      printf("Only whole negative or positive integers allowed! Use ';' su seperate them.\n");
      return 1;
    }
  }

  if (numberCheck != NUMBER_COUNT - 1)
  {
    printf("This program needs %d numbers as its input!\n", NUMBER_COUNT);
    return 1;
  }

  printf("\n");

  for (int i = 0; i < NUMBER_COUNT; ++i)
  {
    numbers[i] *= negative[i];
  }
  printf("\nInput is correct! Enter 'fileName.txt' to see the answer.\n");
  gets(fileName);
  length = strlen(fileName);
  while (fileName[length-1] != 't' || fileName[length-2] != 'x' || fileName[length-3] != 't' || fileName[length-4] != '.')
  {
    printf("File name has to end with '.txt'.\n");
    gets(fileName);
    length = strlen(fileName);
  }
  outputFile = fopen(fileName, "w");

  int midNumber = numbers[0] + numbers[1] + numbers[2] - MAX(MAX(numbers[0], numbers[1]), numbers[2]) - MIN(MIN(numbers[0], numbers[1]), numbers[2]);
  fprintf(outputFile,"Middle number in terms of value is: %d\n", midNumber);
}
