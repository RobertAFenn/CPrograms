#include <stdio.h>

int main() {
  char array_ch[5] = {'A', 'B', 'C', 'D', 'E'};

  // ? Print out the values within the array
  char *arrPtr = 0;

  for (int i = 0; i < sizeof(array_ch); i++) {
    arrPtr = &array_ch[i];
    printf("Index %d: %c\n", i, *arrPtr);
  }

  return 0;
}