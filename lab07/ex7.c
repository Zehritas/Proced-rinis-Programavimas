#include <stdio.h>
#include <string.h>

#define CAPACITY 100

int getValue(int index, FILE *filePointer);
void setValue(int index, FILE *filePointer);
//void addValue(int index, FILE *filePointer);
long getFileSize(char *fileName);

int main()
{
  char fileName[] = "file.bin";
  int value, index;
  FILE *filePointer;
  long fileSize;
  fileSize = getFileSize(fileName);
  filePointer = fopen("file.bin", "rb+");
  printf("Enter index of number which calue of you would like to get: \n");
  scanf("%d", &index);
  if (index - 1 > fileSize || index - 1 < 0)
  {
    printf("Incorrect index!.\n");
    return -1;
  }
  value = getValue(index - 1, filePointer);
  printf("Value with index %d is: %d\n", index, value);
  setValue(index - 1, filePointer);
  //addValue(index, filePointer);
  //remValue(index, filePointer);
  fclose(filePointer);
}

int getValue(int index, FILE *filePointer)
{
  int value;
  fseek(filePointer, index, SEEK_SET);
  fscanf(filePointer, "%1d", &value);
  return value;
}

void setValue(int index, FILE *filePointer)
{
  char temp[CAPACITY];
  printf("Insert value1: ");
  scanf("%s", temp);
  char value[strlen(temp)];
  strcpy(value, temp);
  fseek(filePointer, index, SEEK_SET);
  fwrite(value, 1, sizeof(value), filePointer); //fwrite reik nuadot
}

/*void addValue(int index, FILE *filePointer)
{
  fseek(filePointer, -3, SEEK_END);
  char tmp, value;
  int i = ftell(filePointer);
  printf("Insert value1: ");
  scanf(" %c", &value);

  while (i < index)
  {
    value = fgetc
  }
}*/

void addValue(int index, FILE *filePointer)
{

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
