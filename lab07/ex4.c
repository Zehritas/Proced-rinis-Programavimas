#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void generateArray(int data[], int size, int low, int high);

int main()
{
  srand(time(NULL));
  int size, low, high;
  printf("size, [low;high]\n");
  scanf("%d %d %d", &size, &low, &high);
  int data[size];
  generateArray(data, size, low, high);

}

void generateArray(int data[], int size, int low, int high)
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
        data[i] = low + (rand() % (high + 1));
    }
    else
    {
        data[i] = low + (rand() % high);
    }
  }
}
