#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    unsigned long long int input, a = 0, b = 1;

    printf("Enter the number for a Fibonacci Sequence (Parent): ");
    scanf("%llu", &input);

    // Check if it's a non-negative number
    if (input < 0) {
        printf("Please enter a non-negative value\n");
        return 1;
    }

    pid_t pid;
    pid = fork();

    // Error handle
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) { /* child process */
        printf("Child is computing.\n");

        // "Base Case"
        if (input > 0) {
            printf("%llu ", a);
        }

        // "Base Case"
        if (input > 1) {
            printf("%llu ", b);
        }

        for (unsigned long long int i = 2; i < input; i++) {
            unsigned long long int nextVal = a + b;
            printf("%llu ", nextVal);
            a = b;
            b = nextVal;
        }

        printf("\nChild ends\n");
        return 0;
    } else if (pid > 0) { /* parent process */
        printf("Parent is waiting for the child process\n");
        wait(NULL);
        printf("Parent ends\n");
        return 0;
    }
}

