/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:32:53 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 12:24:59 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == -1)
		return (0x00000000);
	t = (double)iteration / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

static int	iter_pixel(double zx, double zy, double cr, double ci)
{
	int		i;
	double	zx2;
	double	zy2;

	i = 0;
	zx2 = zx * zx;
	zy2 = zy * zy;
	while (i < MAX_ITER)
	{
		if (zx2 + zy2 > 4.0)
			return (i);
		zy = 2.0 * zx * zy + ci;
		zx = zx2 - zy2 + cr;
		zx2 = zx * zx;
		zy2 = zy * zy;
		i++;
	}
	return (-1);
}

static int	iter_pixel_burning_ship(double cr, double ci)
{
	int		i;
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;

	zx = 0.0;
	zy = 0.0;
	zx2 = 0.0;
	zy2 = 0.0;
	i = 0;
	while (i < MAX_ITER)
	{
		if (zx2 + zy2 > 4.0)
			return (i);
		zy = fabs(2.0 * zx * zy) + ci;
		zx = zx2 - zy2 + cr;
		zx2 = zx * zx;
		zy2 = zy * zy;
		i++;
	}
	return (-1);
}

static int	draw_fractal(t_fractol *f, t_point pix)
{
	double	cr;
	double	ci;
	int		i;

	i = 0;
	cr = ((pix.x - f->offset_x) / WIDTH) * (f->xmax - f->xmin) + f->xmin;
	ci = ((pix.y - f->offset_y) / HEIGHT) * (f->ymax - f->ymin) + f->ymin;
	if (f->fractal_type == MANDELBROT)
		i = iter_pixel(0, 0, cr, ci);
	else if (f->fractal_type == JULIA)
		i = iter_pixel(cr, ci, f->cx, f->cy);
	else if (f->fractal_type == BURNINGSHIP)
		i = iter_pixel_burning_ship(cr, ci);
	my_mlx_pixel_put(f, pix.x, pix.y, get_color(i, MAX_ITER));
	return (1);
}

void	draw_fractal_part(t_fractol *f, int off_x, int off_y)
{
	t_point	pix;

	if (abs(off_x) > WIDTH || abs(off_y) > HEIGHT)
		return ;
	pix.y = 0;
	while (pix.y < HEIGHT)
	{
		pix.x = 0;
		if ((off_y > 0 && pix.y >= (HEIGHT - off_y)) || (off_y < 0 && pix.y
				< -off_y))
			while (pix.x < WIDTH)
				pix.x += draw_fractal(f, pix);
		else if (off_x > 0)
		{
			pix.x = (WIDTH - off_x);
			while (pix.x < WIDTH)
				pix.x += draw_fractal(f, pix);
		}
		else if (off_x < 0)
			while (pix.x < -off_x)
				pix.x += draw_fractal(f, pix);
		pix.y++;
	}
}
