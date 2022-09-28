#include <stdio.h>
#include <string.h>

int main()
{
  //Kintamieji
  int skaicius;
  //Du kintamieji su galimais atsakymais, nes galimas tik vienas printf
  char variantas1[10] = "Lyginis";
  char variantas2[10] = "Nelyginis";
  //Kintamasis galutinio atsakymo laikimui
  char atsakymas[10];
  printf("Iveskite skaiciu: ");
  //Nesu tikras ar tikrinti input teisinguma yra uzduoties dalis, bet tiesiog pasiskolinau is lab01 ex3
  while (scanf("%d", &skaicius) != 1 || (getchar() != '\n')) //fixas buvo naudoti || logika o ne && :D
  {
    printf("Prasome pateikti skaiciu!\n");
    while(getchar() != '\n')
    {
      //Input kaip 5a vistiek priimtu kaip valid, bet nezinau kaip fixint (Apie sita dali ir noreciau suzinoti)
    }

  }
  //Naudoju srcpy funkcija nes nesugalvojau kaip kitaip uzpildyti atsakymo masyva
  printf("%s", (skaicius % 2 == 0 ? "Lyginis" : "Nelyginis"));
  return 0;
}
