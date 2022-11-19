#include <stdio.h>
#include <stdlib.h>

int splitData(int * inputArray, int sizeInputArr, int sizeSplitArray1, int **firstPartArray, int **secondPartArray);

int main()
{
   int * firstPartArray = NULL;
   int * secondPartArray = NULL;

   int sizeInputArr = 5, sizeSplitArray1 = 2;
   int inputArray[5] = {2,3,5,8,9};
   printf("Function returned: %d\n", splitData(inputArray, sizeInputArr, sizeSplitArray1, &firstPartArray, &secondPartArray));

   for (int i = 0; i < 2; ++i)
   {
      printf("%d ",firstPartArray[i]);
   }

   for (int i = 2; i < 5; ++i)
   {
      printf("%d ",secondPartArray[i]);
   }


   free(firstPartArray);
   free(secondPartArray);
}

int splitData(int * inputArray, int sizeInputArr, int sizeSplitArray1, int **firstPartArray, int **secondPartArray)
{
   if (inputArray == NULL)
   {
      printf("Please enter a valid input array!\n");
      return -1;
   }

   if (sizeInputArr < 1)
   {
      printf("Size of input array has to be larger than 0!\n");
      return -1;
   }

   if (sizeSplitArray1 >= sizeInputArr)
   {
      printf("Size of first array split cannot be larger or equal to the size of input array!\n");
      return -1;
   }

   if (*firstPartArray != NULL || *secondPartArray != NULL)
   {
      printf("Please do not create split arrays beforehand, initialize them as NULL!\n");
      return -1;
   }

   int sizeSplitArray2 = sizeInputArr - sizeSplitArray1;
   *firstPartArray = (int *) malloc(sizeSplitArray1 * sizeof(int));
   *secondPartArray = (int *) malloc(sizeSplitArray2 * sizeof(int));
   
   for (int i = 0; i < sizeSplitArray1; ++i)
   {
      *(*firstPartArray + i) = inputArray[i];
   }

   for (int i = sizeSplitArray1; i < sizeInputArr; ++i)
   {
      *(*secondPartArray + i) = inputArray[i];
   }
   return 0;

}
