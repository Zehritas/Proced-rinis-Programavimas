#include <stdio.h>
#include <string.h>

int main()
{
int n;

//input
printf("This program finds the sum, average, min and max values of n given real numbers.\n");
printf("Input n, the amount of numbers you want to work with: ");
//foolproof
while (scanf("%d", &n) != 1 || (n <= 0) || getchar() != '\n')
{
  printf("Please input a natural number!\n");
  while(getchar() != '\n')
  {

  }

}

float numbers[n], sum = 0, average, min, max;
//more input and foolproof
printf("Input %d number(s): ", n);

// main loop: input and logic
for (int i = 0; i < n; ++i)
{
  while (scanf("%f", &numbers[i]) != 1 || getchar() != '\n')
  {
    printf("Please input a number!\n");
    while(getchar() != '\n')
    {

    }

  }

  if (i == 0)
  {
    min = numbers[0];
    max = numbers[0];
  }

  if (numbers[i] < min)
  {
    min = numbers[i];
  }

  if (numbers[i] > max)
  {
    max = numbers[i];
  }

  sum += numbers[i];
}

//average
average = sum / n;

printf("Sum:  %f\n", sum);
printf("Average:  %f\n", average);
printf("Min value: %f\n", min);
printf("Max value: %f\n", max);




}
