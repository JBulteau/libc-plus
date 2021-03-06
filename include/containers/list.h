#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "iterator.h"

typedef struct __list_s List;

struct __list_s {
    size_t      __size;
    void        *__data;
    void        *(*front)(void *);
    void        *(*back)(void *);
    Iterator    *(*begin)(void *);
    Iterator    *(*end)(void *);
    Iterator    *(*erase)(void *, Iterator *[]);
    Iterator    *(*insert)(void *, ...);
    bool        (*empty)(List *);
    size_t      (*size)(List *);
    void        (*clear)(List *);
    void        (*delete)(List *);
};

struct __list_bool_s {
    size_t      __size;
    bool        *__data;
    bool        (*front)(struct __list_bool_s *);
    bool        (*back)(struct __list_bool_s *);
    Iterator    *(*begin)(struct __container_s *);
    Iterator    *(*end)(struct __container_s *);
    Iterator    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator    *(*insert)(struct __container_s *, Iterator *, bool);
};

struct __list_char_s {
    size_t      __size;
    char        *__data;
    char        (*front)(struct __list_char_s *);
    char        (*back)(struct __list_char_s *);
    Iterator    *(*begin)(struct __container_s *);
    Iterator    *(*end)(struct __container_s *);
    Iterator    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator    *(*insert)(struct __container_s *, Iterator *, char);
};

struct __list_unsigned_char_s {
    size_t          __size;
    unsigned char   *__data;
    unsigned char   (*front)(struct __list_unsigned_char_s *);
    unsigned char   (*back)(struct __list_unsigned_char_s *);
    Iterator        *(*begin)(struct __container_s *);
    Iterator        *(*end)(struct __container_s *);
    Iterator        *(*erase)(struct __container_s *, Iterator *[]);
    Iterator        *(*insert)(struct __container_s *, Iterator *, unsigned char);
};

struct __list_signed_char_s {
    size_t          __size;
    signed char     *__data;
    signed char     (*front)(struct __list_signed_char_s *);
    signed char     (*back)(struct __list_signed_char_s *);
    Iterator        *(*begin)(struct __container_s *);
    Iterator        *(*end)(struct __container_s *);
    Iterator        *(*erase)(struct __container_s *, Iterator *[]);
    Iterator        *(*insert)(struct __container_s *, Iterator *, signed char);
};

struct __list_short_int_s {
    size_t          __size;
    short int       *__data;
    short int       (*front)(struct __list_short_int_s *);
    short int       (*back)(struct __list_short_int_s *);
    Iterator        *(*begin)(struct __container_s *);
    Iterator        *(*end)(struct __container_s *);
    Iterator        *(*erase)(struct __container_s *, Iterator *[]);
    Iterator        *(*insert)(struct __container_s *, Iterator *, short int);
};

struct __list_unsigned_short_int_s {
    size_t                  __size;
    unsigned short int      *__data;
    unsigned short int      (*front)(struct __list_unsigned_short_int_s *);
    unsigned short int      (*back)(struct __list_unsigned_short_int_s *);
    Iterator                *(*begin)(struct __container_s *);
    Iterator                *(*end)(struct __container_s *);
    Iterator                *(*erase)(struct __container_s *, Iterator *[]);
    Iterator                *(*insert)(struct __container_s *, Iterator *, unsigned short int);
};

struct __list_int_s {
    size_t      __size;
    int         *__data;
    int         (*front)(struct __list_int_s *);
    int         (*back)(struct __list_int_s *);
    Iterator    *(*begin)(struct __container_s *);
    Iterator    *(*end)(struct __container_s *);
    Iterator    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator    *(*insert)(struct __container_s *, Iterator *, int);
};

struct __list_long_int_s {
    size_t      __size;
    long int    *__data;
    long int    (*front)(struct __list_long_int_s *);
    long int    (*back)(struct __list_long_int_s *);
    Iterator    *(*begin)(struct __container_s *);
    Iterator    *(*end)(struct __container_s *);
    Iterator    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator    *(*insert)(struct __container_s *, Iterator *, long int);
};

struct __list_long_long_int_s {
    size_t          __size;
    long long int   *__data;
    long long int   (*front)(struct __list_long_long_int_s *);
    long long int   (*back)(struct __list_long_long_int_s *);
    Iterator        *(*begin)(struct __container_s *);
    Iterator        *(*end)(struct __container_s *);
    Iterator        *(*erase)(struct __container_s *, Iterator *[]);
    Iterator        *(*insert)(struct __container_s *, Iterator *, long long int);
};

struct __list_unsigned_int_s {
    size_t          __size;
    unsigned int    *__data;
    unsigned int    (*front)(struct __list_unsigned_int_s *);
    unsigned int    (*back)(struct __list_unsigned_int_s *);
    Iterator        *(*begin)(struct __container_s *);
    Iterator        *(*end)(struct __container_s *);
    Iterator        *(*erase)(struct __container_s *, Iterator *[]);
    Iterator        *(*insert)(struct __container_s *, Iterator *, unsigned int);
};

struct __list_unsigned_long_int_s {
    size_t              __size;
    unsigned long int   *__data;
    unsigned long int   (*front)(struct __list_unsigned_long_int_s *);
    unsigned long int   (*back)(struct __list_unsigned_long_int_s *);
    Iterator            *(*begin)(struct __container_s *);
    Iterator            *(*end)(struct __container_s *);
    Iterator            *(*erase)(struct __container_s *, Iterator *[]);
    Iterator            *(*insert)(struct __container_s *, Iterator *, unsigned long int);
};

struct __list_unsigned_long_long_int_s {
    size_t                      __size;
    unsigned long long int      *__data;
    unsigned long long int      (*front)(struct __list_unsigned_long_long_int_s *);
    unsigned long long int      (*back)(struct __list_unsigned_long_long_int_s *);
    Iterator                    *(*begin)(struct __container_s *);
    Iterator                    *(*end)(struct __container_s *);
    Iterator                    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator                    *(*insert)(struct __container_s *, Iterator *, unsigned long long int);
};

/*
** Floating point types are currently not supported because of an undefined behavior
*/

// struct __list_float_s {
//   size_t __size;
//   float *__data;
//   float (*front)(struct __list_float_s *);
//   float (*back)(struct __list_float_s *);
// };

// struct __list_double_s {
//   size_t __size;
//   double *__data;
//   double (*front)(struct __list_double_s *);
//   double (*back)(struct __list_double_s *);
// };

// struct __list_long_double_s {
//   size_t __size;
//   long double *__data;
//   long double (*front)(struct __list_long_double_s *);
//   long double (*back)(struct __list_long_double_s *);
// };

struct __list_char_pointer_s {
    size_t      __size;
    char        **__data;
    char        *(*front)(struct __list_char_pointer_s *);
    char        *(*back)(struct __list_char_pointer_s *);
    Iterator    *(*begin)(struct __container_s *);
    Iterator    *(*end)(struct __container_s *);
    Iterator    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator    *(*insert)(struct __container_s *, Iterator *, char *);
};

struct __list_int_pointer_s {
    size_t      __size;
    int         **__data;
    int         *(*front)(struct __list_int_pointer_s *);
    int         *(*back)(struct __list_int_pointer_s *);
    Iterator    *(*begin)(struct __container_s *);
    Iterator    *(*end)(struct __container_s *);
    Iterator    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator    *(*insert)(struct __container_s *, Iterator *, int *);
};

struct __list_void_pointer_s {
    size_t      __size;
    void        **__data;
    void        *(*front)(struct __list_void_pointer_s *);
    void        *(*back)(struct __list_void_pointer_s *);
    Iterator    *(*begin)(struct __container_s *);
    Iterator    *(*end)(struct __container_s *);
    Iterator    *(*erase)(struct __container_s *, Iterator *[]);
    Iterator    *(*insert)(struct __container_s *, Iterator *, void *);
};

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)

#define create_list(type, ...) __ARGS(type, ##__VA_ARGS__)

#define __ARGS(type, ...) ({ type _; __LIST_TYPE(_)(__VA_NARG(__VA_ARGS__), ##__VA_ARGS__); })
#define __LIST_TYPE(type) _Generic(type,                                                            \
                                    _Bool : create_list_bool,                                       \
                                    unsigned char : create_list_unsigned_char,                      \
                                    char : create_list_char,                                        \
                                    signed char : create_list_signed_char,                          \
                                    short int : create_list_short_int,                              \
                                    unsigned short int : create_list_unsigned_short_int,            \
                                    int : create_list_int,                                          \
                                    unsigned int : create_list_unsigned_int,                        \
                                    long int : create_list_long_int,                                \
                                    unsigned long int : create_list_unsigned_long_int,              \
                                    long long int : create_list_long_long_int,                      \
                                    unsigned long long int : create_list_unsigned_long_long_int,    \
                                    char * : create_list_char_pointer,                              \
                                    void * : create_list_void_pointer,                              \
                                    int * : create_list_int_pointer,                                \
                                    default : print_default)

#define __VA_NARG(...) (__VA_NARG_(_0, ##__VA_ARGS__, __RSEQ_N()) - 1)
#define __VA_NARG_(...) __VA_ARG_N(__VA_ARGS__)
#define __VA_ARG_N(                                     \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,            \
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,   \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,   \
    _31, _32, _33, _34, _35, _36, _37, _38, _39, _40,   \
    _41, _42, _43, _44, _45, _46, _47, _48, _49, _50,   \
    _51, _52, _53, _54, _55, _56, _57, _58, _59, _60,   \
    _61, _62, _63, N, ...) N
#define __RSEQ_N()                              \
        63, 62, 61, 60,                         \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#else

#error Not supported

#endif

static inline bool empty(List *this)
{
    return (this->__size == 0);
}

static inline size_t size(List *this)
{
    return this->__size;
}

static inline void clear(List *this)
{
    if (this->__data)
        free(this->__data);
    this->__data = NULL;
    this->__size = 0;
}

static inline void delete(List *this)
{
    if (this->__data)
        free(this->__data);
    free(this);
}

static inline void init_list(List *list)
{
    list->empty = &empty;
    list->size = &size;
    list->clear = &clear;
    list->delete = &delete;
}

static inline int helper(unsigned int n_args, ...)
{
    printf("%u argument(s):\n", n_args);

    if (n_args == 0) return 1;

    unsigned int i, arg;
    va_list ap;

    va_start(ap, n_args);
    for (i = 0; i < n_args; i++) {
        arg = va_arg(ap, unsigned int);
        printf("  %u\n", arg);
    }
    va_end(ap);
    return 0;
}

static inline bool front_bool(struct __list_bool_s *this)
{
    return this->__size ? this->__data[0] : false;
}

static inline bool back_bool(struct __list_bool_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : false;
}

static inline List *create_list_bool(unsigned int n_args, ...)
{
    struct __list_bool_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(bool) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((bool *)list->__data)[i] = va_arg(ap, int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_bool;
    list->back = &back_bool;
    list->begin = &begin_bool;
    list->end = &end_bool;
    list->erase = &erase_bool;
    list->insert = &insert_bool;
    init_list((List *)list);
    return (List *)list;
}

static inline char front_char(struct __list_char_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline char back_char(struct __list_char_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_char(unsigned int n_args, ...)
{
    struct __list_char_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(char) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((char *)list->__data)[i] = va_arg(ap, int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_char;
    list->back = &back_char;
    list->begin = &begin_char;
    list->end = &end_char;
    list->erase = &erase_char;
    list->insert = &insert_char;
    init_list((List *)list);
    return (List *)list;
}

static inline unsigned char front_unsigned_char(struct __list_unsigned_char_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline unsigned char back_unsigned_char(struct __list_unsigned_char_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_unsigned_char(unsigned int n_args, ...)
{
    struct __list_unsigned_char_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(unsigned char) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((unsigned char *)list->__data)[i] = va_arg(ap, int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_unsigned_char;
    list->back = &back_unsigned_char;
    list->begin = &begin_unsigned_char;
    list->end = &end_unsigned_char;
    list->erase = &erase_unsigned_char;
    list->insert = &insert_unsigned_char;
    init_list((List *)list);
    return (List *)list;
}

static inline signed char front_signed_char(struct __list_signed_char_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline signed char back_signed_char(struct __list_signed_char_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_signed_char(signed int n_args, ...)
{
    struct __list_signed_char_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(signed char) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((signed char *)list->__data)[i] = va_arg(ap, int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_signed_char;
    list->back = &back_signed_char;
    list->begin = &begin_signed_char;
    list->end = &end_signed_char;
    list->erase = &erase_signed_char;
    list->insert = &insert_signed_char;
    init_list((List *)list);
    return (List *)list;
}

static inline short int front_short_int(struct __list_short_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline short int back_short_int(struct __list_short_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_short_int(unsigned int n_args, ...)
{
    struct __list_short_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(short int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((short int *)list->__data)[i] = va_arg(ap, int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_short_int;
    list->back = &back_short_int;
    list->begin = &begin_short_int;
    list->end = &end_short_int;
    list->erase = &erase_short_int;
    list->insert = &insert_short_int;
    init_list((List *)list);
    return (List *)list;
}

static inline unsigned short int front_unsigned_short_int(struct __list_unsigned_short_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline unsigned short int back_unsigned_short_int(struct __list_unsigned_short_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_unsigned_short_int(unsigned int n_args, ...)
{
    struct __list_unsigned_short_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(unsigned short int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((unsigned short int *)list->__data)[i] = va_arg(ap, unsigned int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_unsigned_short_int;
    list->back = &back_unsigned_short_int;
    list->begin = &begin_unsigned_short_int;
    list->end = &end_unsigned_short_int;
    list->erase = &erase_unsigned_short_int;
    list->insert = &insert_unsigned_short_int;
    init_list((List *)list);
    return (List *)list;
}

static inline int front_int(struct __list_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline int back_int(struct __list_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_int(unsigned int n_args, ...)
{
    struct __list_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((int *)list->__data)[i] = va_arg(ap, int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_int;
    list->back = &back_int;
    list->begin = &begin_int;
    list->end = &end_int;
    list->erase = &erase_int;
    list->insert = &insert_int;
    init_list((List *)list);
    return (List *)list;
}

static inline long int front_long_int(struct __list_long_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline long int back_long_int(struct __list_long_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_long_int(unsigned int n_args, ...)
{
    struct __list_long_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(long int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((long int *)list->__data)[i] = va_arg(ap, long int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_long_int;
    list->back = &back_long_int;
    list->begin = &begin_long_int;
    list->end = &end_long_int;
    list->erase = &erase_long_int;
    list->insert = &insert_long_int;
    init_list((List *)list);
    return (List *)list;
}

static inline long long int front_long_long_int(struct __list_long_long_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline long long int back_long_long_int(struct __list_long_long_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_long_long_int(unsigned int n_args, ...)
{
    struct __list_long_long_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(long long int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((long long int *)list->__data)[i] = va_arg(ap, long long int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_long_long_int;
    list->back = &back_long_long_int;
    list->begin = &begin_long_long_int;
    list->end = &end_long_long_int;
    list->erase = &erase_long_long_int;
    list->insert = &insert_long_long_int;
    init_list((List *)list);
    return (List *)list;
}

static inline unsigned int front_unsigned_int(struct __list_unsigned_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline unsigned int back_unsigned_int(struct __list_unsigned_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_unsigned_int(unsigned int n_args, ...)
{
    struct __list_unsigned_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(unsigned int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((unsigned int *)list->__data)[i] = va_arg(ap, int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_unsigned_int;
    list->back = &back_unsigned_int;
    list->begin = &begin_unsigned_int;
    list->end = &end_unsigned_int;
    list->erase = &erase_unsigned_int;
    list->insert = &insert_unsigned_int;
    init_list((List *)list);
    return (List *)list;
}

static inline unsigned long int front_unsigned_long_int(struct __list_unsigned_long_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline unsigned long int back_unsigned_long_int(struct __list_unsigned_long_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_unsigned_long_int(unsigned int n_args, ...)
{
    struct __list_unsigned_long_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(unsigned long int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((unsigned long int *)list->__data)[i] = va_arg(ap, long int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_unsigned_long_int;
    list->back = &back_unsigned_long_int;
    list->begin = &begin_unsigned_long_int;
    list->end = &end_unsigned_long_int;
    list->erase = &erase_unsigned_long_int;
    list->insert = &insert_unsigned_long_int;
    init_list((List *)list);
    return (List *)list;
}

static inline unsigned long long int front_unsigned_long_long_int(struct __list_unsigned_long_long_int_s *this)
{
    return this->__size ? this->__data[0] : 0;
}

static inline unsigned long long int back_unsigned_long_long_int(struct __list_unsigned_long_long_int_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : 0;
}

static inline List *create_list_unsigned_long_long_int(unsigned int n_args, ...)
{
    struct __list_unsigned_long_long_int_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(unsigned long long int) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((unsigned long long int *)list->__data)[i] = va_arg(ap, long long int);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_unsigned_long_long_int;
    list->back = &back_unsigned_long_long_int;
    list->begin = &begin_unsigned_long_long_int;
    list->end = &end_unsigned_long_long_int;
    list->erase = &erase_unsigned_long_long_int;
    list->insert = &insert_unsigned_long_long_int;
    init_list((List *)list);
    return (List *)list;
}

/*
** Floating point types are currently not supported because of an undefined behavior
*/

// static inline float front_float(struct __list_float_s *this)
// {
//   return ((float *)this->__data)[0];
// }

// static inline float back_float(struct __list_float_s *this)
// {
//   return ((float *)this->__data)[this->__size - 1];
// }

// static inline List *create_list_float(unsigned int n_args, ...)
// {
//   struct __list_float_s *list = malloc(sizeof(struct __list_float_s));

//   if (!list) return NULL;

//   if (n_args) {
//     list->__data = malloc(sizeof(float) * n_args);
//     if (!list->__data) {
//       free(list);
//       return NULL;
//     }
//     va_list ap;
//     va_start(ap, n_args);
//     for (unsigned int i = 0; i < n_args; i++) {
//       ((float *) list->__data)[i] = va_arg(ap, double);
//     }
//     va_end(ap);
//   }
//   list->__size = n_args;
//   list->front = &front_float;
//   list->back = &back_float;
//   return (List *)list;
// }

// static inline double front_double(struct __list_double_s *this)
// {
//   return ((double *)this->__data)[0];
// }

// static inline double back_double(struct __list_double_s *this)
// {
//   return ((double *)this->__data)[this->__size - 1];
// }

// static inline List *create_list_double(unsigned int n_args, ...)
// {
//   struct __list_double_s *list = malloc(sizeof(struct __list_double_s));

//   if (!list) return NULL;

//   if (n_args) {
//     list->__data = malloc(sizeof(double) * n_args);
//     if (!list->__data) {
//       free(list);
//       return NULL;
//     }
//     va_list ap;
//     va_start(ap, n_args);
//     for (unsigned int i = 0; i < n_args; i++) {
//       ((double *) list->__data)[i] = va_arg(ap, double);
//     }
//     va_end(ap);
//   }
//   list->__size = n_args;
//   list->front = &front_double;
//   list->back = &back_double;
//   return (List *)list;
// }

// static inline long double front_long_double(struct __list_long_double_s *this)
// {
//   return ((long double *)this->__data)[0];
// }

// static inline long double back_long_double(struct __list_long_double_s *this)
// {
//   return ((long double *)this->__data)[this->__size - 1];
// }

// static inline List *create_list_long_double(unsigned int n_args, ...)
// {
//   struct __list_long_double_s *list = malloc(sizeof(struct __list_long_double_s));

//   if (!list) return NULL;

//   if (n_args) {
//     list->__data = malloc(sizeof(long double) * n_args);
//     if (!list->__data) {
//       free(list);
//       return NULL;
//     }
//     va_list ap;
//     va_start(ap, n_args);
//     for (unsigned int i = 0; i < n_args; i++) {
//       ((long double *) list->__data)[i] = va_arg(ap, long double);
//     }
//     va_end(ap);
//   }
//   list->__size = n_args;
//   list->front = &front_long_double;
//   list->back = &back_long_double;
//   return (List *)list;
// }

static inline char *front_char_pointer(struct __list_char_pointer_s *this)
{
    return this->__size ? this->__data[0] : NULL;
}

static inline char *back_char_pointer(struct __list_char_pointer_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : NULL;
}

static inline List *create_list_char_pointer(unsigned int n_args, ...)
{
    struct __list_char_pointer_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(char *) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((char **)list->__data)[i] = va_arg(ap, char *);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_char_pointer;
    list->back = &back_char_pointer;
    list->begin = &begin_char_pointer;
    list->end = &end_char_pointer;
    list->erase = &erase_char_pointer;
    list->insert = &insert_char_pointer;
    init_list((List *)list);
    return (List *)list;
}

static inline int *front_int_pointer(struct __list_int_pointer_s *this)
{
    return this->__size ? this->__data[0] : NULL;
}

static inline int *back_int_pointer(struct __list_int_pointer_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : NULL;
}

static inline List *create_list_int_pointer(unsigned int n_args, ...)
{
    struct __list_int_pointer_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(int *) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((int **)list->__data)[i] = va_arg(ap, int *);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_int_pointer;
    list->back = &back_int_pointer;
    list->begin = &begin_int_pointer;
    list->end = &end_int_pointer;
    list->erase = &erase_int_pointer;
    list->insert = &insert_int_pointer;
    init_list((List *)list);
    return (List *)list;
}

static inline void *front_void_pointer(struct __list_void_pointer_s *this)
{
    return this->__size ? this->__data[0] : NULL;
}

static inline void *back_void_pointer(struct __list_void_pointer_s *this)
{
    return this->__size ? this->__data[this->__size - 1] : NULL;
}

static inline List *create_list_void_pointer(unsigned int n_args, ...)
{
    struct __list_void_pointer_s *list = malloc(sizeof(List));

    if (!list) return NULL;

    if (n_args) {
        list->__data = malloc(sizeof(void *) * n_args);
        if (!list->__data) {
            free(list);
            return NULL;
        }
        va_list ap;
        va_start(ap, n_args);
        for (unsigned int i = 0; i < n_args; i++) {
            ((void **)list->__data)[i] = va_arg(ap, void *);
        }
        va_end(ap);
    } else {
        list->__data = NULL;
    }
    list->__size = n_args;
    list->front = &front_void_pointer;
    list->back = &back_void_pointer;
    list->begin = &begin_void_pointer;
    list->end = &end_void_pointer;
    list->erase = &erase_void_pointer;
    list->insert = &insert_void_pointer;
    init_list((List *)list);
    return (List *)list;
}

static inline int print_default(unsigned int n_args, ...)
{
    printf("%u argument(s):\n", n_args);

    if (n_args == 0) return 1;

    printf("  Unknown type\n");
    return 0;
}

#endif