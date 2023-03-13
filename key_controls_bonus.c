/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:55:40 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/08 00:55:46 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_esc(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	close_cross(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

void	arrow_move(int button, t_vars *vars)
{
	if (button == UP_ARROW)
	{
		vars->minim += 0.05;
		vars->maxim += 0.05;
	}
	if (button == DOWN_ARROW)
	{
		vars->minim -= 0.05;
		vars->maxim -= 0.05;
	}
	if (button == LEFT_ARROW)
	{
		vars->minre -= 0.05;
		vars->maxre -= 0.05;
	}
	if (button == RIGHT_ARROW)
	{
		vars->minre += 0.05;
		vars->maxre += 0.05;
	}
}

int	key_controls(int button, t_vars *vars)
{
	if (button == ESC)
		close_esc(vars);
	if (button == UP_ARROW)
		arrow_move(button, vars);
	if (button == DOWN_ARROW)
		arrow_move(button, vars);
	if (button == LEFT_ARROW)
		arrow_move(button, vars);
	if (button == RIGHT_ARROW)
		arrow_move(button, vars);
	if (vars->set == JULIA)
		draw_julia(vars);
	else
		draw_mandelbrot(vars);
	return (0);
}
