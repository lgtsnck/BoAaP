#include "my_string.h"

char* my_strchr(const char* s, int c) {
    while (*s != (char)c) {
        if (!*s) return NULL;
        s++;
    }
    return (char*)s;
}

char* my_strstr(const char* haystack, const char* needle) {
    if (!*needle) return (char*)haystack;
    for (; *haystack; haystack++) {
        if (*haystack == *needle) {
            const char *h = haystack, *n = needle;
            while (*h && *n && *h == *n) {
                h++; n++;
            }
            if (!*n) return (char*)haystack;
        }
    }
    return NULL;
}

char* my_strlwr(char* s) {
    char* p = s;
    while (*p) {
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p + 32; // Сдвиг по таблице ASCII
        }
        p++;
    }
    return s;
}
