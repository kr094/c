#include "guid.h"

char *guid_new() {
	GUID pguid;
	HRESULT res;
	char guid[37];
	char *string = (char *) malloc(sizeof(char) * _UNIQUE_ID_GUID_LENGTH);

	if(!string)
		return NULL;

	res = CoCreateGuid(&pguid);

	if(res == S_OK) {
		guid_to_str(&pguid, guid);
	}

	strcpy(string, guid);

	return string;
}

/* 128 bit GUID to human-readable string 
http://stackoverflow.com/questions/21431047/how-to-convert-guid-to-char
*/
char *guid_to_str(const GUID *id, char *out) {
    int i;
    char *ret = out;

	out += sprintf(out, "%.8lX-%.4hX-%.4hX-", id->Data1, id->Data2, id->Data3);
    for (i = 0; i < sizeof(id->Data4); ++i) {
		out += sprintf(out, "%.2hhX", id->Data4[i]);
        if (i == 1) *(out++) = '-';
    }

    return ret;
}