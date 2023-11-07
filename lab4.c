#include <stdio.h>

int main() {

  int myC;
  printf("Enter a character to print to the screen (Using getchar) \n");
  myC = getchar();
  printf("\nCharacter entered %c \n", myC);
  printf("\nputchar ");
  putchar(myC);
  printf("\n");

  return 0;
}