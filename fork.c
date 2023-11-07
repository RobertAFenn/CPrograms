#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  // Declare variables for child process ID (child_pid),
  // process status (status), loop counter (i), and an integer array (a).
  pid_t child_pid, wpid;
  int status = 0;
  int i;
  int a[3] = {1, 2, 1};

  // Print the parent process ID.
  printf("parent_pid = %d\n", getpid());

  // Loop to create child processes.
  for (i = 0; i < 3; i++) {
    printf("i = %d\n", i);

    // Create a child process using fork().
    if ((child_pid = fork()) == 0) {
      printf("In child process (pid = %d)\n", getpid());

      // Check the value in the array 'a' for each child process.
      if (a[i] < 2) {
        printf("Should be accept\n");
        // Exit the child process with status 1 (indicating accept).
        exit(1);
      } else {
        printf("Should be reject\n");
        // Exit the child process with status 0 (indicating reject).
        exit(0);
      }
      /*NOT REACHED*/
    }
  }

  // Parent process: Wait for all child processes to complete.
  while ((wpid = wait(&status)) > 0) {
    // Print the exit status of each child process and
    // whether it was accepted or rejected based on the status value.
    printf("Exit status of %d was %d (%s)\n", (int)wpid, status,
           (status > 0) ? "accept" : "reject");
  }

  // Return 0 to indicate successful completion of the parent process.
  return 0;
}
