#ifndef _GUID_WIN_H_
#define _GUID_WIN_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

char *guid_new();
char *guid_to_str(const GUID *id, char *out);
#endif