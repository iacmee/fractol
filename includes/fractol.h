/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:33:12 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 14:12:24 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "struct_and_define.h"
# include <math.h>

int		mouse_press(int button, int x, int y, t_fractol *f);
int		mouse_release(int button, int x, int y, t_fractol *f);
void	fractal_zoom(t_fractol *f, double zoom_factor);
void	calculate_offset(t_fractol *f, t_point now_mouse_pos);
double	ft_atof(char *str);
void	parse_av(t_fractol *f, int ac, char **av);
int		key_press(int key, t_fractol *f);
void	printc(char *str, char *color);

# define WIDTH 900
# define HEIGHT 900
# define MOVE_FACTOR 1 // deve essere intero altrimenti sfaciola
# define MAX_ITER 80

// rect_and_line

void	draw_line(t_fractol *f, t_point start, t_point end, int color);
void	draw_rect(t_fractol *f, t_rect rect, int color, int width);
void	draw_circle(t_fractol *f, t_circle circ, int color, int width);

// pixel_put

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

// exit_func

void	del_exit(t_fractol *f, int exit_code);
int		end_fractol(t_fractol *f);

// draw_cursor

void	initialize_drag_mouse_buf(t_fractol *f);
void	initialize_dragging_mouse_buf(t_fractol *f);
void	draw_drag_mouse(t_fractol *f, int x, int y);
void	draw_dragging_mouse(t_fractol *f, int x, int y);

// draw_cursor2

void	redraw_under_the_mouse(t_fractol *f, int x, int y);

// main_loop

int		main_loop(t_fractol *f);

// draw_fractal

void	draw_fractal_part(t_fractol *f, int off_x, int off_y);

// move_image

void	move_image_buffer(t_fractol *f, int off_x, int off_y);

#endif