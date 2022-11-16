#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t fork(void);
    pid_t wait();
    int val = 0;
    printf("Parent Process\n");
    val = fork();
    int v = wait(NULL);
    if (val == 0)
        printf("I am child process with id %d, val : %d\n", getpid(), val);
    else
        printf("I am parent process with id %d, val : %d\n", getpid(), val);

    return 0;
}

// Comments
// declare pid_t wait()
// pass NULL as parameter in wait() for exit status
// exit status returns the reason of process termination
// -1 if the current process has no child