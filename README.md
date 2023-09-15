# Hello, World!

This repository is an exercise in learning the C programming language. Not just
the language itself but various idioms and approaches. The focus will be on the
kernel code. As it is the biggest C codebase known to me.

This version shows how various APIs are implemented in C. Have a look at the
greeter API. Often for more complex functionality you will see an idiom where
API implementation functions will only be a wrapper around other functions that
are conventionally prepended with one or or two underscores2 (i.e.
`say_hello_fn()` would call another function `_say_hello_function()` ). This has
several uses; generally it relates to having simpler and smaller parts of the
API (marshalling or checking arguments, for example) separate from more complex
implementation, which often eases the path to significant changes in the
internal workings whilst ensuring the API remains constant. Our implementation
is very simple, however, and doesn't even need its own support functions. In
various projects, single-, double- or even triple-underscore function prefixes
will mean different things, but universally it is a visual warning that the
function is not supposed to be called directly from "beyond" the API.

Refences: https://www.bottomupcs.com/csbu.pdf
