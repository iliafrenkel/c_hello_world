/* Copyright 2023 Ilia Frenkel. All rights reserved.
   Use of this source code is governed by a MIT-style
   license that can be found in the LICENSE.txt file. */

#include <stdio.h>

/*
 * Returns a greeting as a string.
 */
char *greeting() { return "Hello, World!\n"; }

/*
 * Prints a greeting and returns.
 * Function : int main(void)
 * Input    : none
 * Output   : Returns 0 on success
 */
int main(void) {
    printf("%s", greeting());
    return 0;
}
