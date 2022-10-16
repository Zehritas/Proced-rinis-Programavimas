#include <stdio.h>

int main()
{
  int inputNumb;
  unsigned long long int factorialNumb = 1;
  FILE *outFile;

  printf("This program takes one positive whole number and calculates its factorial!\n");
  printf("Please enter a positive integer:\n");
  while ((scanf("%d", &inputNumb) != 1 || (getchar() != '\n')) || inputNumb < 0 || inputNumb > 20)
  {
    if (inputNumb > 20)
    {
      printf("This program supports numbers not larger than 20!\n");
    }

    else if (inputNumb < 0)
    {
      printf("Only positive integers are allowed!\n");
    }

    else {
      printf("Only whole numbers allowed!\n");
    }

    while(getchar() != '\n')
    {

    }

  }

  for (int i = 1; i <= inputNumb; ++i)
  {
    factorialNumb *= i;
  }
  outFile = fopen("out.txt", "w");
  fprintf(outFile, "The factorial of %d is %llu\n", inputNumb, factorialNumb);
  printf("The factorial of %d is %llu\n", inputNumb, factorialNumb);
  fclose(outFile);
}
