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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file
#define BUFFER_LEN 256
#define RESET "\x1B[0m"
#define GRN   "\x1B[32m"
#define RED   "\x1B[31m"
#define BLU   "\x1B[34m"

 // cd command -- change the current directory ***
        void com_cd(char *PATH)
        {
            getcwd(PATH, sizeof(PATH));
            printf("The current work directory is: %s\n", PATH);
        }

        // Clr command
        void com_clr(void){
            system("clear");
        }

        // Dir command 
        void com_dir(char a[]){
            
            char sys_call[sizeof(a)+5];
            strcpy(sys_call, "ls \"");
            strcat(sys_call, a);
            strcat(sys_call, "\"");
            system(sys_call);
        }

        // Environ command
        void com_environ(void){
            extern char **envi;
            int i = 0;
            while(envi[i] != NULL){
                printf("%s\n", envi[i]);
                i++;
            }
        }

        // Echo command
        void com_echo(char *arg){
            printf(BLU "%s\n" RESET, arg);
        }

        // Pause command
        void com_pause(void){
            printf("Hit the 'enter' key to resume");
            getchar(); 
        }

        // Help Command
        void com_help(void){
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
