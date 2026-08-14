#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("\nMy PID is : %d",getpid());
    pid_t pid = fork();
    if(pid==0)
    {
        printf("\nI am Child Process");
    }
    else 
    {
        printf("\nI am PArent Process");
    }
    return 0;
}