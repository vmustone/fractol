/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:32:26 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/27 18:02:31 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_esc(int keycode, t_vars *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int	close_cross(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	mouse_zoom_down(int button, int x, int y, t_vars *param)
{
	t_data	*zoom;

	zoom = param->data;
	x = 0;
	y = 0;
	if (button == ON_MOUSEDOWN)
	{
		zoom->minre = ((double) x + zoom->minre) / 1.2;
		zoom->maxre = ((double) x + zoom->maxre) / 1.2;
		zoom->minim = ((double) y + zoom->minim) / 1.2;
		zoom->maxim = ((double) y + zoom->maxim) / 1.2;
		zoom->re_factor = (zoom->maxre - zoom->minre) / (WIDTH - 1);
		zoom->im_factor = (zoom->maxim - zoom->minim) / (HEIGHT - 1);
		if (param->data->set == JULIA)
			draw_julia(param);
		else
			draw_mandelbrot(param);
	}
	mouse_zoom_up(button, x, y, param);
	return (0);
}

int	mouse_zoom_up(int button, int x, int y, t_vars *param)
{
	t_data	*zoom;

	zoom = param->data;
	x = 0;
	y = 0;
	if (button == ON_MOUSEUP)
	{
		zoom->minre *= 1.2;
		zoom->maxre *= 1.2;
		zoom->minim *= 1.2;
		zoom->maxim *= 1.2;
		zoom->re_factor = (zoom->maxre - zoom->minre) / (WIDTH - 1);
		zoom->im_factor = (zoom->maxim - zoom->minim) / (HEIGHT - 1);
		if (param->data->set == JULIA)
			draw_julia(param);
		else
			draw_mandelbrot(param);
	}
	return (0);
}