#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t fork(void);
    int val = 0;

    val = fork();
    if (val == 0){
        printf("I am child process with id %d, val : %d\n", getpid(), val);
        printf("Child completed\n"); 
        exit(0);
    }
    else
    {
        printf("I am parent process with id %d, val : %d\n", getpid(), val);
        sleep(3);
        printf("Parent completed\n");
    }
    return 0;
}