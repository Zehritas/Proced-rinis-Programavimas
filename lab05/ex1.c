#include <stdio.h>
#define CAPACITY 20

int main()
{
  int size = 10, x, y;


  // a)
  int array[CAPACITY] = {0};

  // b)
  printf("Array at the start:\n");
  for (int i = 0; i < size; ++i )
  {
    printf("%d\n", array[i]);
  }

  // c)
  array[0] = 1;
  array[3] = 2;
  array[9] = 3;

  // d)
  for (int i = 2; i <= size - 1; ++i)
  {
    array[i] = array[i + 1];
  }

  --size;

  // e)
  for (int i = size; i >= 6; --i)
  {
    array[i + 1] = array[i];
  }

  array[6] = 4;
  ++size;

  // f)
  printf("The array after changes:\n");
  for (int i = 0; i < size; ++i )
  {
    printf("%d\n", array[i]);
  }

  // g)
  printf("Insert 2 numbers x and y. x is the index which value should change to y\n");
  while(scanf("%d %d", &x, &y) != 2 || (x >= size || x < 0))
  {
    printf("Enter whole numbers. x has to be smaller than size of array (%d) and smaller than 0!\n", size);
    while(getchar() != '\n')
    {

    }
  }

  array[x] = y;

  // h
  printf("Enter index number which should be deleted!\n");
  while(scanf("%d", &x) != 1 || (x >= size || x < 0))
  {
    printf("Enter whole number. x has to be smaller than size of array (%d) and smaller than 0!\n", size);
    while(getchar() != '\n')
    {

    }
  }

  for (int i = x; i <= size - 1; ++i)
  {
    array[i] = array[i + 1];
  }
  --size;

  // i)
  printf("Insert 2 numbers x and y. x is the index where should y be inserted\n");

  while(scanf("%d %d", &x, &y) != 2 || (x >= size || x < 0))
  {
    printf("Enter whole numbers. x has to be smaller than size of array (%d) and smaller than 0!\n", size);
    while(getchar() != '\n')
    {

    }
  }

  for (int i = size; i >= x; --i)
  {
    array[i + 1] = array[i];
  }

  array[x] = y;
  ++size;
  //////////////////////////////////////////////////////////////////////////////
  // j)
  printf("The array after changes:\n");
  for (int i = 0; i < size; ++i )
  {
    printf("%d\n", array[i]);
  }

}
