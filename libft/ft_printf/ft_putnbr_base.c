/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:26:19 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/24 12:21:16 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_base_u(unsigned long long num, char *base,
		unsigned long long len_base)
{
	int	count;

	count = 0;
	if (num >= len_base)
		count += nbr_base_u(num / len_base, base, len_base);
	count += write(1, &base[num % len_base], 1);
	return (count);
}

static int	nbr_base_s(long long num, char *base, int len_base)
{
	int	count;

	count = 0;
	if (num == LLONG_MIN)
	{
		count += write(1, "-", 1);
		count += nbr_base_s(-(num / len_base), base, len_base);
		count += write(1, &base[-(num % len_base)], 1);
		return (count);
	}
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	if (num >= len_base)
		count += nbr_base_s(num / len_base, base, len_base);
	count += write(1, &base[num % len_base], 1);
	return (count);
}

/**
 * @brief stampa sullo STDOUT un numero scritto nella base corrispondente.
 * @param num: numero da stampare.
 * @param base: base da utilizzare.
 * @param is_unsigned specifica se il numero è unsigned o meno.
 * @return ritorna quanti carattteri ha stampato
 *
 * gestisce numeri che stanno nel long long int
 * non gestisce la validità della base, undefined
 * behaviour altrimenti
 */
int	ft_putnbr_base(unsigned long long num, char *base, bool is_usigned)
{
	int	count;

	if (is_usigned == true)
		count = nbr_base_u(num, base, ft_strlen(base));
	else
		count = nbr_base_s(num, base, ft_strlen(base));
	return (count);
}
