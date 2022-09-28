#include <stdio.h>
#include <math.h>

int main()
{
  float x, y, z;
  printf("Iveskite 3 skaicius\n");
  scanf("%f%f%f", &x, &y, &z);

  printf("%.2f\n", (x+(y*4)+(z*z*z)));
  printf("%.2f\n", (x + sqrt(y))*((z*z*z*z)-fabs(z)+46.3));
}
