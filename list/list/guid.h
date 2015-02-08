#ifndef _GUID_H_
#define _GUID_H_
#define _GUID_LENGTH_ 37
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

char *guid_new();

char *guid_to_str(const GUID *id, char *out);
#endif