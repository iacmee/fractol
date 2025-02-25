/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:29:08 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 14:00:44 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "fractol.h"
#include "mlx_int.h"
#include <stdnoreturn.h>

// this function will free all the allocated resources,
// destroy: image, window and display. end loops.
// then it will exit with the exit_code passed
noreturn void	del_exit(t_fractol *f, int exit_code)
{
	free(f->drag_mouse);
	free(f->dragging_mouse);
	free(f->under_mouse);
	if (!f)
		exit(exit_code);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
}

// this function will be called by mlx_hook for DestroyNotify.
// it calls del_exit with code 0
int	end_fractol(t_fractol *f)
{
	del_exit(f, 0);
	return (0);
}
