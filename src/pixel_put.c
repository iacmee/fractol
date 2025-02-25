/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:55:49 by ibrunial          #+#    #+#             */
/*   Updated: 2025/02/25 12:36:01 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#ifndef OPT

// This function sets a color for a pixel in the image buffer (`f->img`).
// The image is stored in a buffer,
//	where each pixel is represented by its color.
// `img_addr` is the address of the buffer where the image is stored.
// `bytes_pixel` specifies how many bytes are used to represent each pixel.
// `line_length` indicates the number of bytes per row in the image buffer.
// Note: `line_length` is not necessarily equal to `bytes_pixel
//	* WIDTH` due to alignment.
// `endian` determines how the color is represented as an integer:
//   - If `endian == 0`, the color is in the format 0xTTRRGGBB.
//   - If `endian == 1`, the color is in the format 0xBBGGRRTT.
// Depending on the endianness,
//	the function writes the color value in the correct order.
void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	if (!f->endian)
		*(unsigned int *)(f->img_addr + (y * f->line_length + x
					* f->bytes_pixel)) = color;
	else
		*(unsigned int *)(f->img_addr + (y * f->line_length + x
					* f->bytes_pixel)) = (color << 24 | ((color << 16)
					& 0x00FF0000) | ((color >> 8) & 0x0000FF00) | color >> 24);
}

#else
// This function sets a color for a pixel in the image buffer (`f->img`).
// The image is stored in a buffer,
//	where each pixel is represented by its color.
// `img_addr` is the address of the buffer where the image is stored.
// `bytes_pixel` specifies how many bytes are used to represent each pixel.
// `line_length` indicates the number of bytes in each row of the image buffer.
// Note: `line_length` is not necessarily equal to `bytes_pixel
//	* WIDTH` due to alignment.
// For optimization purposes, this function assumes that `endian == 1`,
// meaning the color format is 0xBBGGRRTT (Blue, Green, Red, Transparency).
void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	*(unsigned int *)(f->img_addr + (y * f->line_length + x
				* f->bytes_pixel)) = color;
}
#endif