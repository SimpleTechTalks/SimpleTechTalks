#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void exitHandler1(void)
{
    printf("Exit handler 1 called \n");
}

void exitHandler2(void)
{
    printf("Exit handler 2 called \n");
}

void sigint_handler(int sig)
{
    printf("Caught signal %d quitting now \n", sig);
    exit(0);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if(sigaction(SIGINT, &sa, NULL))
    {
        perror("sigaction");
    }
    atexit(exitHandler1);
    atexit(exitHandler2);
    atexit(exitHandler1);
    atexit(exitHandler1);

    while(1)
    {
        char buf[300];
        int *p = NULL;

        printf("Enter the string \n");
        scanf("%s", buf);

        if (!strcmp(buf, "EXIT"))
            break;
        
        if (!strcmp(buf, "KILL")) {
            printf ("Get kill instructions");
            printf ("%d", *p);
        }

        printf("string entered [%s] \n", buf);
    }

    return 0;
}
