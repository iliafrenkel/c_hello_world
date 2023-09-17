/* Copyright 2023 Ilia Frenkel. All rights reserved.
   Use of this source code is governed by a MIT-style
   license that can be found in the LICENSE.txt file. */

#include "include/greeter.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50

/*
 * Prints a greeting and returns.
 * Function : int main(void)
 * Input    : none
 * Output   : Returns 0 on success
 */
int main(int argc, char *argv[]) {
    char name[MAX_NAME_SIZE]; // The name to greet

    /*
     * We expect the name to great as a command line parameter.
     * If it's not there, we ask for it.
     */
    if (argc < 2) {
        printf("Your name: ");
        if (fgets(name, MAX_NAME_SIZE, stdin) == NULL) {
            printf("\rCouldn't read the user input: ");
            if (feof(stdin) != 0) {
                printf("unexpected end of file.\n");
            } else if (ferror(stdin) != 0) {
                printf("error while reading from a file.\n");
            }
            clearerr(stdin);
            return -1;
        }
        /* Remove the '\n' at the end */
        const unsigned int len = strlen(name);
        if (len > 0) {
            name[len - 1] = '\0';
        }
        printf("\n");
    } else {
        strncpy(name, argv[1], MAX_NAME_SIZE);
    }
    greeter_api.say_hello(name);
    greeter_api.say_goodbye();

    return 0;
}
