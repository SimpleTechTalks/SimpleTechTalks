#include <unistd.h>
#include <iostream>
#include <stdarg.h>
#include <stdio.h>

#define DBG(x, ...) fprintf( stdout, "%s:%s:%s:%s:%d: " x "\n", "DBG", __TIME__,__DATE__,__func__, __LINE__, ##__VA_ARGS__)
int myprintf (const char *format, ...)
{
   va_list arg;
   int done;
 
   va_start (arg, format);
   done = vfprintf (stdout, format, arg);
   va_end (arg);
 
   return done;
}

int pipefd[2];

int main ()
{
	myprintf ("Hello %d %f %c \n", 10, 12.1, 'c');
	pipe (pipefd);

	if (fork() == 0)
	{
		// child
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		dup2(pipefd[1], 2);
		close (pipefd[1]);
		DBG("Hello %d %f %c", 10, 12.1, 'c');
	}
	else
	{
		// parent
		char buffer[1024];
		close(pipefd[1]);

		while (read(pipefd[0], buffer, sizeof(buffer)) != 0)
		{
			printf ("Read at parent msg [%s]\n", buffer);
		}
		printf ("parent exiting \n");
	}
}
