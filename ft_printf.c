/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:07:41 by toandrad          #+#    #+#             */
/*   Updated: 2025/05/21 12:02:23 by toandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, const char format);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_check_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

static int	ft_check_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_putptr((unsigned long long)va_arg(args, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

/*int	main(void)
{
	int	count1;
	int	count2;
	char	*string = "Hello World";
	char	c = 'o';
	int		n = 7;
	unsigned int un = 777;
	void	*null_ptr = NULL;
	
	printf("=========== STRING ===========\n");
	count1 = ft_printf("ft_printf: %s\n", string);
	count2 = printf("og_printf: %s\n", string);
	printf("ft_printf return: %d\n", count1);
	printf("og_printf return: %d\n", count2);
	
	printf("========= CHARACTER =========\n");
	count1 = ft_printf("ft_printf: %c\n", c);;
	count2 = printf("og_printf: %c\n", c);
	printf("ft_printf return: %d\n", count1);
	printf("og_printf return: %d\n", count2);
	
	printf("============ INT ============\n");
	count1 = ft_printf("ft_printf: %d\n", n);
	count2 = printf("og_printf: %d\n", n);
	printf("ft_printf return: %d\n", count1);
	printf("og_printf return: %d\n", count2);
	
	printf("======= UNSIGNED INT =======\n");
	count1 = ft_printf("ft_printf: %u\n", un);
	count2 = printf("og_printf: %u\n", un);
	printf("ft_printf return: %d\n", count1);
	printf("og_printf return: %d\n", count2);

	printf("========= POINTER =========\n");
	count1 = ft_printf("ft_printf: %p\n", &n);
	count2 = ft_printf("og_printf: %p\n", &n);
	printf("ft_printf return: %d\n", count1);
	printf("og_printf return: %d\n", count2);

	printf("======= HEXADECIMAL =======\n");
	count1 = ft_printf("ft_printf: %x or %X\n", 255, 255);
	count2 = printf("og_printf: %x or %X\n", 255, 255);
	printf("ft_printf return: %d\n", count1);
	printf("og_printf return: %d\n", count2);

	printf("======== NULL POINTER ======\n");
	count1 = ft_printf("ft_printf: %p\n", null_ptr);
	count2 = printf("og_printf: %p\n", null_ptr);
	printf("ft_printf return: %d\n", count1);
	printf("og_printf return: %d\n", count2);
}*/
