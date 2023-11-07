#include <stdio.h>

// Function to print an integer in binary
void printBinary(int num) {
  int mask =
      1 << (sizeof(int) * 8 - 1); // Create a mask to extract the leftmost bit

  for (int i = 0; i < sizeof(int) * 8; i++) {
    // Use bitwise operators to check each bit and print '0' or '1'
    if (num & mask) {
      printf("1");
    } else {
      printf("0");
    }

    num <<= 1; // Shift the number to the left
  }
}

int main() {
  int x = 0;
  int y;

  y *= x + 5;
  printf("%d\n", y);
  y = y * x + 5;
  printf("%d\n", y);

  return 0;
}
