#ifndef _LIST_H__
#define _LIST_H__

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)

#define init(type, ...)  __ARGS_(type, __VA_ARGS__)

#define __ARGS_(type, ...) { type _; __TYPE_(_)(__VA_NARG__(__VA_ARGS__), ##__VA_ARGS__); }
#define __TYPE_(type) _Generic(type,                                                 \
        _Bool: print_bool,                  unsigned char: print_unsigned_char,          \
            char: print_char,                     signed char: print_signed_char,            \
    short int: print_short_int,         unsigned short int: print_unsigned_short_int,     \
            int: print_int,                     unsigned int: print_unsigned_int,           \
        long int: print_long_int,           unsigned long int: print_unsigned_long_int,      \
long long int: print_long_long_int, unsigned long long int: print_unsigned_long_long_int, \
        float: print_float,                         double: print_double,                 \
    long double: print_long_double,                   char *: print_char_pointer,        \
        void *: print_void_pointer,                int *: print_int_pointer,         \
        default: print_default)

#define __VA_NARG__(...) \
(__VA_NARG_(_0, ##__VA_ARGS__, __RSEQ_N()) - 1)
#define __VA_NARG_(...) \
__VA_ARG_N(__VA_ARGS__)
#define __VA_ARG_N( \
_1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
_11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
_21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
_31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
_41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
_51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
_61,_62,_63,N,...) N
#define __RSEQ_N() \
63, 62, 61, 60, \
59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#elif defined(__GNUC__)

#error not supported yet

#define N_ARGS(args...) N_ARGS_HELPER1(args, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define N_ARGS_HELPER1(args...) N_ARGS_HELPER2(args)
#define N_ARGS_HELPER2(x1, x2, x3, x4, x5, x6, x7, x8, x9, n, x...) n

#define template(args...) helper(N_ARGS(args), args)

#else

#error variadic macros for your compiler here

#endif

static inline void helper(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i, arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, unsigned int);
    printf("  %u\n", arg);
  }
  va_end(ap);
}

static inline void print_bool(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  bool arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int);
    printf("  (bool)%s\n", arg ? "true" : "false");
  }
  va_end(ap);
}

static inline void print_char(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  char arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int);
    printf("  (char)%c\n", arg);
  }
  va_end(ap);
}

static inline void print_unsigned_char(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  unsigned char arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int);
    printf("  (unsigned char)%u\n", arg);
  }
  va_end(ap);
}

static inline void print_signed_char(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  signed char arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int);
    printf("  (signed char)%u\n", arg);
  }
  va_end(ap);
}

static inline void print_short_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  short int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int);
    printf("  (short int)%i\n", arg);
  }
  va_end(ap);
}

static inline void print_unsigned_short_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  unsigned short int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int);
    printf("  (unsigned short int)%u\n", arg);
  }
  va_end(ap);
}

static inline void print_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int);
    printf("  (int)%i\n", arg);
  }
  va_end(ap);
}

static inline void print_long_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  long int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, long int);
    printf("  (long int)%li\n", arg);
  }
  va_end(ap);
}

static inline void print_long_long_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  long long int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, long long int);
    printf("  (long long int)%lli\n", arg);
  }
  va_end(ap);
}

static inline void print_float(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  float arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, double);
    printf("  (float)%f\n", arg);
  }
  va_end(ap);
}

static inline void print_double(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  double arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, double);
    printf("  (double)%f\n", arg);
  }
  va_end(ap);
}

static inline void print_long_double(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  long double arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, long double);
    printf("  (long double)%f\n", arg);
  }
  va_end(ap);
}

static inline void print_unsigned_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  unsigned int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, unsigned);
    printf("  (unsigned int)%i\n", arg);
  }
  va_end(ap);
}

static inline void print_unsigned_long_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  unsigned long int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, unsigned long int);
    printf("  (unsigned long int)%ul\n", arg);
  }
  va_end(ap);
}

static inline void print_unsigned_long_long_int(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  unsigned long long int arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, unsigned long long int);
    printf("  (unsigned long long int)%ul\n", arg);
  }
  va_end(ap);
}

static inline void print_char_pointer(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  char *arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, char *);
    printf("  (char *)%s\n", arg);
  }
  va_end(ap);
}

static inline void print_int_pointer(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  int *arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, int *);
    printf("  (int *)%x\n", arg);
  }
  va_end(ap);
}

static inline void print_void_pointer(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  unsigned int i;
  void *arg;
  va_list ap;

  va_start(ap, n_args);
  for (i = 0; i < n_args; i++) {
    arg = va_arg(ap, void *);
    printf("  (void *)%x\n", arg);
  }
  va_end(ap);
}

static inline void print_default(unsigned int n_args, ...)
{
  printf("%u argument(s):\n", n_args);

  if (n_args == 0) return;

  printf("  Unknown type\n");
}

#endif