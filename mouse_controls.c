/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:12:04 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/13 11:32:01 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_vars *vars)
{
	x = 0;
	y = 0;
	vars->minre = ((double) x + vars->minre) / 1.5;
	vars->maxre = ((double) x + vars->maxre) / 1.5;
	vars->minim = ((double) y + vars->minim) / 1.5;
	vars->maxim = ((double) y + vars->maxim) / 1.5;
	vars->re_factor = (vars->maxre - vars->minre) / (WIDTH - 1);
	vars->im_factor = (vars->maxim - vars->minim) / (HEIGHT - 1);
	if (vars->set == JULIA)
		draw_julia(vars);
	else
		draw_mandelbrot(vars);
}

void	zoom_out(int x, int y, t_vars *vars)
{
	x = 0;
	y = 0;
	vars->minre *= 1.5;
	vars->maxre *= 1.5;
	vars->minim *= 1.5;
	vars->maxim *= 1.5;
	vars->re_factor = (vars->maxre - vars->minre) / (WIDTH - 1);
	vars->im_factor = (vars->maxim - vars->minim) / (HEIGHT - 1);
	if (vars->set == JULIA)
		draw_julia(vars);
	else
		draw_mandelbrot(vars);
}

int	mouse_zoom(int button, int x, int y, t_vars *vars)
{
	if (button == ON_MOUSEDOWN)
	{
		zoom_in(x, y, vars);
	}
	if (button == ON_MOUSEUP)
	{
		zoom_out(x, y, vars);
	}
	return (0);
}
