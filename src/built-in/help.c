
#include <sh.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void print_help() {
    printf("Welcome to the Linux minishell!\n");
    printf("Available commands:\n");
    printf("1. help - Display this help message\n");
    printf("2. exit - Exit the minishell\n");
    printf("3. Any Linux command available in your system\n");
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    int num_args;

    while (1) {
        printf("minishell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from the end
        command[strcspn(command, "\n")] = 0;

        // Tokenize the command string
        num_args = 0;
        args[num_args++] = strtok(command, " ");
        while ((args[num_args++] = strtok(NULL, " ")) != NULL);

        // Handle the "help" command
        if (strcmp(args[0], "help") == 0) {
            print_help();
            continue;
        }

        // Handle the "exit" command
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting minishell...\n");
            break;
        }

        // Fork a child process to execute the command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL); // Wait for child to terminate
        }
    }

    return 0;
}

