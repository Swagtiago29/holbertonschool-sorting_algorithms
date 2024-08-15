#include "main.h"
/**
 *
 *
 *
 */
int main(char **tokk)
{
	int i = 0;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	const char delim[] = " ";
	pid_t child;
	int status;

	while (1)
	{
		printf("\n$ ");
		read = getline (&line, &len, stdin);
		if (read == -1)
			printf("error");
		child = fork();
		if (child == 0)
		{
			execve(comm[0], comm, NULL);	
		}
		else
			wait(&status);
	}
	return (0);
}
