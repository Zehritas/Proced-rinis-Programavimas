#include <stdio.h>
#include <string.h>

char * getLargestFileName(int argumentCount, char *argumentVector[]);

int main(int argc, char *argv[])
{
   char fileName[100];
   if (argc == 1)
   {
      printf("Please enter at least one file name!\n");
      return 1;
   }
   printf("Largest file name: %s\n", getLargestFileName(argc - 1, argv));
}

char * getLargestFileName(int argumentCount, char *argumentVector[])
{
   int maxSize = 0, indexMaxSize = 0;
   for (int i = 1; i <= argumentCount; ++i)
   {
      if (strlen(argumentVector[i])  > maxSize)
      {
         maxSize = strlen(argumentVector[i]);
         indexMaxSize = i;
      }
   }
   return argumentVector[indexMaxSize];
}
