#include "main.h"
#include <errno.h>
#include <string.h>
/**
 *
 *
 *
 */

int main(int ac, char **av)
{
	int i = 1;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

/*	while(av[i] != NULL)
	{
		printf("%s ", av[i]);
		i++;
	} */
	while (read != -1)
	{
		printf("\n$ ");
		read = getline (&line, &len, stdin);
		printf("%s\n", line, read);
	}
		
	if (read = -1)
		printf("%d\n",errno);
	return (0);
}
