#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H


typedef enum {
    ERROR,
    WARNING,
    DEBUG,
    INFO,
    SUCCESS,
    OTHER
} ERROR_T;

void error(ERROR_T type, char *message, bool abort);

#endif