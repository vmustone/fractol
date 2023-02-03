/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:18:31 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/02 12:20:20 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	draw_mandelbrot(t_data *data)
{
	unsigned	y = 0;
	unsigned	x = 0;
	unsigned	n;
	int		inside;
	unsigned int	color = 0x00000000;
	double	MinRe = -2.0;
	double	MaxRe = 1.0;
	double	MinIm = -1.2;
	double	MaxIm = MinIm + (MaxRe - MinRe) * 800/800;
	double	Re_factor = (MaxRe - MinRe)/(800 - 1);
	double	Im_factor = (MaxIm - MinIm)/(800 - 1);
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		maxiterations = 30;
	while (y < 800)
	{
		c_im = MaxIm - y * Im_factor;
		x = 0;
		while (x < 800)
		{
			c_re = MinRe + x * Re_factor;
			z_re = c_re;
			z_im = c_im;
			inside = 1;
			n = 0;
		while (n <= maxiterations)
		{
			z_re2 = z_re * z_re;
			z_im2 = z_im * z_im;
			if (z_re2 + z_im2 > 4)
			{
				inside = 0;
				break;
			}
			z_im = 2 * z_re * z_im + c_im;
        	z_re = z_re2 - z_im2 + c_re;
			n++;
		}
		if (!inside)
		{
			if (n < maxiterations / 2 - 1)
				color = (n % 8) * 0x00FFFFFF;
			if (n < maxiterations - 1)
				color = (n % 8) * 0x00FFFFFF;
			else if (n == maxiterations)
				color = 0x00CC0000;
			my_mlx_pixel_put(data, x, y, color);
		}
		else
		my_mlx_pixel_put(data, x, y, 0x00000000);
		x++;
		}
		y++;
	}
}