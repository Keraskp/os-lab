#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void World(int signo)
{
    if (signo == SIGINT)
        printf("Hello SIGINT\n");
}

int main()
{
    signal(SIGINT, World);

    printf("In Main");
    while (1)
    {
        printf("In Loop\n");
        sleep(1);
    }

    return 0;
}

// Declare signal(SIGINT, World) to generate interrupt signal and redirect to World
// In Main prints once, In Loop prints in Loop
// Pressing Ctrl + C executes  World