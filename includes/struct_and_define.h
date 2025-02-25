/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_and_define.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:44:15 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 14:11:56 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_AND_DEFINE_H
# define STRUCT_AND_DEFINE_H

# include <stdbool.h>

# define ESC 27
# define LEFT_ARROW 81
# define RIGHT_ARROW 83
# define UP_ARROW 82
# define DOWN_ARROW 84
# define OFFSET_ARROW 50

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

# ifndef FLT_MAX
#  define FLT_MAX 3.40282346638528859811704183484516925e+38F
# endif

# define YEL "\e[1;93m"
# define RED "\e[1;91m"
# define GRN "\e[1;92m"
# define BLU "\e[1;94m"
# define MAG "\e[1;95m"
# define CYN "\e[1;96m"
# define WHT "\e[1;97m"
# define RES "\e[0m"
# define BLD "\e[1m"

typedef struct s_fractol
{
	void		*mlx;// sara usato per creare l'istanza di mlx
	void		*win;// sarà la finestra che si apre
	void		*img;// sarà limmagine che poi sarà pushata sulla finestra
	void		*img_addr;// sarà l'address della mia immagine
	int			bytes_pixel;// numero di byte usati per rappresentare un pixel
	int			line_length;// quanti byte è lunga una linea di pixel
	int			endian;// la rappresentazione dei colori 0xTTRRGGBB-0xBBGGRRTT
	bool		mouse;// indica se il tasto sinistro del mouse è premuto o meno
	short int	*dragging_mouse;// tabella per disegnare il dragging cursor
	int			*drag_mouse;// tabella per disegnare il dragging mouse
	int			*under_mouse; // buffer per salvare i pixel sotto il mouse
	double		offset_x; // offset globale x del frattele
	double		offset_y; // offset globale y del frattele
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
	int			fractal_type;
	double		cx;
	double		cy;
	bool		is_zoom;
}				t_fractol;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_rect
{
	t_point		a;
	int			width;
	int			height;
}				t_rect;

typedef struct s_circle
{
	int			x;
	int			y;
	int			radius;
}				t_circle;

#endif