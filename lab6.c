#include <stdio.h>

int main() {
  unsigned int expression1 = 0xFFFF ^ 0x8888;
  unsigned int expression2 = 0xABCD & 0x4567;
  unsigned int expression3 = 0xDCBA | 0x1234;

  // * Do not use %d instead use %X

  printf("0xFFFF ^ 0x8888: 0x%X\n", expression1);
  printf("0xABCD & 0x4567: 0x%X\n", expression2);
  printf("0xDCBA | 0x1234: 0x%X\n", expression3);

  return 0;
}
