#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define INITIAL_SIZE 64

char **tokenize(char *line, const char *delim) {
    char **tokens = malloc(sizeof(char *) * INITIAL_SIZE);
    char *token;
    int size = INITIAL_SIZE;
    int i = 0;

    if (tokens == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, delim);
    while (token != NULL) {
        if (i >= size) {
            size *= 2;
            tokens = realloc(tokens, sizeof(char *) * size);
            if (tokens == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL; // NULL-terminate the array

    return tokens;
}

void free_tokens(char **tokens) {
    char **ptr = tokens;
    while (*ptr) {
        free(*ptr);
        ptr++;
    }
    free(tokens);
}

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    const char delim[] = " ";
    pid_t child_pid;
    int status;
    char **comm;

    while (1) {
        printf("\n$ ");
        read = getline(&line, &len, stdin);
        if (read == -1) {
            perror("getline");
            free(line);
            exit(EXIT_FAILURE);
        }

        // Remove newline character if present
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }

        comm = tokenize(line, delim);
        if (comm[0] == NULL) {
            free_tokens(comm);
            continue; // No command entered
        }

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            free_tokens(comm);
            free(line);
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            // Child process
            printf("%s\n", comm[0]);
            execvp(comm[0], comm); // execvp is often used instead of execve for simplicity
            perror("execvp"); // execvp returns only on error
            free_tokens(comm);
            free(line);
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(&status);
            printf("after wait\n");
            free_tokens(comm);
        }
    }

    free(line);
    return 0;
}
