#include <stdio.h>

/*
? An int variable with block scope and temporary storage
? A constant character variable with block scope
? A float local variable with permanent storage
? A register int variable
? A char pointer initialized with a null character
*/

static float myFloat;
char *char_ptr = "\0";

int main() {
  int myNum;
  register int x;
  const char c;
}