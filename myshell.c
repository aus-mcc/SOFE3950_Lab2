/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define RESET "\x1B[0m"
#define GRN   "\x1B[32m"
#define RED   "\x1B[31m"
#define BLU   "\x1B[34m"


// Put global environment variables here
const char PROMPT[] = GRN ">>"RESET;
char PATH[BUFFER_LEN];

// Define functions declared in myshell.h here

void tokenization(char *buffer, char *command, char *arg){
    char *token;
    token = strtok(buffer, " \n");
    printf("You entered: " GRN "%s" RESET"\n", token);
    int n = 0;
    while(token){
        if(n==0){
            strcpy(command, token);
        }
        else{
            strcpy(arg, token);
        }
        n++;
        token = strtok(NULL, " ");
    }
}

void executables(char *command, char *arg){
    if(strcmp(command, "cd") == 0){
        com_cd(arg);
    }
    else if(strcmp(command, "clr") == 0){
        com_clr();
    }
    else if(strcmp(command, "dir") == 0){
        com_dir(arg);
    }
    else if(strcmp(command, "environ") == 0){
        com_environ();
    }
    else if(strcmp(command, "echo") == 0){
        com_echo(arg);
    }
    else if(strcmp(command, "pause") == 0){
        com_pause();
    }
    else if(strcmp(command, "help") == 0){
        com_help();
    }
    // quit command -- exit the shell
    else if (strcmp(command, "quit") == 0)
    {
        return EXIT_SUCCESS;
    }
    else{ 
        fputs(RED "Unsupported command, use help to display the manual\n" RESET, stderr);
    }
}

void file_based(char *arg){
    char file_command[BUFFER_LEN] = {0};
    char file_arg[BUFFER_LEN] = {0};

    FILE *bat;

    char ln[BUFFER_LEN];

    bat = fopen(arg, "r");

    if(bat == NULL){
        printf("Could not read file");
    }
    else{
        while(fgets(ln, BUFFER_LEN, bat)){
            tokenization(ln, file_command, file_arg);
            executables(file_command, file_arg);
        }
        fclose(bat);
    }
}


int main(int argc, char *argv[], char *envp[])
{
   
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    if(argc ==2){
        file_based(argv[1]);
    }
    else{

        getcwd(PATH, sizeof(PATH));
        printf("%s %s", PATH, PROMPT);
    
        // Perform an infinite loop getting command input from users
        while (fgets(buffer, BUFFER_LEN, stdin) != NULL){
            tokenization(buffer, command, arg);   
            executables(command, arg);
            printf("%s %s", PATH, PROMPT);
        }
        return EXIT_SUCCESS;
    }
}

