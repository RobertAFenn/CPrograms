#include <stdio.h>
#include <string.h>
// !  Given a character string, I really like C!, write a program to pass the
// string to a function that displays the string on the screen.

void printStrln(char *s) { printf("%s\n", s); }

int main() {
  char *str = "I really like C!";
  printStrln(str);
  return 0;
}
