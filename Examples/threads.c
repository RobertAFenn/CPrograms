#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_message(void *ptr) {
  char *message = (char *)ptr;
  printf("%s\n", message);
  // Get the thread's id
  pthread_t thread_id = pthread_self();
  printf("Thread ID: %lu\n", (unsigned long)thread_id);
  pthread_exit(NULL);
}

int main() {

  pthread_t thread1, thread2;
  char *message1 = "Hello from Thread 1";
  char *message2 = "Hello from Thread 2";

  // Create new threads
  int ret1 = pthread_create(&thread1, NULL, print_message, message1);
  int ret2 = pthread_create(&thread2, NULL, print_message, message2);

  // Wait for threads to complete
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // Print a message from the main thread
  printf("Hello from Main Thread\n");
  return 0;
}