#include <stdio.h>

int main() {

  char input = ' ';

  printf("Please enter a Capital letter A-C \n");
  input = getchar();
  printf("%c\n", input);

  switch (input) {
  case 'C':
  case 'B':
  case 'A':
    printf("%d\n", ((int)input));
    break;

  default:
    printf("A-C Not detected, exiting program\n");
    break;
  }

  return 0;
}