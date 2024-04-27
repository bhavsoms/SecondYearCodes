#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 7; i++) {
        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid == 0) {
            printf("Child process #%d with PID %d\n", i+1, getpid());
            return 0;
        }
    }

    printf("Parent process with PID %d\n", getpid());
    return 0;
}
