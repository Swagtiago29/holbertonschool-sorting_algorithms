#include "main.h"
/**
 *
 *
 *
 */
char **tokenize(char *line, const char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (tokens == NULL)
	{
		perror("malloc");
		exit (EXIT_FAILURE);
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
int main(void)
{
	int i = 0;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	const char delim[] = " ";
	pid_t child_pid;
	int status;
	char **comm;

	while (1)
	{
		printf("\n$ ");
		read = getline (&line, &len, stdin);
		if (read == -1)
			printf("error");
		comm = tokenize(line, delim);
		child_pid = fork();
		if (child_pid  == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			printf("child\n");
			printf("%s",comm[0]);
			execve(comm[0], comm, NULL);
			perror("execve");
			printf("child2");
		}
		else
		{	
			wait(&status);
			printf("aa");
		}
	}
	return (0);
}
