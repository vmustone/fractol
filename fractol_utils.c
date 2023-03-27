/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:52:56 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/23 14:23:07 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int color)
{
	char	*dst;

	dst = vars->addr + (vars->y * vars->line_length + vars->x * \
	(vars->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	init_mandel(t_vars *vars)
{
	vars->minre = -2.0;
	vars->maxre = 1.0;
	vars->minim = -1.5;
	vars->maxim = 1.5;
	vars->re_factor = (vars->maxre - vars->minre) / (WIDTH - 1);
	vars->im_factor = (vars->maxim - vars->minim) / (HEIGHT - 1);
}

void	init_julia(t_vars *vars, char **argv)
{
	vars->minre = -2.0;
	vars->maxre = 2.0;
	vars->minim = -1.5;
	vars->maxim = 1.5;
	vars->julia_c = 0.0;
	vars->julia_i = -0.8;
	if (argv[2] && ft_atof(argv[2]) != 0)
		vars->julia_c = ft_atof(argv[2]);
	if (argv[3] && ft_atof(argv[3]) != 0)
		vars->julia_i = ft_atof(argv[3]);
	vars->re_factor = (vars->maxre - vars->minre) / (WIDTH - 1);
	vars->im_factor = (vars->maxim - vars->minim) / (HEIGHT - 1);
}
