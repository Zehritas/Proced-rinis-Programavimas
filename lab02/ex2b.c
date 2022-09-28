#include <stdio.h>
#include <math.h>

void DtB(int skaicius);
void BtD(long long int skaicius1);

int main()
{
  //Binary to Decimal
  BtD(11011);
  printf(" ");

  BtD(10010100);
  printf(" ");

  BtD(11001011010101);
  printf("\n");

  //Decimal to Binary
  DtB(37);
  printf(" ");

  DtB(241);
  printf(" ");

  DtB(2487);
  printf("\n");

  //Hexadecimal to Decimal
  printf("%i %i %i\n", 0x6E2, 0xED33, 0x123456);

  //Decimal to Hexadecimal
  printf("0x%X 0x%X 0x%X \n", 243, 2483, 4612);
}

void DtB (int skaicius)
{
  int i = 0;
  int binary[32]; //int size 4 bytes

  while (skaicius > 0)
  {
    binary[i++] = skaicius % 2;
    skaicius = skaicius / 2;
  }

  for (int j = i-1; j >= 0; j--)
  {
    printf("%d", binary[j]);
  }
}

void BtD (long long int skaicius1)
{
  int i = 0, liek, decimal = 0;
  while (skaicius1 != 0)
  {
    liek = skaicius1 % 10;
    skaicius1 = skaicius1 / 10;
    decimal += liek * pow(2, i);
    i++;
  }
  printf("%d", decimal);
}
