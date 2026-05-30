#include "error_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void error(ERROR_T type, char *message, bool abort) {

    switch (type)
    {
        case ERROR: // ERROR 
            char *type_and_file = ANSI_COLOR_RED"(ERROR)-:"ANSI_COLOR_RESET;
            char *type_and_message = malloc(strlen(type_and_file) + strlen(message) +1);
            sprintf(type_and_message, "%s%s", type_and_file, message);
            perror(type_and_message);

            free(type_and_message);
            break;
        case WARNING: 
            printf(ANSI_COLOR_YELLOW "(WARNING)-" ANSI_COLOR_RESET);
            break;
        case DEBUG: 
            printf(ANSI_COLOR_CYAN "(DEBUG)-" ANSI_COLOR_RESET);
            break;
        case INFO: 
            printf(ANSI_COLOR_BLUE "(INFO)-"  ANSI_COLOR_RESET);
            break;
        case SUCCESS:
            printf(ANSI_COLOR_GREEN "(SUCCESS)-" ANSI_COLOR_RESET);
            break;
        case OTHER:
            printf(ANSI_COLOR_MAGENTA "(OTHER)-" ANSI_COLOR_RESET);
            break;
    }

    

    
    if (type != ERROR) {
        printf("%s\n", message);
    }

    if (abort == true) {
        exit(1);
    }
}