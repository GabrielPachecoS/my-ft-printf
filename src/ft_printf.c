#include "../include/ft_printf.h"

int print_int(int value, t_flags flags) {
    int len = 0;
    char *num = ft_itoa(value);

    if (flags.plus && value >= 0)
        len += write(1, "+", 1);
    else if (flags.space && value >= 0)
        len += write(1, " ", 1);

    len += write(1, num, ft_strlen(num));
    free(num);
    return len;
}

int print_string(const char *value, t_flags flags) {
    int len = 0;
    int str_len = ft_strlen(value);

    if (flags.precision >= 0 && flags.precision < str_len)
        str_len = flags.precision;

    len += write(1, value, str_len);
    return len;
}

const char *parse_format(const char *format, t_flags *flags) {
    format = parse_flags(format, flags);
    format = parse_width(format, flags);
    format = parse_precision(format, flags);
    format = parse_specifier(format, flags);
    return format;
}

int handle_format(t_flags flags, va_list args) {
    int printed = 0;

    if (flags.specifier == 'd' || flags.specifier == 'i')
        printed += print_int(va_arg(args, int), flags);
    else if (flags.specifier == 's')
        printed += print_string(va_arg(args, const char *), flags);
    return printed;
}

int ft_printf(const char *format, ...) {
    va_list args;
    int total_printed = 0;

    va_start(args, format);
    while (*format) {
        if (*format == '%') {
            t_flags flags;
            init_flags(&flags);
            format = parse_format(format + 1, &flags);
            total_printed += handle_format(flags, args);
        } else {
            total_printed += write(1, format, 1);
        }
        format++;
    }
    va_end(args);
    return total_printed;
}