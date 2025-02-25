/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:56:53 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 11:31:46 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_float_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '.')
		return (false);
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

static int	parse_julia_set(t_fractol *f, int ac, char **av)
{
	if (ft_strncmp(av[1], "J", 2) == 0)
	{
		if (ac == 4)
		{
			if (!is_float_num(av[3]) || !is_float_num(av[2]))
			{
				printc("that are not a number!!\n", RED);
				return (false);
			}
			f->cx = ft_atof(av[2]);
			f->cy = ft_atof(av[3]);
			if ((f->cx == 0.0 && av[2][0] != '0') || (f->cy == 0.0
					&& av[3][0] != '0'))
			{
				printc("number exede max_float!!\n", RED);
				return (false);
			}
		}
		else
			printc("not enough argument for JULIA set\n standard configuation is setted with starting value 0.123, \
				0.745\n", YEL);
		return (true);
	}
	return (false);
}

static void	print_instruction(void)
{
	printc("usage: ./fractol [M|J|B] [cx] [cy]\n", YEL);
	printc("cx and cy are only for the julia set, are the starting value\n",
		YEL);
	printc("please use M for Mandelbrot, J for Julia, B for Burning Ship\n",
		BLD);
}

void	parse_av(t_fractol *f, int ac, char **av)
{
	if (ac < 2)
	{
		printc("not enough argument!\n", RED);
		print_instruction();
		del_exit(f, EXIT_FAILURE);
	}
	if (parse_julia_set(f, ac, av))
		f->fractal_type = JULIA;
	else if (ft_strncmp(av[1], "M", 2) == 0 && ac == 2)
		f->fractal_type = MANDELBROT;
	else if (ft_strncmp(av[1], "B", 2) == 0 && ac == 2)
		f->fractal_type = BURNINGSHIP;
	else
	{
		printc("unable to parse argument, not propely formatted\n", RED);
		print_instruction();
		del_exit(f, EXIT_FAILURE);
	}
}
