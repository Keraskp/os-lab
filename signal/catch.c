#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void signal_handler(int signo)
{
    if(signo == SIGINT)
        printf("Received SIGINT\n");
}

int main()
{   
    if(signal(SIGINT, signal_handler) == SIG_ERR)
        printf("Can't catch SIGINT\n");
    while (1)
    {
        sleep(1);
    }
     
    return 0;
}

// Comments 
// signal(<SIG_N0>,<function called>)
// The code below signal keeps executing
// Whenever SIG_INT signal is generated using Ctrl + C, it is caught by signal_handler