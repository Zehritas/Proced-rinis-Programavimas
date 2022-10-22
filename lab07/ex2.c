#include <stdio.h>

int getFactorial(int number);
int getFactorialv2(int number);

int main()
{
  int number;

  printf("Enter a number, this program will find the factorial of it!\n");
  scanf("%d", &number);
  printf("%d\n", getFactorial(number));
  printf("%d\n", getFactorialv2(number));

}

int getFactorial(int number)
{
  if (number < 0)
  {
    return 0;
  }

  if (number == 0)
  {
    return 1;
  }
  else
  {
    return number * getFactorial(number - 1);
  }
}

int getFactorialv2(int number)
{
  if (number < 0)
  {
    return 0;
  }

  int answer = 1;
  for (int i = number; i > 0; --i)
  {
    answer *= i;
  }

  return answer;
}
