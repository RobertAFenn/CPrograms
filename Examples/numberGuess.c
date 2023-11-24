#include <stdio.h>

void printStrLn(char *s) { printf("%s\n", s); }

int main() {
  int usrInt = 0, num = 0, guessNum = 0;

  printStrLn("Welcome to the number guessing game, to begin enter a number");
  scanf("%d", &num); // Use "&" to get the address of 'num'

  printf("We will begin to guess number: %d\n", num);

  while (usrInt != num) {
    printf("-------------------------------\n");
    guessNum++;
    printf("Guess number %d\n", guessNum);
    printStrLn("Enter a number to guess");
    scanf("%d", &usrInt); // Use "&" to get the address of 'usrInt'

    if (usrInt == num)
      break;
    else if (usrInt > num)
      printStrLn("Sorry the number is lower!");
    else
      printStrLn("Sorry the number is higher!");

  }

  printStrLn("Congrats on guessing the number!\nExiting program now\n");

  return 0;
}
