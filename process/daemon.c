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
    {
        printf("I am parent process with id %d, val : %d\n", getpid(), val);
        sleep(3);
        printf("Parent completed\n");
    }
    return 0;
}