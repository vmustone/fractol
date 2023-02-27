/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:51:45 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/27 17:59:05 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*) dst = color;
}

int	main(int argc, char *argv[])
{
	t_vars	*data;
	t_data	*zoom;

	data = malloc(sizeof(t_vars));
	if (!data)
		return (0);
	zoom = malloc(sizeof(t_data));
	if (!zoom)
		return (0);
	declaration(zoom);
	data->data = zoom;
	if (argc == 2)
	{
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
		data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		if (!ft_strncmp(argv[1], "julia", 5))
			{
				draw_julia(data);
				zoom->set = JULIA;
			}
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			draw_mandelbrot(data);
	}
	mlx_hook(data->win, 2, 0, close_esc, data);
	mlx_hook(data->win, 17, 0, close_cross, data);
	mlx_hook(data->win, 4, 0, mouse_zoom_down, data);
	mlx_hook(data->win, 5, 0, mouse_zoom_up, data);
	mlx_loop(data->mlx);
	return (0);
}