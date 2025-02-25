/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mouses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:33:47 by ibrunial          #+#    #+#             */
/*   Updated: 2025/01/19 12:39:39 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_drag_mouse_buf(t_fractol *f)
{
	f->drag_mouse = (int *)ft_calloc(sizeof(int), 17);
	f->drag_mouse[0] = 0b000000000111000000000;
	f->drag_mouse[1] = 0b000000000100100000000;
	f->drag_mouse[2] = 0b000000000100011000000;
	f->drag_mouse[3] = 0b000000000010000110000;
	f->drag_mouse[4] = 0b000111111111000001100;
	f->drag_mouse[5] = 0b001000000000000000011;
	f->drag_mouse[6] = 0b001000000000000000001;
	f->drag_mouse[7] = 0b011111111100000000001;
	f->drag_mouse[8] = 0b100000000000000000001;
	f->drag_mouse[9] = 0b100000000000000000001;
	f->drag_mouse[10] = 0b011111111100000000001;
	f->drag_mouse[11] = 0b010000000000000000001;
	f->drag_mouse[12] = 0b010000000000000000001;
	f->drag_mouse[13] = 0b001111111110000000001;
	f->drag_mouse[14] = 0b000010000000000000011;
	f->drag_mouse[15] = 0b000010000000000011100;
	f->drag_mouse[16] = 0b000001111111111100000;
}

void	initialize_dragging_mouse_buf(t_fractol *f)
{
	f->dragging_mouse = (short int *)malloc(sizeof(short int) * 16);
	f->dragging_mouse[0] = 0b0000000111000000;
	f->dragging_mouse[1] = 0b0000111001110000;
	f->dragging_mouse[2] = 0b0001001001001100;
	f->dragging_mouse[3] = 0b0001001001001010;
	f->dragging_mouse[4] = 0b0011001001001001;
	f->dragging_mouse[5] = 0b0101000000001001;
	f->dragging_mouse[6] = 0b1001000000000001;
	f->dragging_mouse[7] = 0b1000000000000001;
	f->dragging_mouse[8] = 0b0100000000000001;
	f->dragging_mouse[9] = 0b0100000000000001;
	f->dragging_mouse[10] = 0b0010000000000010;
	f->dragging_mouse[11] = 0b0010000000000010;
	f->dragging_mouse[12] = 0b0001000000000010;
	f->dragging_mouse[13] = 0b0001000000000100;
	f->dragging_mouse[14] = 0b0000100000000100;
	f->dragging_mouse[15] = 0b0000111111111100;
}

static void	save_under_the_mouse(t_fractol *f, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < 21)
	{
		i = 0;
		while (i < 17)
		{
			f->under_mouse[i + j * 17] = *((unsigned int *)(f->img_addr + ((y
								+ j) * f->line_length + (x + i)
							* f->bytes_pixel)));
			i++;
		}
		j++;
	}
}

void	draw_dragging_mouse(t_fractol *f, int x, int y)
{
	int		i;
	int		j;
	bool	first_one;

	if (x > WIDTH - 16 || y > HEIGHT - 16 || x < 0 || y < 0)
		return ;
	save_under_the_mouse(f, x, y);
	i = 0;
	while (i < 16)
	{
		j = 0;
		first_one = false;
		while (j < 16 && (f->dragging_mouse[i] >> j))
		{
			if (f->dragging_mouse[i] >> j & 1)
			{
				my_mlx_pixel_put(f, x + (16 - j), y + i, 0);
				first_one = true;
			}
			else if (first_one)
				my_mlx_pixel_put(f, x + (16 - j), y + i, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_drag_mouse(t_fractol *f, int x, int y)
{
	int		i;
	int		j;
	bool	first_one;

	if (x > WIDTH - 17 || y > HEIGHT - 21 || x < 0 || y < 0)
		return ;
	save_under_the_mouse(f, x, y);
	i = 0;
	while (i < 17)
	{
		j = 0;
		first_one = false;
		while (j < 21)
		{
			if (f->drag_mouse[i] & (1 << j))
			{
				my_mlx_pixel_put(f, x + i, y + (20 - j), 0);
				first_one = true;
			}
			else if (first_one && (f->drag_mouse[i] >> j))
				my_mlx_pixel_put(f, x + i, y + (20 - j), 0x00FFFFFF);
			j++;
		}
		i++;
	}
}
