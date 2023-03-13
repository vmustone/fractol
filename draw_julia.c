/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:47:03 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/08 00:39:36 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_color(t_vars *vars, double z_re, double z_im)
{
	vars->iter_count = 0;
	while (vars->iter_count <= MAX_ITER)
	{
		vars->z_re2 = z_re * z_re;
		vars->z_im2 = z_im * z_im;
		if (vars->z_re2 + vars->z_im2 > 4)
		{
			vars->inside = 0;
			break ;
		}
		z_im = 2 * z_re * z_im + vars->julia_i;
		z_re = vars->z_re2 - vars->z_im2 + vars->julia_c;
		vars->iter_count++;
	}
	if (vars->iter_count == MAX_ITER)
		my_mlx_pixel_put(vars, 0x00000000);
	else
		my_mlx_pixel_put(vars, 0x00003300 * vars->iter_count);
}

static void	draw_row(t_vars *vars, double c_im)
{
	vars->x = 0;
	while (vars->x < WIDTH)
	{
		vars->c_re = vars->minre + (vars->x * vars->re_factor);
		change_color(vars, vars->c_re, c_im);
		vars->x++;
	}
}

void	draw_julia(t_vars *vars)
{
	vars->y = 0;
	while (vars->y < HEIGHT)
	{
		vars->c_im = vars->maxim - (vars->y * vars->im_factor);
		draw_row(vars, vars->c_im);
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
