#include <stdio.h>
#include <ctype.h>
#define MAX_DECIMAL_N 3

int main()
{
  //variables
  int wholePart, decimalPart[MAX_DECIMAL_N], decimalCheck, length = 0, wholePartLength = 0;
  char ch, decimalString[MAX_DECIMAL_N + 1]; //+1 for NULL
  FILE *inFile;

  //input
  printf("Please enter a number from [10;1000] in 'in.txt' file. \n");
  inFile = fopen("in.txt", "r");
  if (inFile == NULL) //if no file, create one
  {
    printf("Please create a file 'in.txt'.\n");
    return 1;
  }

  //main algorithm
  //whole number part
  if ((fscanf(inFile,"%d", &wholePart) != 1) || (wholePart > 1000) || (wholePart < 10))
  {
    printf("Please enter a number inbetween [1;1000].\n");
    return 1;
  }

  int tmp = wholePart;
  while (tmp != 0)
  {
    tmp /= 10;
    wholePartLength++;
  }


  //decimal point check
  ch = fgetc(inFile);

   if (ch == '.')
  {
    printf("Use ',' for decimal part.\n");
    return 1;
  }

  //decimal number part
  else if(ch == ',')
  {
    decimalCheck = 1;
    fgets(decimalString, MAX_DECIMAL_N + 1, inFile);

    for (int i = 0; i < MAX_DECIMAL_N; i++)
    {
        if (isdigit(decimalString[i]) != 0)
        {
          decimalPart[length] = (int)(decimalString[i]) - 48;
          ++length;
        }
        else if (decimalString[i] == ' ' || decimalString[i] == 10)
        {
          break;
        }

        else
        {
          printf("Decimal part only consists of numbers.");
          return 1;
        }
    }
  }

  //check if not larger than 1000
  if (wholePart == 1000)
  {
    for (int i = 0; i < length; ++i)
    {
      if (decimalPart[i] > 0)
      {
        printf("Number is larger than 1000!\n");
        return 1;
      }
    }
  }

  //output
  printf("The number found in 'in.txt' is: ");
  if (decimalCheck == 1)
  {
    printf("%d,", wholePart);
    for(int i = 0; i < length; ++i)
    {
        printf("%d", decimalPart[i]);
    }
    printf(" , length = %d\n", length + wholePartLength);

  }
  else
  {
    printf("%d , length = %d\n", wholePart, wholePartLength);
  }

}
