/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 01:01:19 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/08 01:01:27 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cursor_coordinates(double mouse_x, double mouse_y, t_vars *vars)
{
	double	midpoint;

	mouse_x = vars->minre + (((vars->maxre - vars->minre) / WIDTH) * mouse_x);
	mouse_y = vars->maxim - (((vars->maxim - vars->minim) / HEIGHT) * mouse_y);
	midpoint = (vars->maxre + vars->minre) / 2.0;
	vars->minre += mouse_x - midpoint;
	vars->maxre += mouse_x - midpoint;
	midpoint = (vars->maxim + vars->minim) / 2.0;
	vars->minim += mouse_y - midpoint;
	vars->maxim += mouse_y - midpoint;
}

void	zoom_in(t_vars *vars)
{
	double	midpoint;

	midpoint = (vars->maxre + vars->minre) / 2.0;
	vars->minre = (midpoint + vars->minre) / 2.0;
	vars->maxre = (midpoint + vars->maxre) / 2.0;
	midpoint = (vars->maxim + vars->minim) / 2.0;
	vars->minim = (midpoint + vars->minim) / 2.0;
	vars->maxim = (midpoint + vars->maxim) / 2.0;
	vars->re_factor = (vars->maxre - vars->minre) / (WIDTH - 1);
	vars->im_factor = (vars->maxim - vars->minim) / (HEIGHT - 1);
	if (vars->set == JULIA)
		draw_julia(vars);
	else
		draw_mandelbrot(vars);
}

void	zoom_out(t_vars *vars)
{
	vars->minre -= 0.2;
	vars->maxre += 0.2;
	vars->minim -= 0.2;
	vars->maxim += 0.2;
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
		cursor_coordinates(x, y, vars);
		zoom_in(vars);
	}
	if (button == ON_MOUSEUP)
	{
		cursor_coordinates(x, y, vars);
		zoom_out(vars);
	}
	return (0);
}
