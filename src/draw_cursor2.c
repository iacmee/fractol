/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cursor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:21:17 by ibrunial          #+#    #+#             */
/*   Updated: 2025/01/28 23:24:34 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_under_the_mouse(t_fractol *f, int x, int y)
{
	int	i;
	int	j;

	if (x > WIDTH - 16 || y > HEIGHT - 16 || x < 0 || y < 0)
		return ;
	j = 0;
	while (j < 21)
	{
		i = 0;
		while (i < 17)
		{
			*((unsigned int *)(f->img_addr + ((y + j) * f->line_length + (x + i)
							* f->bytes_pixel))) = f->under_mouse[i + j * 17];
			i++;
		}
		j++;
	}
}
