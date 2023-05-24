#ifndef _LOGGER_H_
#define _LOGGER_H_

#define LM_NOLOG 0
#define LM_DEADLY 1
#define LM_ERROR 2
#define LM_INFO 3
#define LM_DEBUG 4

#define LOG_DEADLY(...) logger(LM_DEADLY, __VA_ARGS__)
#define LOG_ERROR(...) logger(LM_ERROR, __VA_ARGS__)
#define LOG_INFO(...) logger(LM_INFO, __VA_ARGS__)
#define LOG_DEBUG(...) logger(LM_DEBUG, __VA_ARGS__)

void logger(int level, const char* format, ...);

#endif