#include "config.h"
#include "./lib/error_handler/error_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/toml17/tomlc17.h"

typedef struct {
    const char* key;
    char** target_ptr; 
} ConfigMapping;


CONFIG get_config(void) {
    CONFIG config;

    char *home = getenv("HOME"); //!can be null implement error / fallback etc.

    if (home == NULL) {
        error(ERROR, "Home folder could NOT be automatically identified", true);
    }
    char *file = "/.config/lsh/lsh.toml";

    char *file_path = malloc(strlen(home) + strlen(file) +1);
    sprintf(file_path, "%s%s", home, file);

    toml_result_t result = toml_parse_file_ex(file_path);

    if (!result.ok) {
        toml_free(result);
        error(WARNING, "Parsing of the config file failed", true);
        // TODO: implement fallback
        
        return config;
    }
    

    ConfigMapping mappings[] = {
        {"prompt",          &config.prompt},
        {"welcome_message", &config.welcome_message},
        
        {NULL,              NULL} 
    };

    for (int i = 0; mappings[i].key != NULL; i++) {
        
        toml_datum_t buffer = toml_seek(result.toptab, mappings[i].key);
        

        if (buffer.type == TOML_STRING) {
            
            *mappings[i].target_ptr = malloc(strlen(buffer.u.s) + 1);
            if (*mappings[i].target_ptr != NULL) {
                strcpy(*mappings[i].target_ptr, buffer.u.s);
            }
        }
    }
    

    toml_free(result);
    
    return config;
}
