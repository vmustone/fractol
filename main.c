/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:51:45 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/17 16:53:21 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	declaration(t_data *value)
{
	value->y = 0;
	value->x = 0;
	value->minre = -2.0;
	value->maxre = 1.0;
	value->minim = -1.5;
	value->maxim = 1.5; //value->minim + (value->maxre - value->minre) * WIDTH/HEIGHT;
	value->re_factor = (value->maxre - value->minre)/(WIDTH - 1);
	value->im_factor = (value->maxim - value->minim)/(HEIGHT - 1);
}

int	close_esc(int keycode, t_vars *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int close_cross(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_mandelbrot(t_vars *vars)
{
	int	y = 0;
	int	x = 0;
	int	n;
	int		inside;
	unsigned int	color = 0x00000000;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	t_data	*d;
	
	d = vars->data;
	
	while (y < HEIGHT)
	{
		c_im = d->maxim - y * d->im_factor;
		x = 0;
		while (x < WIDTH)
		{
			c_re = d->minre + x * d->re_factor;
			z_re = c_re;
			z_im = c_im;
			inside = 1;
			n = 0;
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
			my_mlx_pixel_put(vars, x, y, color);
		}
		else
			my_mlx_pixel_put(vars, x, y, 0x00000000);
		x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
/*
void cursor_coordinate(int x, int y, t_data *data) 
 { 
    double mouse_x; 
    double mouse_y; 
    double midpoint; 

    mouse_x = data->minre + (((data->maxre - data->minre) / WIDTH) * x);
	mouse_y = data->minim + (((data->maxim - data->minim) / HEIGHT) * y);
    midpoint = (data->maxre + data->minre) / 1.22;
    data->minre += mouse_x - midpoint;
    data->maxre += mouse_x - midpoint;
    midpoint = (data->maxim + data->minim) / 1.2;
    data->minim += mouse_y - midpoint;
    data->maxim += mouse_y - midpoint;	
 }
*/
int mouse_zoom(int button, int x, int y, t_vars *d)
{
	t_data	*zoom;
	double	x_mouse;
	double	y_mouse;
	zoom = d->data;
	x_mouse = x * zoom->re_factor + zoom->minre;
	y_mouse = y * zoom->im_factor - zoom->minim;

	zoom = d->data;
	if (button == 1)
	{
		/*
		xmouse on xskaalan uusi keskikohta
		ymouse on yskaalan uusi keskikohta
		laske nykyinen keskikohta
		laske erot keskikohdasta
		laita erot uuden keskikohdan mukaan
		*/
			
		printf("%f\n%f\n", (HEIGHT -y) * zoom->im_factor + zoom->minim, x * zoom->re_factor + zoom->minre);
	}
	if (button == ON_MOUSEDOWN)
	{
		x = 0;
		y = 0;
		zoom->minre = ((double)x + zoom->minre) / 1.2;
		zoom->maxre = ((double)x + zoom->maxre) / 1.2;
		zoom->minim = ((double)y + zoom->minim) / 1.2;
		zoom->maxim = zoom->minim + (zoom->maxre - zoom->minre) * WIDTH/HEIGHT;
		zoom->re_factor = (zoom->maxre - zoom->minre)/(WIDTH - 1);
		zoom->im_factor = (zoom->maxim - zoom->minim)/(HEIGHT - 1);
		draw_mandelbrot(d);
	}
	if (button == ON_MOUSEUP)
	{
		zoom->minre *= 1.2;
		zoom->maxre *= 1.2;
		zoom->minim *= 1.2;
		zoom->maxim = zoom->minim + (zoom->maxre - zoom->minre) * WIDTH/HEIGHT;
		zoom->re_factor = (zoom->maxre - zoom->minre)/(WIDTH - 1);
		zoom->im_factor = (zoom->maxim - zoom->minim)/(HEIGHT - 1);
		draw_mandelbrot(d);
	}
	return (0);
}


int	main(void)
{
	t_vars	*data;
	t_data	*zoom;

	data = malloc(sizeof(t_vars));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	zoom = malloc(sizeof(t_data));
	if (!zoom)
		return (0);
	declaration(zoom);
	data->data = zoom;
	draw_mandelbrot(data);
	mlx_hook(data->win, 2, 0, close_esc, data);
	mlx_hook(data->win, 17, 0, close_cross, data);
	//cursor_coordinate(0, 0, zoom);
	mlx_hook(data->win, 4, 0, mouse_zoom, data);
	mlx_loop(data->mlx);
}