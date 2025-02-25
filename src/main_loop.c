/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:47:37 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 12:40:34 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main_loop(t_fractol *f)
{
	static t_point	mouse_pos;

	if (!f->is_zoom)
		redraw_under_the_mouse(f, mouse_pos.x, mouse_pos.y);
	else
		f->is_zoom = false;
	mlx_mouse_get_pos(f->mlx, f->win, &mouse_pos.x, &mouse_pos.y);
	if (f->mouse)
	{
		calculate_offset(f, mouse_pos);
		draw_dragging_mouse(f, mouse_pos.x, mouse_pos.y);
	}
	else
	{
		calculate_offset(NULL, mouse_pos);
		draw_drag_mouse(f, mouse_pos.x, mouse_pos.y);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
	usleep(1000);
}

void	calculate_offset(t_fractol *f, t_point now_mouse_pos)
{
	static t_point	mouse_pos;

	if (f == NULL)
	{
		mouse_pos.x = 0;
		mouse_pos.y = 0;
		return ;
	}
	if (mouse_pos.x == 0 && mouse_pos.y == 0)
	{
	}
	else if (mouse_pos.x == now_mouse_pos.x && mouse_pos.y == now_mouse_pos.y)
		return ;
	else
	{
		f->offset_x -= (mouse_pos.x - now_mouse_pos.x) * MOVE_FACTOR;
		f->offset_y -= (mouse_pos.y - now_mouse_pos.y) * MOVE_FACTOR;
		move_image_buffer(f, (mouse_pos.x - now_mouse_pos.x) * MOVE_FACTOR,
			(mouse_pos.y - now_mouse_pos.y) * MOVE_FACTOR);
		draw_fractal_part(f, (mouse_pos.x - now_mouse_pos.x) * MOVE_FACTOR,
			(mouse_pos.y - now_mouse_pos.y) * MOVE_FACTOR);
	}
	mouse_pos.x = now_mouse_pos.x;
	mouse_pos.y = now_mouse_pos.y;
}
