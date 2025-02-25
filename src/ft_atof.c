/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:52:31 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 12:19:46 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/** helper function for ft_atof
 * calculate the decimal part
 * this function should not be used somewehereelse */
static double	dec_part(char *str)
{
	double	decimal_part;
	double	divisor;

	if (*str == '.')
		str++;
	else
		return (0.0);
	decimal_part = 0.0;
	divisor = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		decimal_part += (*str - '0') / (divisor);
		divisor *= 10;
		str++;
	}
	return (decimal_part);
}

/**
 * Converts a string to a double.
 * The integer and decimal parts must be separated by a '.' (dot).
 * Ignores leading spaces and handles optional sign (+/-).
 * Stops parsing at the first non-numeric character (except '.').
 */
double	ft_atof(char *str)
{
	int		sign;
	double	integer_part;

	sign = 1;
	integer_part = 0.0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		integer_part = (integer_part * 10) + (*str - '0');
		if (integer_part > FLT_MAX)
			return (0.0);
		str++;
	}
	return ((integer_part + dec_part(str)) * sign);
}
