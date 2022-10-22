#include <stdio.h>
#include <marijonasgeriausias.h>

// This function swaps values pointed by xp and yp

int main()
{
	int x, y;
  int array[5] = {1, 2, 69 ,15 ,15};
  printf("\nBefore Swapping: x = %d, y = %d", array[1], array[4]);
	swap(&array[1], &array[4]);
	printf("\nAfter Swapping: x = %d, y = %d",array[1], array[4]);
	return 0;
}
