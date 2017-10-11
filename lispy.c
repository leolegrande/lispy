#include <stdio.h>
#include <stdlib.h> 

/* If we are compiling on Windows, compile these functions */

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt){
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

/* Fake add_history function */

void add_history(char* unused) {}

/* Otherwise include the editline headers */

#else
// editline for better input functionality
#include <editline/readline.h>
#include <histedit.h>
#endif

/* Declare a buffer for user input */
//static char input[2048];

int main(int argc, char** argv){

    /* print version and Exit Information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    /* In a never ending loop */
    while (1) {

        /* Output prompt and get input */
        char* input = readline("lispy> ");

        /*Add input to history */
        // history acts as a stack
        // allows for up and down arrow keys to browse history
        add_history(input);

        /* Echo input back to user */
        printf("No you're a %s\n", input);

        /* Free retrieved input */
        free(input);
    }
    return 0;
}
