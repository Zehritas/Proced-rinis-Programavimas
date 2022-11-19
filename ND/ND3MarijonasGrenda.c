#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int checkCommandLine(int argc, char *argv[]);
void getBuffer(int bufferSize, char **data, FILE **readFile, char *fileName);
void cleanBuffer();

int main(int argc, char *argv[])
{
   FILE *dataFile;
   char dataFileName[100]; // Change this to be a defineable size
   int check = checkCommandLine(argc, argv), resultFile = 1;
   char *data = NULL;
   // Check if correct input
   if (check != 0)
   {
      resultFile = 0;
      if (check == 2)
      {
         while (check)
         {
            printf("Please enter data file name!: ");
            scanf("%s", dataFileName);
            cleanBuffer();
            if ((fopen(dataFileName, "r")) != NULL)
            {
               check = 0;
            }
         }
      }
      else
      {
         strcpy(dataFileName, argv[1]);
         while ((fopen(dataFileName, "r")) == NULL)
         {
            printf("Please enter data file name!: ");
            scanf("%s", dataFileName);
            cleanBuffer();
         }
      }
   }

   else if (check == 0)
   {
      strcpy(dataFileName, argv[1]);
      while ((fopen(dataFileName, "r")) == NULL)
      {
         printf("Please enter data file name!: ");
         scanf("%s", dataFileName);
         cleanBuffer();
      }
   }

   // Do something else
   // Move to function (read buffer)
   char BUFFER[BUFFER_SIZE];
   int elementsRead = 0;
   if (fopen(dataFileName, "r") == NULL)
   {
      printf("File could not be opened.\n");
      exit(1);
   }
   dataFile = fopen(dataFileName, "r");
   elementsRead = fread(BUFFER, sizeof(char), (BUFFER_SIZE + 1), dataFile);
   data = (char *)realloc(data, elementsRead * sizeof(char));
   if (data == NULL)
   {
      printf("Could not allocate memory.\n");
      exit(1);
   }
   // char tmpr[elementsRead];
   char *tmpr = malloc(elementsRead * sizeof(char));
   if (tmpr == NULL)
   {
      printf("Could not allocate memory.\n");
      exit(1);
   }
   memcpy(tmpr, BUFFER, (elementsRead * sizeof(char)));
   strcpy(data, tmpr);
   printf("%s\n", data);
   // Read buffer done
   if (elementsRead < BUFFER_SIZE)
   {
      printf("Nereikia skaityt antra karta.\n");
   }
   else
   {
      printf("Read again bby!\n");
   }
}

int checkCommandLine(int argc, char *argv[])
{
   if (argc == 1)
   {
      return 2; // two arg missing
   }

   else if (argc == 2)
   {
      return 1; // one arg missing
   }

   else if (argc == 3)
   {
      return 0;
   }

   else if (argc > 3)
   {
      printf("Usage: programName duom.txt rez.txt\n");
      exit(1);
   }
}

void getBuffer(int bufferSize, char **data, FILE **readFile, char *fileName)
{
   char BUFFER[BUFFER_SIZE];
   int elementsRead;
   if ((*readFile = fopen(fileName, "r")) == NULL)
   {
      printf("File could not be opened.\n");
      exit(1);
   }

   elementsRead = fread(BUFFER, (BUFFER_SIZE + 1), sizeof(char), *readFile);
   printf("%s %d", BUFFER, elementsRead);
}

void cleanBuffer()
{
   while (getchar() != '\n')
   {
   }
}
