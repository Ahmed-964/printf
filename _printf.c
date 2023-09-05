#include <main.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
            format++;
            if (*format == '\0')
                break;

            switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;

                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (str != NULL)
                    {
                        while (*str != '\0')
                        {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
                }

                case '%':
                    putchar('%');
                    count++;
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}

int main(void)
{
    int count;

    count = _printf("Hello, %c %s%%!\n", 'W', "orld");
    printf("Count: %d\n", count);

    return (0);
}

