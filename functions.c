#include "main.h"

/**
 * print_char - Char output
 * @types: Argument type
 * @buffer: Print buffer array
 * @flags: Active flag calculator
 * @width: Number of chars
 * @precision: Precision specifications
 * @size: String size
 * Return: width
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - String output
 * @types: Argument type
 * @buffer: Print buffer array
 * @flags: Active flag calculator
 * @width: Number of chars
 * @precision: Precision specifications
 * @size: String size
 * Return: Width
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int iter, len = 0;
	char *str_ptr = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str_ptr == NULL)
	{
		str_ptr = "(null)";
		if (precision >= 6)
		{
			str_ptr = "      ";
		}
	}

	while (str_ptr[len] != '\0')
	{
		len++;
	}

	if (precision >= 0 && precision < len)
	{
		len = precision;
	}

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			iter = width - len;
			while (iter > 0)
			{
				write(1, " ", 1);
				iter--;
			}
			return (width);
		}
		else
		{
			for (iter = width - len; iter > 0; iter--)
			{
				write(1, " ", 1);
			}
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_percent - Percent sign output
 * @types: Argument type
 * @buffer: Print buffer array
 * @flags: Active flag calculator
 * @width: Number of chars
 * @precision: Precision specifications
 * @size: Char size
 * Return: width
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
