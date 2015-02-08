#ifndef _UNIQUE_ID_H_
#define _UNIQUE_ID_H_
#define _UNIQUE_ID_GUID_LENGTH 37
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

char *guid_new();

char *guid_to_str(const GUID *id, char *out);
#endif