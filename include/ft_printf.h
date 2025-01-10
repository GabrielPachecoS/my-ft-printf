#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

typedef struct s_flags {
    int minus;
    int plus;
    int space;
    int zero;
    int hash;
    int width;
    int precision;
    char specifier;
} t_flags;

void init_flags(t_flags *flags);
const char *parse_specifier(const char *format, t_flags *flags);
const char *parse_precision(const char *format, t_flags *flags);
const char *parse_width(const char *format, t_flags *flags);
const char *parse_flags(const char *format, t_flags *flags);
int ft_printf(const char *format, ...);

#endif