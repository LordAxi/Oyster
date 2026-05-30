#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    char *prompt;
    char *welcome_message;
} CONFIG;
CONFIG get_config(void);



#endif