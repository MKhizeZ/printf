#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Characters
 */
int _printf(const char *format, ...)
{
	int iter = 0, Output_Char = 0, Char_Print = 0;
	int buff_ind = 0;
	int str_len, flags;
	int precision, size;
	va_list arguments;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arguments, format);

	while (format && format[iter] != '\0')
	{
		if (format[iter] != '%')
		{
			buffer[buff_ind++] = format[iter];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			Char_Print++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &iter);
			size = get_width(format, &iter, arguments);
			precision = get_precision(format, &iter, arguments);
			str_len = get_size(format, &iter);
			++iter;
			Output_Char = handle_print(format, &iter, arguments, buffer,
				flags, size, precision, str_len);
			if (Output_Char == -1)
			{
				return (-1);
			}
			Char_Print = Char_Print + Output_Char;
		}
		iter++;
	}

	print_buffer(buffer, &buff_ind);

	va_end(arguments);

	return (Char_Print);
}

/**
 * print_buffer - Prints buffer content for existing buffer
 * @buffer: Char array
 * @buff_ind: Char position index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
