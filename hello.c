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
 * Gets a string from stdin and returns without the trailing '\n'.
 * Function : void get_name(char *pszName, int buffSize)
 * Input:
 *     - char *pszName, a buffer to put the user input in
 *     - int buffSize, size of the buffer
 * Output: none
 */
void get_name(char *pszName, size_t buffSize) {
    if (!pszName || buffSize < 1) {
        return; // We need a proper buffer to operate.
    }
    /*
     * Use `fgets` to get the user input because `gets` and `scanf` are
     * considered unsafe. They don't check for the length of the input!
     */
    if (fgets(pszName, buffSize, stdin) == NULL) {
        if (feof(stdin) != 0) {
            printf("\n\tError: unexpected end of file.\n");
        } else if (ferror(stdin) != 0) {
            perror("\n\tError");
        }
        clearerr(stdin);
        return;
    }
    /* Remove the '\n' at the end */
    const unsigned int len = strlen(pszName);
    if (len > 0) {
        pszName[len - 1] = '\0';
    }
}

/*
 * Prints a greeting and returns.
 * Function : int main(void)
 * Input    : none
 * Output   : Returns 0 on success
 */
int main(int argc, char *argv[]) {
    char name[MAX_NAME_SIZE]; // The name to greet

    /*
     * We expect the name to greet as a command line parameter.
     * If it's not there, we ask for it.
     */
    if (argc < 2) {
        printf("Your name: ");
        get_name(name, MAX_NAME_SIZE);
        if (strlen(name) == 0) {
            greeter_api.say_goodbye();
            return 0;
        }
    } else {
        strncpy(name, argv[1], MAX_NAME_SIZE);
    }

    /*
     * Use our greeter API to greet the user.
     * This is the main point of the current version.
     * Everything else up to this point was just fluff.
     */
    greeter_api.say_hello(name);
    greeter_api.say_goodbye();

    return 0;
}
