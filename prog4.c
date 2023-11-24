#include <pthread.h>
#include <stdio.h>
#include <string.h>
/*
 * Write a C program that utilizes two threads displaying two strings “Hello”
 * and “How are you?” independent of each other.  Call the program prog4.c.
 * Compile the program.
 */

// ? Void pointers can point to anything
void *print_message(void *ptr) {
  // ? Assign the void pointer to a char
  char *message = (char *)ptr;
  printf("%s\n", message);
  pthread_exit(NULL);
}

void *print_message2(char *message) {
  printf("%s\n", message);
  pthread_exit(NULL);
}

int main() {
  pthread_t thread1, thread2;
  char *message1 = "Hello";
  char *message2 = "How are you?";

  while (1) {
    pthread_create(&thread1, NULL, print_message, message1);
    pthread_create(&thread2, NULL, print_message, message2);
  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  return 0;
}