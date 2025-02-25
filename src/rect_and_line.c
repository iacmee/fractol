/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_and_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:07:26 by ibrunial          #+#    #+#             */
/*   Updated: 2025/01/28 23:24:04 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// This function draws a line between two points (`start` and `end`)
// on the image.
// - `color`: Color of the line.
// The function implements the Bresenham's line algorithm to calculate
// the path of the line
// between the two points. The algorithm ensures the line is drawn
// efficiently by only
// using integer arithmetic.
// Steps:
// 1. Calculate the difference in x (`delta.x`) and y (`delta.y`)
//    between the points.
// 2. Determine the step direction (positive or negative)
//    for x and y based on their positions.
// 3. Iterate through the line path,
//    updating the error term to decide the next pixel to draw.
// 4. For each pixel,
//    call `my_mlx_pixel_put` to set the color in the image buffer.
void	draw_line(t_fractol *f, t_point start, t_point end, int color)
{
	t_point	delta;
	t_point	step;
	t_point	err;

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	step.x = (start.x < end.x) * 1 + (start.x >= end.x) * -1;
	step.y = (start.y < end.y) * 1 + (start.y >= end.y) * -1;
	err.x = delta.x - delta.y;
	my_mlx_pixel_put(f, start.x, start.y, color);
	while (start.x != end.x || start.y != end.y)
	{
		err.y = 2 * err.x;
		if (err.y > -delta.y)
		{
			err.x -= delta.y;
			start.x += step.x;
		}
		if (err.y < delta.x)
		{
			err.x += delta.x;
			start.y += step.y;
		}
		my_mlx_pixel_put(f, start.x, start.y, color);
	}
}

void	draw_rect(t_fractol *f, t_rect rect, int color, int width)
{
	t_point	dr;

	dr.y = rect.a.y;
	while (dr.y < rect.a.y + width)
	{
		dr.x = rect.a.x;
		while (dr.x <= rect.a.x + rect.width)
		{
			my_mlx_pixel_put(f, dr.x, dr.y, color);
			my_mlx_pixel_put(f, dr.x, rect.a.y * 2 + rect.height - dr.y, color);
			dr.x++;
		}
		dr.y++;
	}
	while (dr.y <= rect.a.y + rect.height - width)
	{
		dr.x = rect.a.x;
		while (dr.x < rect.a.x + width)
		{
			my_mlx_pixel_put(f, dr.x, dr.y, color);
			my_mlx_pixel_put(f, dr.x + rect.width - width + 1, dr.y, color);
			dr.x++;
		}
		dr.y++;
	}
}

// let's talk about why this algoritm works.
// firt we have to understant that a poin is inside or in the circle if
// d(x, y) = (x^2 + y^2- r^2) <= 0.
// we could theoretically use this function but we
// notice that we only increment 1 pixel at the time. we are working on
// the top left part of the circle and for simmetry we are drawing the rest
// so we could only increment by (1, 0) or (0, 0) (orizzontal or diagonal)
// notice that d(x + 1, y) = (x + 1)^2 + y^2 -r^2 = 2x + 1 + d(x, y)
// so if we have (x, y) for the next iteration d will be d(x, y) + 2x + 1
// in code (d += 2x + 1)
// void	draw_circle(t_fractol *f, t_circle circ, int color, int width)
// {
// 	int	r_out;
// 	int	r_in;
// 	int	r_out_sq;
// 	int	r_in_sq;
// 	int	x_start;
// 	int	x_end;
// 	int	y_start;
// 	int	y_end;
// 	int	dx;
// 	int	dy;
// 	int	dist_sq;

// 	r_out = circ.radius;
// 	r_in = circ.radius - width;
// 	if (r_in < 0)
// 		r_in = 0;
// 	r_out_sq = r_out * r_out;
// 	r_in_sq = r_in * r_in;
// 	x_start = circ.x - r_out;
// 	x_end = circ.x + r_out;
// 	y_start = circ.y - r_out;
// 	y_end = circ.y + r_out;
// 	for (int y = y_start; y <= y_end; y++)
// 	{
// 		for (int x = x_start; x <= x_end; x++)
// 		{
// 			dx = x - circ.x;
// 			dy = y - circ.y;
// 			dist_sq = dx * dx + dy * dy;
// 			if (dist_sq <= r_out_sq && dist_sq >= r_in_sq)
// 				my_mlx_pixel_put(f, x, y, color);
// 		}
// 	}
// }
