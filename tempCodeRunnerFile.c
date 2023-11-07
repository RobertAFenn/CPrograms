#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int input, value = 0, a = 0, b = 1;

    printf("Enter the number for a Fibonacci Sequence (Parent): ");
    scanf("%d", &input);

    // Check if it's a non-negative number
    if (input < 0) {
        printf("Please enter a non-negative value\n");
        return 1;
    }

    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) { /* child process */
        printf("Child is computing.");

        for (int i = 1; i <= input; i++) {
            printf(" %d", a);
            int nextVal = a + b;
            a = b;
            b = nextVal;
            value = a; // Update value in the child process
        }

        printf("\n");

        return 0;
    } else if (pid > 0) { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d\n", value);
        return 0;
    }
}
