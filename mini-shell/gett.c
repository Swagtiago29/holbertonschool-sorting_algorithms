#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h> 
/**
*
*
*
*/

int main(void)
{
	pid_t my_pid;
	pid_t dad_pid;

	my_pid = getpid();
	dad_pid = getppid();
	printf ("%u & %u\n", my_pid, dad_pid);
	return (0);
}
