#ifndef _HELPERS_H_
#define _HELPERS_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* getl(char *prompt);
void say(char *message);
void die(int code, char *message);
#endif