/* Copyright 2023 Ilia Frenkel. All rights reserved.
   Use of this source code is governed by a MIT-style
   license that can be found in the LICENSE.txt file. */

#ifndef GREETER_H
#define GREETER_H

/* The greeter API */
struct greeter_api {
    int (*say_hello)(char *);
    int (*say_goodbye)(void);
};

int say_hello_fn(char *name);
int say_goodbye_fn(void);

#endif // !GREETER_H
