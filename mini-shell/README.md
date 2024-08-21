# Our Simple Shell

## Description
The Simple Shell is a basic command-line interface program that prints a welcome message and allows users to input commands. The shell tokenizes the input and executes commands using the `fork` and `execve` system calls.

## Functions
- **`print_user`:** Outputs a welcome message and returns the number of command-line arguments.
- **`tokenize`:** Splits the input string into tokens based on the given delimiter and returns an array of these tokens.
- **`syn`:** Forks function given and executes commands, prints error if unsuccesful.
- **`main`:** Handles the shell’s main loop, displays a prompt, processes user input. Includes basic exit functionality.

## Flowchart
![shell_flowchart](https://github.com/user-attachments/assets/54b6f838-b100-422f-b555-68aff5685b73)

## Usage
To use the Simple Shell, compile with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh` and run the program. It will prompt you for command input. Enter a command, and the shell will tokenize the input and execute it.

### Example
```
$ ./hsh
Welcome, thank you for using my shell! <3
$ bin/ls -l -a
