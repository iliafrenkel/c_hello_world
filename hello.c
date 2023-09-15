/* Copyright 2023 Ilia Frenkel. All rights reserved.
   Use of this source code is governed by a MIT-style
   license that can be found in the LICENSE.txt file. */

#include <stdio.h>

/* The greeter API */
struct greeter_api {
    int (*say_hello)(char *);
    int (*say_goodbye)(void);
};

/* Implementation of the greeter API */

/*
 * Prints a greeting for a given name.
 */
int say_hello_fn(char *name) {
    printf("Hello, %s!\n", name);
    return 0;
}

/*
 * Prints a goodbye.
 */
int say_goodbye_fn(void) {
    printf("Sayōnara!\n");
    return 0;
}

struct greeter_api greeter_api = {.say_hello = say_hello_fn,
                                  .say_goodbye = say_goodbye_fn};

/*
 * Prints a greeting and returns.
 * Function : int main(void)
 * Input    : none
 * Output   : Returns 0 on success
 */
int main(int argc, char *argv[]) {
    greeter_api.say_hello(argv[1]);
    greeter_api.say_goodbye();
    return 0;
}
