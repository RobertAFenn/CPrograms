// Include necessary header files
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int status;
  pid_t pid;

  // Fork a child process
  if (!fork()) {
    return 1; // Child process returns 1 and exits
  }

  // Parent process waits for the child to terminate
  pid = wait(&status);

  // Check if wait() returns an error (pid == 1)
  if (pid == 1) {
    perror("wait"); // Print an error message if wait() fails
  }

  printf("pid=%d\n", pid);

  // Check if the child terminated normally
  if (WIFEXITED(status)) {
    printf("Normal termination with exit status=%d\n", WEXITSTATUS(status));
  }

  // Check if the child was killed by a signal
  if (WIFSIGNALED(status)) {
    printf("Killed by signal=%d%s\n", WTERMSIG(status),
           WCOREDUMP(status) ? " (dumped core)"
                             : ""); // Print signal information
  }

  // Check if the child was stopped by a signal
  if (WIFSTOPPED(status)) {
    printf("Stopped by signal=%d\n",
           WSTOPSIG(status)); // Print signal information
  }

  // Check if the child was continued after being stopped
  if (WIFCONTINUED(status)) {
    printf("Continued\n"); // Print if the child was continued
  }

  return 0; // Exit the parent process
}
