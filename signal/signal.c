#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
    while(1){
        printf("Hello World! %d\n", getpid()); //getpid() returns Process Id of calling process
        sleep(1); // sleeps CPU for 1 sec
    }
    return 0;
}
