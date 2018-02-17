/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */

#ifndef MYSHELL_H_
#define MYSHELL_H_

// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following example:
// extern void display_help(void);
extern void cmd_cd(char *PATH);
extern void cmd_clr(void);
extern void cmd_dir(void);
extern void cmd_environ(void);
extern void cmd_echo(char *a);
extern void cmd_pause(void);
extern void cmd_help(void);

#endif /* MYSHELL_H_ */