/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:32:54 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 13:34:10 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <time.h>

static void	init_f(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "la mia prima finestra");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_addr = mlx_get_data_addr(f->img, &f->bytes_pixel, &f->line_length,
			&f->endian);
	f->bytes_pixel /= 8;
	initialize_drag_mouse_buf(f);
	initialize_dragging_mouse_buf(f);
	f->under_mouse = (int *)malloc(f->bytes_pixel * 17 * 21);
	f->offset_x = 0;
	f->offset_y = 0;
	f->mouse = false;
	f->is_zoom = true;
	f->xmin = -2.0;
	f->xmax = 1.0;
	f->ymin = -1.5;
	f->ymax = 1.5;
	f->cx = -0.123;
	f->cy = 0.745;
	f->fractal_type = 0;
}

int	main(int ac, char **av)
{
	t_fractol	f;

	init_f(&f);
	parse_av(&f, ac, av);
	mlx_mouse_hide(f.mlx, f.win);
	mlx_hook(f.win, DestroyNotify, 0, end_fractol, &f);
	mlx_loop_hook(f.mlx, main_loop, &f);
	mlx_hook(f.win, 2, (1L << 0), key_press, &f);
	mlx_hook(f.win, 4, (1L << 2), mouse_press, &f);
	mlx_hook(f.win, 5, (1l << 3), mouse_release, &f);
	draw_fractal_part(&f, WIDTH, HEIGHT);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_loop(f.mlx);
	del_exit(&f, 0);
}

void	fractal_zoom(t_fractol *f, double zoom_factor)
{
	t_point	mouse_pos;
	double	center_r;
	double	center_i;

	mlx_mouse_get_pos(f->mlx, f->win, &mouse_pos.x, &mouse_pos.y);
	if (abs(mouse_pos.x) > WIDTH || abs(mouse_pos.y) > HEIGHT)
		return ;
	f->offset_x += (WIDTH / 2 - mouse_pos.x - 17.0f / 2);
	f->offset_y += (HEIGHT / 2 - mouse_pos.y - 21.0f / 2);
	center_r = f->xmin - f->xmax;
	center_i = f->ymax - f->ymin;
	f->xmax = f->xmax + (center_r - zoom_factor * center_r) / 2;
	f->xmin = f->xmax + zoom_factor * center_r;
	f->ymin = f->ymin + (center_i - zoom_factor * center_i) / 2;
	f->ymax = f->ymin + zoom_factor * center_i;
	f->offset_x /= zoom_factor;
	f->offset_y /= zoom_factor;
	f->offset_x -= (WIDTH / 2 - mouse_pos.x - 17.0f / 2);
	f->offset_y -= (HEIGHT / 2 - mouse_pos.y - 21.0 / 2);
	ft_memset(f->img_addr, 0, f->line_length * HEIGHT);
	draw_fractal_part(f, WIDTH, HEIGHT);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	f->is_zoom = true;
}

int	mouse_press(int button, int x, int y, t_fractol *f)
{
	if (button == 1)
		f->mouse = true;
	if (button == 4)
		fractal_zoom(f, 0.5);
	if (button == 5)
		fractal_zoom(f, 2);
	(void)x;
	(void)y;
	return (0);
}

int	mouse_release(int button, int x, int y, t_fractol *f)
{
	if (button == 1)
		f->mouse = false;
	(void)x;
	(void)y;
	return (0);
}
