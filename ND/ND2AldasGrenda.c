// This program was made by Marijonas Grenda 
// This file contains a C program, which takes N whole numbers as input
// And outputs one number which is closest to the average but is smaller,
// And one number which is closest to the average but is larger.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  //Half of the variables Initialization
  int n,  smallerCount = 0, largerCount = 0, closestSmallerIndex = -1, closestLargerIndex = -1;
  long double average, inputSum;


  //input
  printf("This program takes a positive number N and asks user to fill an N capacity array with whole numbers,\n");
  printf("output of the program are two numbers closest to the average of inputted N numbers\n");
  printf("One of which is smaller than average, other is larger than average.\n");
  printf("Input the capacity of array (N): \n");
  while (scanf("%3d", &n) != 1 || (getchar() != '\n')) //if over 999 it no work cuz too much testing
  {
    printf("Only whole numbers allowed! Do not use a number larger than 999.\n");
    while(getchar() != '\n')
    {

    }
  }

  //Array Initialization
  long long int inputArray[n];
  //long long int *inputArray = (long long int *)malloc(n * sizeof(long long int)); dinamiska atmintis, patikrinti ar yra tminties su if
  long double smallerArray[n], largerArray[n];  // largerArray is for storing numbers > average, difference
  //Input of array elements                     // smallerArray is for storing numbers < average
  printf("Enter %d number(s): \n", n);
  for (int i = 0; i < n; ++i)
  {
    while (scanf("%18lld", &inputArray[i]) != 1 || (getchar() != '\n'))
    {
      printf("Only whole numbers allowed! Max 18 digits!\n");
      while(getchar() != '\n')
      {

      }
    }
    inputSum += inputArray[i]; //sum calculation
  }

  //Main algorithm
  average = inputSum / n; //average calculation
  printf("Average: %Lf\n", average);

  //Find all smaller and larger elements than the average, and find how close they are to the average
  for (int i = 0; i < n; ++i)
  {
    smallerArray[i] = 0;
    largerArray[i] = 0;
    if ((double)inputArray[i] != average && (double)inputArray[i] < average)
    {
      smallerArray[i] = (double)inputArray[i] - average;
      closestSmallerIndex = i;
    }

    else if ((double)inputArray[i] != average && (double)inputArray[i] > average)
    {
      largerArray[i] = (double)inputArray[i] - average;
      closestLargerIndex = i;
    }
  }

  //for checking
  /*for (int i = 0; i < n; ++i)
  {
    printf("%lld ", inputArray[i]);
    printf("%Lf ", largerArray[i]);
    printf("%Lf\n ", smallerArray[i]);
  }*/

  //Find the closestSmallerIndex and the closestLargerIndex
  for (int i = 0; i < n; ++i)
  {
    if ((double)inputArray[i] != average && (double)inputArray[i] < average)  //abs (x - y)  < tikslumas
    {
      if (smallerArray[i] > smallerArray[closestSmallerIndex] && smallerArray[i] != 0)
      {
        closestSmallerIndex = i;
      }
    }

    else if ((double)inputArray[i] != average && (double)inputArray[i] > average)
    {
      if (largerArray[i] < largerArray[closestLargerIndex] && largerArray[i] != 0)
      {
        closestLargerIndex = i;
      }
    }
  }

  //Output cases
  if (closestSmallerIndex == -1 && closestLargerIndex == -1)
  {
    printf("There is no number smaller than the average.\n");
    printf("There is no number larger than the average.\n");
  }

  else if (closestLargerIndex == -1)
  {
    printf("There is no number smaller than the average.\n");
    printf("Closest number to to the average which is larger than the average: %lld\n", inputArray[closestLargerIndex]);
  }

  else if (closestSmallerIndex == -1)
  {
    printf("Closest number to to the average which is larger than the average: %lld\n", inputArray[closestLargerIndex]);
    printf("There is no number larger than the average.\n");
  }

  else
  {
    printf("Closest number to to the average which is smaller than the average: %lld\n", inputArray[closestSmallerIndex]);
    printf("Closest number to to the average which is larger than the average: %lld\n", inputArray[closestLargerIndex]);
  }
  return 0;

}
