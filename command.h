#ifndef COMMAND_H
#define COMMAND_H


typedef enum  {
        QUIT,
        CLEAR,
} COMMAND;

char **parse_command(char input[]);
int run_command(char **args);

#endif