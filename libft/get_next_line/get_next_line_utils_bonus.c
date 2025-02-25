/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:57:45 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/24 12:27:06 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	at_index(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief prende come argomento 2  buffer e copia n elementi
 * di to_copy dentro dest reallocando lo spazio necessario.
 * è garantito il carattere di fine stringa.
 * @param dest: è il buffer di destinazione.
 * @param size è l'attuale size di dest.
 * @param to_copy è il buffer da dove deve copiare.
 * @param n sono i byte da copiare da to_copy.
 * @return ritorna la nuova size di dest
 */
void	resize_and_cp(char **dest, int *size, char *to_copy, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)malloc(*size + n + 1);
	if (!temp)
	{
		free(*dest);
		*dest = NULL;
		return ;
	}
	temp[*size + n] = '\0';
	while ((int)i < *size)
	{
		temp[i] = (*dest)[i];
		i++;
	}
	i = -1;
	while (++i < n)
		temp[*size + i] = to_copy[i];
	free(*dest);
	*dest = temp;
	(*size) += n;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_sub;
	char	*dest;

	len_sub = ft_strlen(s) - start;
	if ((long long)len_sub < 0)
	{
		dest = (char *)malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	if (len_sub > len)
		len_sub = len;
	dest = (char *)malloc(sizeof(char) * len_sub + 1);
	if (!dest)
		return (NULL);
	dest[len_sub] = '\0';
	while (len_sub--)
		dest[len_sub] = s[len_sub + start];
	return (dest);
}
