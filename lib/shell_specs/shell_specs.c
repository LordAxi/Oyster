#include "shell_specs.h"
#include "../../version.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>

char *get_shell_spec(char *search) {
    char *result;
    if (strcmp(search, "HOSTNAME") == 0) {
        struct utsname hostname;

        if (uname(&hostname) == 0) {
            result = malloc(strlen(hostname.nodename) +1);
            strcpy(result, hostname.nodename);
            return result;
        }
    }
    else if (strcmp(search, "VERSION") == 0) {
        return version;
    }
    else if (strcmp(search, "WORKING_DIR") == 0) {
        return getcwd(NULL, 0);
    }
    return NULL;
}