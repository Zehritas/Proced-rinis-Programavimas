// This program was made by Marijonas Grenda 
// This file contains a C program, which takes N whole numbers as input
// And outputs the most frequent number from the input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WIDTH_SIZE 3
#define MAX_WIDTH_INPUT 18

long long int getInput (int maxWidth);
void cleanBuffer ();
long long int findMostFreqNumb(long long int inputArray[],long long int arraySize);
int compareFunction(const void * a, const void * b);

int main()
{
   long long int n, mostFreqNumber;

   // Input
   printf("This program takes a positive number N and asks user to fill an N capacity array with whole numbers,\n");
   printf("output of the program is the most common number.\n");
   printf("Input the capacity of array (N): \n");
   n = getInput(MAX_WIDTH_SIZE);

   if (n <= 0)
   {
      printf("N must be larger than 0. Try again!");
      return 1;
   }

   long long int *inputArray = (long long int *)malloc(n * sizeof(long long int));
   
   if (inputArray == NULL)
   {
      printf("Could not allocate memory.\n");
      return 1;
   }
   
   printf("Enter %lld number(s): \n", n);
   for (int i = 0; i < n; ++i)
   {
      inputArray[i] = getInput(MAX_WIDTH_INPUT);
   }

   // Main algorithm
   mostFreqNumber = findMostFreqNumb(inputArray, n);

   // Output
   printf("The most common number in the array is: %lld!", mostFreqNumber);
   free(inputArray);
   return 0;

}

long long int findMostFreqNumb(long long int inputArray[], long long int arraySize)
{
   qsort(inputArray, arraySize, sizeof(long long int), compareFunction);

   long long int result = inputArray[0], maxCount = 1, currentCount = 1;
   for (int i = 1; i < arraySize; ++i)
   {
      if (inputArray[i] == inputArray[i - 1])
      {
         currentCount++;
      }

      else
      {
         currentCount = 1;
      }

      if (currentCount > maxCount)
      {
         maxCount = currentCount;
         result = inputArray[i - 1];
      }
   }

   return result;
}


long long int getInput (int maxWidth)
{
   long long int number;
   int check = 1;
   char buffer[100]; //Char array to contain the input converted to a string 

   while (check)
   {
      while (scanf("%lld", &number) != 1 || (getchar() != '\n'))
      {
         printf("Only whole numbers allowed!\n");
         cleanBuffer();
      }

      //Check if the number does not overstep the MAX_WIDTH 
      
      sprintf(buffer, "%lld", llabs(number)); //Take absolute value so '-' does not add to the strlen
      if (strlen(buffer) > maxWidth)
      {
         printf("Number is too large, max is %d digits.\n", maxWidth);
      }
      
      else
      {
         check = 0;
      }

   }

   return number;

}

int compareFunction(const void * a, const void *b)
{
   int x = *(int *)a;
   int y = *(int *)b;
   return x - y;
}


void cleanBuffer ()
{
   while(getchar() != '\n')
   {

   }
}