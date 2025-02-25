/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:09:36 by ibrunial          #+#    #+#             */
/*   Updated: 2025/01/29 14:27:32 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pasrse_ps(const char **str, va_list *args, int *count)
{
	char		*str_to_display;
	long long	temp;

	if (**str == 'p')
	{
		temp = va_arg(*args, long long);
		if (temp == 0)
			(*count) += write(1, "(nil)", 5);
		else
			(*count) += write(1, "0x", 2) + ft_putnbr_base(temp, HEX, 1);
	}
	else if (**str == 's')
	{
		str_to_display = va_arg(*args, char *);
		if (str_to_display == NULL)
			(*count) += write(1, "(null)", 6);
		else
			(*count) += write(1, str_to_display, ft_strlen(str_to_display));
	}
}

void	parse_str(const char **str, va_list *args, int *count)
{
	if (**str == 'd' || **str == 'i')
		(*count) += ft_putnbr_base(va_arg(*args, int), DEC, 0);
	else if (**str == 'u')
		(*count) += ft_putnbr_base(va_arg(*args, unsigned int), DEC, 1);
	else if (**str == 'x')
		(*count) += ft_putnbr_base(va_arg(*args, unsigned int), HEX, 1);
	else if (**str == 'X')
		(*count) += ft_putnbr_base(va_arg(*args, unsigned int), HEX_UPP, 1);
	else if (**str == 'c')
		(*count) += write(1, &(char){va_arg(*args, int)}, 1);
	else if (**str == '%')
		(*count) += write(1, "%", 1);
	pasrse_ps(str, args, count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && str++)
			parse_str(&str, &args, &count);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
