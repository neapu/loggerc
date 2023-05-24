#include "logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1) : __FILE__)

void logger(int level, const char* format, ...)
{
    int formatLen;
    char* buf;
    const char* flags = NULL;
    switch (level) {
    case LM_DEADLY: flags = "DEADLY"; break;
    case LM_ERROR: flags = "ERROR"; break;
    case LM_INFO: flags = "INFO"; break;
    case LM_DEBUG: flags = "DEBUG"; break;
    default:return;
    }

    formatLen = strlen(format);
    buf = (char*)malloc(formatLen + 1024);
    if (buf == NULL) {
        perror("malloc failed");
        return;
    }

    sprintf(buf, "[%s][%s:%d][%s]", flags, __FILENAME__, __LINE__, __FUNCTION__);
    strcat(buf, format);

    va_list args;
    va_start(args, format);

    if (level <= LM_ERROR) {
        vfprintf(stderr, buf, args);
    } else {
        vfprintf(stdout, buf, args);
    }

    va_end(args);

    free(buf);
}