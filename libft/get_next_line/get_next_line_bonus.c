/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:57:43 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/24 12:27:11 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check_exit(char **dest, int size, char **line)
{
	int		index;
	char	*tem;

	if (!(*dest))
		return (0);
	index = at_index(*dest, '\n');
	if (index != -1)
	{
		*line = ft_substr(*dest, 0, index + 1);
		tem = *dest;
		*dest = ft_substr(tem, index + 1, size - index);
		if (*dest[0] == '\0')
		{
			free(*dest);
			*dest = NULL;
		}
		free(tem);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*dest[4096] = {NULL};
	char		*buffer;
	int			byte_read;
	int			size;

	size = ft_strlen(dest[fd]);
	byte_read = 1;
	while (byte_read != 0)
	{
		if (check_exit(&dest[fd], size, &buffer))
			return (buffer);
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buffer), NULL);
		if (byte_read > 0)
			resize_and_cp(&dest[fd], &size, buffer, byte_read);
		free(buffer);
	}
	buffer = dest[fd];
	dest[fd] = NULL;
	return (buffer);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	if (argc != 2)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
// 	do
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 			printf("%s", line);
// 	} while (line != NULL);
// 	close(fd);
// }
