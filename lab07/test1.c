#include <stdio.h>
#include <marijonasgeriausias.h>

int main()
{
  printf("%s\n", SECRET_MSG);
  int x = 5, y = 9;
  swap(&x, &y);
  printf("%d %d", x, y);

}
