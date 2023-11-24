#include <stdio.h>
#include <string.h>

void printStrLn(char *s) { printf("%s\n", s); }

void println() { printf("\n"); }

int main() {
  printStrLn("Printing this string using a function");
  char *s = "This is also a string";
  printStrLn(s);

  s = "For Loop!";
  for (int i = 0; s[i]; i++) {
    printf("[%d][%c]\n", i, s[i]);
  }
  println();

  return 0;
}