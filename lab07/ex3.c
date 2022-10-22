#include <stdio.h>

int getPositiveNumber(char *msg);

int main()
{
  char msg[] = "Enter the expected character: ";
  printf("%d\n", getPositiveNumber(msg));

}

int getPositiveNumber(char *msg)
{
  int check = 0, input;

  while(check == 0)
  {
    printf("%s", msg);
    check = scanf("%d", &input);
    printf("\n");

    while(getchar() != '\n')
    {

    }

  }

  return 1;
}
