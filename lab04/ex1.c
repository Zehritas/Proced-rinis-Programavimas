#include <stdio.h>

int main()
{
  int a, b, c, sprendNumb;
  printf("Iveskite 3 skaicius: \n");
  scanf("%d %d %d", &a, &b, &c);
  printf("%d %d %d\n", a, b, c);

  if (((b*b)-(4*a*c)) > 0)
  {
    sprendNumb = 2;
  }
  else if (((b*b)-(4*a*c)) == 0)
  {
    sprendNumb = 1;
  }

  else
  {
    sprendNumb = 0;
  }

  printf("diskriminanto sprendiniu yra %d\n", sprendNumb);
  printf("diskriminanto reiksmes ");

  for (int i = 0; i < sprendNumb; i++)
  {
    ;
  }
}
