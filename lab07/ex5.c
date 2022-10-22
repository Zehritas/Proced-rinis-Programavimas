#include <stdio.h>

long getFileSize(char *fileName);

int main()
{
  char fileName[] = "file.bin";
  long fileSize;
  fileSize = getFileSize(fileName);
  printf("%ld", fileSize);
}

long getFileSize(char *fileName)
{
  FILE *filePointer;
  filePointer = fopen(fileName, "rb");
  if (filePointer == NULL)
  {
    printf("There is no file.\n");
    return -1;
  }

  fseek(filePointer, 0, SEEK_END);
  return ftell(filePointer);

}
