#include <stdio.h>

int main() {

      char letter;

      printf("Enter a character: ");
      scanf("%c", &letter);

      switch(letter) {

      case 'a':
            printf("\nA is a vowel");
            break;

      case 'e':
            printf("\nE is a vowel");
            break;

      case 'i':
            printf("\nI is a vowel");
            break;

      case 'o':
            printf("\nO is a vowel");
            break;

      case 'u':
            printf("\nU is a vowel");
            break;

      default:
            printf("\nIt is not a vowel.\n", letter);
      }
}
