#include <stdio.h>
void main()
{
      int maths,physics,chemistry,english,french, average, weight;

      printf("Enter marks in Maths: ");
      scanf("%d", &maths);
      printf("Enter marks in Physics: ");
      scanf("%d", &physics);
      printf("Enter marks in Chemistry: ");
      scanf("%d", &chemistry);
      printf("Enter marks in English: ");
      scanf("%d", &english);
      printf("Enter marks in French: ");
      scanf("%d", &french);

      average = (maths + physics + chemistry + english + french) / 5;
      weight = average / 10;

      switch(weight)
      {
      case 9:
            printf("Your grade is A");
            break;
      case 8:
            printf("Your grade is B");
            break;
      case 7:
            printf("Your grade is C");
            break;
      case 6:
            printf("Your grade is D");
            break;
      case 5:
            printf("Your grade is E");
            break;
      default:
            printf("Your grade is F");
            break;
      }
}
