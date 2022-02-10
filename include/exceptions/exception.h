#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

jmp_buf     __buffer;
jmp_buf     __old_buffer;
int         __error;

typedef struct {
    size_t      __size;
    char        *__name;
    int         __error;
    char        *what;
} ExceptionClass;

typedef struct {
    char    *name;
    char    *function;
    char    *file;
    int     line;
    char    *what;
} __internal_exception_t;

__internal_exception_t __internal_exception;

#define RegisterException(exception)            \
    static ExceptionClass __DECL(__LINE__) = { \
        .__size = sizeof(ExceptionClass),       \
        .__name = #exception,                   \
        .__error = __COUNTER__,                 \
        .what = #exception};                    \
    ExceptionClass *exception = &__DECL(__LINE__);

#define try                         \
    __old_buffer[0] = __buffer[0];  \
    __error = setjmp(__buffer);     \
    if (__error == 0)

#define catch(exception)                                    \
    __buffer[0] = __old_buffer[0];                          \
    exception->what = __internal_exception.what;            \
    if (exception->__error != __error && __error != 0) {    \
        longjmp(__buffer, __error);                         \
    } else if (__error != 0)

#define throw(exception, what) __throw(__func__, __FILE__, __LINE__, what, exception)

static inline void __throw(const char *function, const char *file, int line, const char *what, ExceptionClass *exception)
{
    free(__internal_exception.name);
    free(__internal_exception.function);
    free(__internal_exception.file);
    free(__internal_exception.what);
    __internal_exception.name = strdup(exception->__name);
    __internal_exception.function = strdup(function);
    __internal_exception.file = strdup(file);
    __internal_exception.line = line;
    __internal_exception.what = strdup(what);
    longjmp(__buffer, exception->__error);
}

RegisterException(__void__)
RegisterException(Exception)

void __attribute__((constructor)) init()
{
    int error = setjmp(__buffer);

    if (error != 0) {
        dprintf(2, "Exception %s thrown in function '%s' (%s at line %i): \"%s\"\n", __internal_exception.name, __internal_exception.function, __internal_exception.file, __internal_exception.line, __internal_exception.what);
        exit(error);
    }
}

void __attribute((destructor)) dispose()
{
    free(__internal_exception.name);
    free(__internal_exception.function);
    free(__internal_exception.file);
    free(__internal_exception.what);
}

#endif