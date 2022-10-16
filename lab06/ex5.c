#include <stdio.h>
#include <string.h>
#define EMAIL_CAPACITY 100

int main()
{
  //variables
  FILE *userOutput;
  int length, validInput = 0, atLocation = 0, dotLocation = 0;
  char email[EMAIL_CAPACITY];

  //input
  printf("Enter an email address: ");
  scanf("%s", email);
  length = strlen(email);

  //validation
  for (int i = 0; i < length; ++i)
  {
    if (email[i] == '@' && i != 0)
    {
      if (atLocation != 0)
      {
        printf("One '@' per email adress.\n");
        return 1;
      }

      atLocation = i;
      validInput++;
    }

    else if (email[i] == '.' && i > atLocation + 1 && i != length - 1)
    {
      dotLocation = i;
      validInput++;
    }

    else if (email[i] == '.' && i == atLocation + 1)
    {
      printf("Inbetween '@' and '.' there has to be another character.\n");
      return 1;
    }
  }

  if (validInput < 2)
  {
    printf("Incorrect input.\n");
    return 1;
  }

  //output
  printf("The email entered is correct.\nThe domain of this website is: \n");
  for (int i = atLocation + 1; i < length; ++i)
  {
    printf("%c", email[i]);
  }
  printf("\n");
  userOutput = fopen("emails.txt", "a");
  fprintf(userOutput, "%s\n", email);

}
