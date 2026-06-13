#include "command.h"
#include "config.h"
#include "./lib/error_handler/error_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char  *input = malloc(100 +1);
    bool running = true;
    

    printf("\033[2J\033[H");

    CONFIG config = get_config();

    printf("%s", config.welcome_message);
    while (running == true) {
        

        printf("%s", config.prompt);

        fgets(input, 100, stdin);

        int parsed_size = strcspn(input, "\n");
        input[parsed_size] = '\0';
        
        char **args = parse_command(input);

        
        int exit_code = run_command(args);
        config = get_config();
        if (exit_code < 0) {
            running = false;
        }
    }
    
}