#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define CAPACITY 100

int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
int medianOfThree(int array[], int low, int high);

//high - ending index
//low - starting index
int main()
{
  int array[CAPACITY], low = 0, high, number, counter = 0;
  while (number != 0)
  {
    //foolproof(validation)
    while (scanf("%lld", &number) != 1 || (getchar() != '\n'))
    {
      printf("Only whole numbers allowed!\n");
      while(getchar() != '\n')
      {

      }
    }

    if (number != 0)
    {
      array[counter] = number;
      ++counter;
    }

  }
  high = counter - 1;

  // Runner ///////////////////
  quickSort(array, low, high);
  /////////////////////////////
  for (int i = 0; i <= high; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n%d %d", low, high);
}

//////////////////////////////////////////////////////////////////////////////
//                              THE                                         //
//                                FUNCTIONS                                 //
//                                        XD                                //
//////////////////////////////////////////////////////////////////////////////

//                            NUMBER 1: The main quickSort                  //
void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pivot_index = partition(array, low, high);
    quickSort(array, low, pivot_index); //Left of the array
    quickSort(array, pivot_index + 1, high); //Right of the array
  }
}

//                            NUMBER 2: The partition for quickSort         //
int partition(int array[], int low, int high)
{
    int pivot_index = medianOfThree(array, low, high), i = low, j = high;
    while (i < j)
    {
      while (array[i] < array[pivot_index])
      {
        ++i;
      }

      while (array[j] >= array[pivot_index])
      {
        --j;
      }

      if (i < j)
      {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    int temp = array[i];
    array[i] = array[pivot_index];
    array[pivot_index] = temp;
    return i;

}

//                            NUMBER 3: The pivot for partition             //
int medianOfThree(int array[], int low, int high)
{
  int a = array[low], b = array[((high + low) / 2)], c = array[high], temp;
  array[low] = min(min(a,b), c);
  array[high] = max(max(a,b), c);
  array[((high + low) / 2)] = a + b + c - array[low] - array[high];
  temp = array[((high + low) / 2)];
  array[((high + low) / 2)] = array[high - 1];
  array[high - 1] = temp;
  return high - 1;
}
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 ~THE END~                                  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

/*for (int i = 0; i <= high; ++i)
{
  printf("%d ", array[i]);
}
printf("\n%d %d", low, high);*/
