/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:47:03 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/27 16:00:24 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void draw_pixel(t_vars *vars, double z_re, double z_im, int x, int y)
{
	double	c_re = 0.0;
	double	c_im = -0.8;
	double	z_re2;
	double	z_im2;
	int		inside = 1;
	int		n = 0;
	int		color = 0x00000000;

	while (n <= MAX_ITER)
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
		if (n < MAX_ITER * 0.5)
			color = 0x00FFFFFF;
		if (n == MAX_ITER || n > MAX_ITER * 0.3)
			color = (n % 8) * 0x00CC0000;
	}
	my_mlx_pixel_put(vars, x, y, color);
}

static void draw_row(t_vars *vars, t_data *d, double c_im, int y)
{
	int 	x;
	double	c_re;

	x = 0;
	
	while (x < WIDTH)
	{
		c_re = d->minre + (x * d->re_factor);
		draw_pixel(vars, c_re, c_im, x, y);
		x++;
	}
}
#include <stdio.h>
void	draw_julia(t_vars *vars)
{
	t_data *d;
	int		y;
	double	c_im;
	
	d = vars->data;
	y = 0;
	while (y < HEIGHT)
	{
		c_im = d->minim + (y * d->im_factor);
		draw_row(vars, d, c_im, y);
		y++;
	}
	printf("maxre: %f\tmaxim: %f\nminre: %f\tminim: %f\n", d->maxre, d->maxim, d->minre, d->minim);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}