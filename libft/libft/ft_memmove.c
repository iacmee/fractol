/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:52:17 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 20:17:05 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*c_dest;
	const char	*c_src;

	c_dest = dest;
	c_src = src;
	if (src == dest)
		return (dest);
	if (src > dest || (src + size) < dest)
		return (ft_memcpy(dest, src, size));
	while (size--)
		c_dest[size] = c_src[size];
	return (dest);
}
