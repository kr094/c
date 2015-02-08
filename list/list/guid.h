#ifndef _GUID_H_
#define _GUID_H_
#define _GUID_LENGTH_ 37

#ifdef _WIN32
#include "guid.win.h"
#endif

char *guid_new();
#endif