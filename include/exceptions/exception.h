#ifndef _EXCEPTION_H__
#define _EXCEPTION_H__

#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

jmp_buf     buffer;
jmp_buf     __old_buffer;
int         __error;

typedef struct {
    size_t    __size__;
    char      *__name__;
    int       __error__;
    char      *what;
}   ExceptionClass;

typedef struct {
    char    *name;
    char    *function;
    char    *file;
    int     line;
    char    *what;
} __internal_exception_t;

__internal_exception_t __internal_exception;

#define RegisterException(exception) \
    static ExceptionClass __DECL_(__LINE__) = { \
        .__size__ = sizeof(ExceptionClass), \
        .__name__ = #exception, \
        .__error__ = __COUNTER__, \
        .what = #exception \
    }; \
    ExceptionClass *exception = &__DECL_(__LINE__);

#define try \
    __old_buffer[0] = buffer[0]; \
    __error = setjmp(buffer); \
    if (__error == 0)

#define catch(exception) \
    buffer[0] = __old_buffer[0]; \
    if (exception->__error__ != __error) { \
        longjmp(buffer, __error); \
    } else

#define throw(exception, what) __throw(__func__, __FILE__, __LINE__, what, exception)

static inline void __throw(const char *function, const char *file, int line, const char *what, ExceptionClass *exception)
{
    __internal_exception.name = strdup(exception->__name__);
    __internal_exception.function = strdup(function);
    __internal_exception.file = strdup(file);
    __internal_exception.line = line;
    __internal_exception.what = strdup(what);
    longjmp(buffer, exception->__error__);
}

RegisterException(__void__)
RegisterException(Exception)

void __attribute__((constructor)) init()
{
    int error = setjmp(buffer);

    if (error != 0) {
        dprintf(2, "Exception %s thrown in function '%s' (%s at line %i): \"%s\"\n", __internal_exception.name, __internal_exception.function, __internal_exception.file, __internal_exception.line, __internal_exception.what);
        exit(error);
    }
}

#endif