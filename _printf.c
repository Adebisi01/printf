#include "main.h"

/**
 * _printf - prints out formatted string
 * @format: first argument
 * @...: more arguments
 * Return: numbers of characters printed
 */
int _printf(const char *format, ...)
{
	int i;
	int j;
	unsigned int count;
	va_list list;
	char *substring;
	int digit;

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if ((format[i]) == '%')
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(list, int));
				count++;
			}
			else if (format[i + 1] == 'r')
			{
				return (-1);
			}
				
			else if (format[i + 1] == 's')
			{
				substring = va_arg(list, char *);
				for (j = 0; substring[j] != '\0'; j++)
				{
					_putchar(substring[j]);
					count++;
				}
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				digit = va_arg(list, int);
				if (digit < 0)
				{
					_putchar('-');
					count++;
					digit = -digit;
				}
				_putchar((digit / 10));
				_putchar((digit % 10));
				count++;
			}
		}
		_putchar(format[i]);
		count++;
	}
	return (count);
}
