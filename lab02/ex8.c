#include <stdio.h>
#include <math.h>
#include <string.h>

int toDecimal(char *skaicius, int baseOld);
char * toBaseNew(char newBaseSkaicius[], int skaiciusDecimal, int baseNew);
////////////////////////////////////////////////////////////////////////////////
int main()
{
  int baseOld, baseNew, skaiciusDecimal = 0;
  char skaicius[36];
  char newBaseSkaicius[36];

  //Input
  printf("Iveskite pradines pozicines sistemos baze: ");
  scanf("%d", &baseOld);

  printf("Iveskite norima pozicines sistemos baze: ");
  scanf("%d", &baseNew);

  printf("Iveskite skaiciu: ");
  scanf("%s", &skaicius);

  skaiciusDecimal = toDecimal(skaicius, baseOld);
  //Output
  printf("%s\n", toBaseNew(newBaseSkaicius, skaiciusDecimal, baseNew));
}
////////////////////////////////////////////////////////////////////////////////
int toDecimal(char *skaicius, int baseOld)
{
  int newSkaicius[strlen(skaicius)];
  int decimalSkaicius = 0, power = (strlen(skaicius) - 1);

  //Conversion to int values
  for (int i = 0; i < strlen(skaicius); i++)
  {
    if (skaicius[i] >= '0' && skaicius[i] <= '9')
    {
      newSkaicius[i] = (int)skaicius[i] - '0';
    }

    else if (skaicius[i] >= 65 && skaicius[i] <= 90)
    {
      newSkaicius[i] = (int)skaicius[i] - 'A' + 10;
    }

    else if (skaicius[i] >= 97 && skaicius[i] <= 122)
    {
      newSkaicius[i] = (int)skaicius[i] - 'a' + 10;
    }

  }

  //Convertion to decimal
  for(int i = 0; i < strlen(skaicius); i++)
  {
    decimalSkaicius = decimalSkaicius + newSkaicius[i] * pow(baseOld, power);
    power--;
  }

  return decimalSkaicius;

}
////////////////////////////////////////////////////////////////////////////////
char * toBaseNew(char newBaseSkaicius[], int skaiciusDecimal, int baseNew)
{
  int i = 0;
  //convertion to new base
  while (skaiciusDecimal > 0)
    {
        if ((skaiciusDecimal % baseNew) >= 0 && (skaiciusDecimal % baseNew) <= 9)
        {
          newBaseSkaicius[i] = (char)((skaiciusDecimal % baseNew) + '0');
        }

        else
        {
          newBaseSkaicius[i] = (char)((skaiciusDecimal % baseNew) - 10 + 'A');
        }

        skaiciusDecimal /= baseNew;
        i++;
    }
    newBaseSkaicius[i] = '\0'; //labai svarbu!!

    //Reverse string
    newBaseSkaicius = strrev(newBaseSkaicius);

    return newBaseSkaicius;
}
