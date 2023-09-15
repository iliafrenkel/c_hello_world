/* Copyright 2023 Ilia Frenkel. All rights reserved.
   Use of this source code is governed by a MIT-style
   license that can be found in the LICENSE.txt file. */

#include "include/greeter.h"
#include <stdio.h>

/*
 * Prints a greeting and returns.
 * Function : int main(void)
 * Input    : none
 * Output   : Returns 0 on success
 */
int main(int argc, char *argv[]) {
    // TODO: Check if we have at least one argument.
    struct greeter_api greeter_api = {.say_hello = say_hello_fn,
                                      .say_goodbye = say_goodbye_fn};
    greeter_api.say_hello(argv[1]);
    greeter_api.say_goodbye();
    return 0;
}
