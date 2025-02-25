/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:55:25 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 10:35:08 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	translate_immage(t_fractol *f, t_point mouse_pos, int x, int y)
{
	f->offset_x -= x;
	f->offset_y -= y;
	redraw_under_the_mouse(f, mouse_pos.x, mouse_pos.y);
	mlx_mouse_move(f->mlx, f->win, mouse_pos.x - x, mouse_pos.y - y);
	move_image_buffer(f, x, y);
	draw_fractal_part(f, x, y);
	f->is_zoom = true;
}

int	key_press(int key, t_fractol *f)
{
	t_point	mouse_pos;

	mlx_mouse_get_pos(f->mlx, f->win, &mouse_pos.x, &mouse_pos.y);
	if ((char)key == ESC)
		end_fractol(f);
	else if ((char)key == '+')
		fractal_zoom(f, 0.5);
	else if ((char)key == '-')
		fractal_zoom(f, 2);
	else if ((char)key == LEFT_ARROW)
		translate_immage(f, mouse_pos, OFFSET_ARROW, 0);
	else if ((char)key == RIGHT_ARROW)
		translate_immage(f, mouse_pos, -OFFSET_ARROW, 0);
	else if ((char)key == UP_ARROW)
		translate_immage(f, mouse_pos, 0, OFFSET_ARROW);
	else if ((char)key == DOWN_ARROW)
		translate_immage(f, mouse_pos, 0, -OFFSET_ARROW);
	return (0);
}
