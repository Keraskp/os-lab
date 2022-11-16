#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t fork(void);
    int val = 0;
    printf("Parent Process\n");
    val = fork();
    if (val == 0)
        printf("I am child process with id %d, val : %d\n", getpid(), val);
    else
        printf("I am parent process with id %d, val : %d\n", getpid(), val);

    return 0;
}

// Comments
// fork creates child process, if val is non-zero, it is pid of child process
// if it returns 0, child process successful