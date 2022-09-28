#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
  int skaicius, temp, absoluteValue;
  bool neigiamas = false;
  printf("Iveskite skaiciu: ");
//input
  while (scanf("%d", &skaicius) != 1 || (getchar() != '\n'))
  {
    printf("Prasome pateikti skaiciu!\n");
    while(getchar() != '\n')
    {

    }

  }

  //check if negative
  if (skaicius < 0)
  {
    neigiamas = true;
    skaicius = abs(skaicius);
  }

  if (neigiamas == true)
  {
    printf("-");
  }
  
//sort and print

  for (int i = 0; i <= 9; i++)
  {
    for(temp = skaicius; temp > 0; temp /= 10)
    {
      if(temp % 10 == i)
      {
        printf("%d", i);
      }
    }
  }

  printf("\n");
}
