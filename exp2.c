// Converting kms into meters, feet, inches and centimeters

#include <stdio.h>

int main() {

      int km;
      long m, ft;
      long long inch, cm;

      printf("Enter the distance in kilometers: ");
      scanf("%d", &km);

      m = km * 1000;
      ft = km * 3281;
      inch = km * 39370;
      cm = km * 100000;

      printf("\n%d kilometers = %ld meters = %ld feets = %lld inches = %lld centimeters", km, m, ft, inch, cm);

      return 0;
}
