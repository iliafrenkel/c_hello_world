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

extern struct greeter_api greeter_api;

#endif // !GREETER_H
