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




int main(int argc, char *argv[], char *envp[])
{
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    getcwd(PATH, sizeof(PATH));

    // Parse the commands provided using argc and argv
    printf("%s %s", PATH, PROMPT);

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {   
        
        // Perform string tokenization to get the command and argument
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
        size_t ln = strlen(arg) - 1;
		if (*arg && arg[ln] == '\n') 
			arg[ln] = '\0';

      

        // Check the command and execute the operations for each command
        
        // cd command -- change the current directory ***
        if (strcmp(command, "cd") == 0)
        {
            getcwd(PATH, sizeof(PATH));
            printf("The current work directory is: %s\n", PATH);
        }

        // Clr command
        else if(strcmp(command, "clr") == 0){
            system("clear");
        }

        // Dir command 
        else if(strcmp(command, "dir") == 0){
            
            /*struct dirent *dir;
            DIR *d;
            const char *pt;
            pt = argv[1];

            if(argc<2){
                printf("Failed to specify directory");
            }

            d = opendir(pt);

            if(d == NULL){
                printf("Failed to open directory");
            }
            printf("\n");
            while((dir = readdir(d)) != NULL){
                printf(RED "[%s]\n" RESET, dir->d_name);
            }
            closedir(d);*/
            char sys_call[sizeof(arg)+5];
            strcpy(sys_call, "ls \"");
            strcat(sys_call, arg);
            strcat(sys_call, "\"");
            system(sys_call);
        }

        // Environ command
        else if(strcmp(command, "environ") == 0){
            while(*envp){
                printf("%s\n", *envp++);
            }
        }

        // Echo command
        else if(strcmp(command, "echo") == 0){
            printf(BLU "%s" RESET, arg);
        }

        // Pause command
        else if(strcmp(command, "pause") == 0){
            printf("Hit the 'enter' key to resume");
            getchar(); 
        }

        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Help Command
        else if (strcmp(command, "help") == 0){
            char c;
            FILE *file;
            file = fopen("README.md", "r");
            if (file) {
                while ((c = getc(file)) != EOF){
                    printf(BLU  "%c" RESET , c);
                }
            fclose(file);
            }
        }

        // Unsupported command
        else
        {
            fputs(RED "Unsupported command, use help to display the manual\n" RESET, stderr);
         
        }
    printf("%s %s", PATH, PROMPT);
    }
    return EXIT_SUCCESS;
}
