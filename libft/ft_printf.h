/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:13:00 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/24 12:24:37 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"

# include "libft.h"
# include <limits.h> // for macros like LLONG_MIN
# include <stdarg.h> // for variable member functions
# include <stdbool.h> // for bool type

int	ft_printf(const char *str, ...);
int	ft_putnbr_base(unsigned long long num, char *base, bool is_usigned);

#endif