#include "utils_bonus.h"

void parse_flags(const char *format, t_printf *main, t_format *fmt)
{
    while (1)
    {
        if (format[main->index] == '-')
            fmt->flag_minus = TRUE;
        else if (format[main->index] == '+')
            fmt->flag_plus = TRUE;
        else if (format[main->index] == ' ')
            fmt->flag_space = TRUE;
        else if (format[main->index] == '0')
            fmt->flag_zero = TRUE;
        else if (format[main->index] == '#')
            fmt->flag_hash = TRUE;
        else
            break;
        (main->index)++;
    }
}

void parse_width(const char *format, t_printf *main, t_format *fmt)
{
    while (format[main->index] >= '0' && format[main->index] <= '9')
    {
        fmt->width = fmt->width * 10 + (format[main->index] - '0');
        (main->index)++;
    }
}

void parse_precision(const char *format, t_printf *main, t_format *fmt)
{
    if (format[main->index] == '.')
    {
        main->index++;
        fmt->precision_specified = TRUE;
        fmt->precision = 0;
        while (format[main->index] >= '0' && format[main->index] <= '9')
        {
            fmt->precision = fmt->precision * 10 + (format[main->index] - '0');
            (main->index)++;
        }
    }
}
