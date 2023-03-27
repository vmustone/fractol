/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:51:45 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/23 22:27:50 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, close_cross, vars);
	mlx_key_hook(vars->win, key_controls, vars);
	mlx_mouse_hook(vars->win, mouse_zoom, vars);
}

void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fractol");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, \
	&vars->line_length, &vars->endian);
}

void	check_fractol(char **argv, t_vars *vars)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && !argv[2])
	{
		init_mandel(vars);
		init_mlx(vars);
		draw_mandelbrot(vars);
		vars->set = MANDELBROT;
	}
	else if ((ft_strcmp(argv[1], "julia") == 0))
	{
		init_julia(vars, argv);
		init_mlx(vars);
		draw_julia(vars);
		vars->set = JULIA;
	}
	else
	{
		ft_printf("Avaible fractols: mandelbrot, julia\n");
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2 || argc > 4)
	{
		ft_printf("Avaible fractols: mandelbrot, julia\n");
		exit(0);
	}
	if (argc > 1)
		check_fractol(argv, &vars);
	hooks(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
