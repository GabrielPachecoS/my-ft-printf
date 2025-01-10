#include "../include/libft.h"
#include "../include/ft_printf.h"

void init_flags(t_flags *flags) {
    flags->minus = 0;
    flags->plus = 0;
    flags->space = 0;
    flags->zero = 0;
    flags->hash = 0;
    flags->width = 0;
    flags->precision = -1;
    flags->specifier = '\0';
}

const char *parse_flags(const char *format, t_flags *flags) {
    while (*format == '-' || *format == '+' || *format == ' ' ||
           *format == '0' || *format == '#') {
        if (*format == '-')
            flags->minus = 1;
        else if (*format == '+')
            flags->plus = 1;
        else if (*format == ' ')
            flags->space = 1;
        else if (*format == '0')
            flags->zero = 1;
        else if (*format == '#')
            flags->hash = 1;
        format++;
    }
    return format;
}

const char *parse_width(const char *format, t_flags *flags) {
    if (ft_isdigit(*format)) {
        flags->width = ft_atoi(format);
        while (ft_isdigit(*format))
            format++;
    }
    return format;
}

const char *parse_precision(const char *format, t_flags *flags) {
    if (*format == '.') {
        format++;
        if (ft_isdigit(*format))
            flags->precision = ft_atoi(format);
        else
            flags->precision = 0;
        while (ft_isdigit(*format))
            format++;
    }
    return format;
}

const char *parse_specifier(const char *format, t_flags *flags) {
    if (*format == 'd' || *format == 'i' || *format == 'u' ||
        *format == 'x' || *format == 'X' || *format == 's' ||
        *format == 'c' || *format == 'p') {
        flags->specifier = *format;
        format++;
    }
    return format;
}