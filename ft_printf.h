#ifndef FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	num_array_print(short number[], int base, int digit);
int	dec_print(int number);
int	unsigned_dec_print(unsigned int number);
int	hex_print(unsigned int number, int flag);
int	addr_print(unsigned long addr);
int	str_print(const char *str);
int	char_print(const char ch);
int	ft_printf(const char *format, ...);
int	flag_print(va_list ap, const char *format);
#endif
