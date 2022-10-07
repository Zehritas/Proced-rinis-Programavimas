#include <stdio.h>
#include <string.h>

int main()
{

int digits = 1, maxDigits = 0;
double inputNumb = 5, mostDigitNumb = 1;


//input
printf("This program finds the number with most digits from a positive number sequence.\n");
printf("To end the sequence write a negative number!\n");
printf("Input the numbers: ");


//foolproof

while (inputNumb >= 0)
{
  while (scanf("%lf", &inputNumb) != 1 || getchar() != '\n')
  {
    printf("Please input a number!\n");
    while(getchar() != '\n')
    {

    }

  }



  if (inputNumb >= 0)
  {

    char buffer[50];
    sprintf(buffer, "%lf", inputNumb);
    digits = strlen(buffer) - 1;
    for (int i = digits; i > digits - 6; --i )
    {
      if(buffer[i] == '0')
      {
        memmove(&buffer[i], &buffer[i + 1], strlen(buffer) - i);
      }
      else
      {
        break;
      }
    }

    digits = strlen(buffer) - 1;

    if (digits > maxDigits)
    {
      maxDigits = digits;
      mostDigitNumb = inputNumb;
    }
  }

}

//output
printf("Most digit number: %lf  with %d (**meaningful**) digit(s)\n", mostDigitNumb,  maxDigits);
}
