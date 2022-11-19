#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main()
{
  char menuTitle[] = "This is menu title!", inputMsg[] = "Choose menu option!: ", *menuOptions[3] = {"Labas","Vanagas","Lietuva"};
  int menuSize = 3, optionNumber;
  //scanf();
  optionNumber = showMenu(menuTitle, menuOptions, menuSize, inputMsg);
  printf("Your choice is: %d , %s\n", optionNumber, menuOptions[optionNumber]);

}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
  int optionNumber;
  printf("%s\n", menuTitle);
  for(int i = 0; i < menuSize; ++i)
  {
    printf("%s\n", menuOptions[i] );
  }

  printf("%s\n", inputMsg);
  while(scanf("%d", &optionNumber) != 1 || (optionNumber > menuSize || optionNumber < 0))
  {
    printf("Incorrect input!\n");

    while (getchar() != '\n')
    {

    }
  }

  return optionNumber; // arba (optionnumber - 1), priklauso ar skaiciuojamas meniu nuo 0 ar nuo 1

}
