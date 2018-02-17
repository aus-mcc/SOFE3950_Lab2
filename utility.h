/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_
#include "utility.c"

// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following example:
// extern void display_help(void);

extern void com_cd(char *PATH);
extern void com_clr(void);
extern void com_dir(char a[]);
extern void com_environ(void);
extern void com_echo(char *arg);
extern void com_pause(void);
extern void com_help(void);


#endif /* UTILITY_H_ */