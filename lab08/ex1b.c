#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateArray(int * data, int size, int low, int high);
int * createArray(int size, int low, int high);

int main()
{
   srand(time(NULL));
   int *ptr;
   ptr = createArray(10, 0, 5);
   for(int i = 0; i < 10; ++i)
   {
      printf("\nPointer where:%d pointer what:%d\n", (ptr + i), *(ptr + i));         
   }
}

int * createArray(int size ,int low, int high)
{
   int *data = malloc(size * sizeof(int));
   if (data == NULL)
   {
      return NULL;
   }

   generateArray(data, size, low, high);

   for (int i = 0; i < size; ++i)
   {
      printf("%d element: %d\n", i, *(data + i));
   }

   return data;

}

void generateArray(int * data, int size, int low, int high)
{
  if (low > high)
  {
    printf("Low cannot be higher than high");
    return;
  }

  for (int i = 0; i < size; ++i)
  {
    if (low == 0)
    {
        *(data + i) = low + (rand() % (high + 1));
    }
    else
    {
        *(data + i) = low + (rand() % high);
    }
  }
}