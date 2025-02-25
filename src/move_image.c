/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:10:02 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 12:22:34 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_image_buffer_positive(t_fractol *f, int off_x, int off_y)
{
	int	i;

	i = -1;
	if (off_x >= 0)
		while (++i < HEIGHT - off_y)
			ft_memmove(f->img_addr + (i * f->line_length), f->img_addr
				+ (f->line_length * (off_y + i)) + (off_x * 4), (WIDTH - off_x)
				* 4);
	else
		while (++i < HEIGHT - off_y)
			ft_memmove(f->img_addr + (i * f->line_length) - (off_x * 4),
				f->img_addr + (f->line_length * (off_y + i)), (WIDTH + off_x)
				* 4);
}

static void	move_image_buffer_negative(t_fractol *f, int off_x, int off_y)
{
	int	i;

	i = HEIGHT;
	if (off_x >= 0)
		while (--i >= -off_y)
			ft_memcpy(f->img_addr + (i * f->line_length), f->img_addr
				+ (f->line_length * (i + off_y)) + (off_x * 4), (WIDTH - off_x)
				* 4);
	else
		while (--i >= -off_y)
			ft_memcpy(f->img_addr + (i * f->line_length) - (off_x * 4),
				f->img_addr + (f->line_length * (i + off_y)), (WIDTH + off_x)
				* 4);
}

// y positivi la finestra si muove verso il basso
// y negativi la finestra si sta muovendo verso l'alto
// x positivi la finestra si sta muovento verso destra
// x negativi la finestra si sta muovendo verso sinistra
void	move_image_buffer(t_fractol *f, int off_x, int off_y)
{
	if (abs(off_x) > WIDTH || abs(off_y) > HEIGHT)
		return ;
	if (off_y >= 0)
		move_image_buffer_positive(f, off_x, off_y);
	else
		move_image_buffer_negative(f, off_x, off_y);
}
