// Calculating area and circumference of the circle

#include <stdio.h>
#define pi 3.141529

int main() {

      float radius;
      double area, cf;

      printf("Enter radius of the circle: ");
      scanf("%f", &radius);

      area = pi * radius * radius;
      cf = 2 * pi * radius;

      printf("\nThe area of the circle is: %lf and the circumference is: %lf", area, cf);

      return 0;
}
