#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdlib.h>

void parent_child_example (bool is_parent_sleep, int var)
{
	pid_t pid;

	printf ("Before calling fork, var: %d \n", var);

	if ((pid = fork ()) < 0)
	{
		printf ("fork () system call failed \n");
	}
	else if (pid == 0)
	{
		if (!is_parent_sleep)
			sleep (2);
		var++;
		printf ("Child process modified var value: %d, parent process: %d, own pid: %d \n", 
				var, getppid (), getpid ());
		exit (10);
	}
	else
	{
		if (is_parent_sleep)
			sleep (2);
		var++;
		printf ("parent process modified var value: %d, child process id: %d, own pid: %d \n",
				var, pid, getpid ());
		/* To ensure child exits first*/
		if (!is_parent_sleep)
			sleep (3);
		printf ("Parent process received returned value of wait %d\n", wait (&pid));
	}
}

int main ()
{
	printf ("Below example when parent sleeps\n");
	parent_child_example (true, 100);
	sleep (5);
	printf ("Below example when child sleeps\n");
	parent_child_example (false, 200);
}