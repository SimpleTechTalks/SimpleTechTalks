#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

void exitHandler(void)
{
    printf(" Exiting process pid %d ppid %d \n", getpid(), getppid());
}

int main()
{
    int pfds[2];

    char buf[100];

    if(pipe(pfds) == -1)
    {
        perror("Pipe creation failed");
    }

    printf("Writing to fds %d \n", pfds[1]);
    write(pfds[1], "Hello World", 12);
    printf("Reading from fds %d \n", pfds[0]);
    read(pfds[0], buf, 12);
    printf("String read is [%s] \n", buf);

    printf("Testing pipes using fork \n");

    if(fork())
    {
        printf("Inside pid %d ppid %d \n", getpid(), getppid());
        printf("parent process will write only \n");
        close(pfds[0]);

        int count = 0;
        while(count < 5)
        {
            printf("Parent writing \n");
            write(pfds[1], "Parent sending", 15);
            sleep(5);
            count++;
        }
        printf("Parent exiting \n");
        wait(NULL);
        atexit(exitHandler);
        int *p = NULL;
        //printf("This shoukd crash %d \n", *p);
        //exit(0);
    }
    else
    {
        printf("Inside pid %d ppid %d \n", getpid(), getppid());
        printf("child process will read only \n");
        close(pfds[1]);

        int count = 0;
        while(count < 5)
        {
            read(pfds[0], buf, 15);
            printf("string read at child is [%s] \n", buf);
            count++;
        }
        printf("child exiting \n");
        atexit(exitHandler);
        exit(0);
    }

    return 0;
}
