/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:51:45 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/13 13:46:54 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>

typedef struct	s_mandel
{
	unsigned		y;
	unsigned		x;
	unsigned		n;
	int				inside;
	unsigned int	color;
	double			MinRe;
	double			MaxRe;
	double			MinIm;
	double			MaxIm;
	double			Re_factor;
	double			Im_factor;
	double			c_re;
	double			c_im;
	double			z_re;
	double			z_im;
	double			z_re2;
	double			z_im2;
	int				maxiterations;
}				t_mandel;


typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	close_esc(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int close_red_cross(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_mandelbrot(t_data *data)
{
	int	y = 0;
	int	x = 0;
	int	n;
	int		inside;
	unsigned int	color = 0x00000000;
	double	MinRe = -2.0;
	double	MaxRe = 1.0;
	double	MinIm = -1.2;
	double	MaxIm = MinIm + (MaxRe - MinRe) * 800/800;
	double	Re_factor = (MaxRe - MinRe)/(800 - 1);
	double	Im_factor = (MaxIm - MinIm)/(800 - 1);
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		maxiterations = 1000;
	while (y < 800)
	{
		c_im = MaxIm - y * Im_factor;
		x = 0;
		while (x < 800)
		{
			c_re = MinRe + x * Re_factor;
			z_re = c_re;
			z_im = c_im;
			inside = 1;
			n = 0;
		while (n <= maxiterations)
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
			if (n < maxiterations * 0.3)
				color = 0x00FFFFFF;
			if (n == maxiterations || n > maxiterations * 0.02)
				color = (n % 8) * 0x00CC0000;
			my_mlx_pixel_put(data, x, y, color);
		}
		else
			my_mlx_pixel_put(data, x, y, 0x00000000);
		x++;
		}
		y++;
	}
}

/*int	zoom(t_data *data)
{
	double	Minre = -2.0;
	double	Maxre = 1.0;
	double	Minim = -1.2;
	double	Maxim = 1.2;
	double	real;
	double	imag;
	double	x = 0;
	double	y = 0;
	double	c;
	int		iterations = 0;

	while (y < 800)
	{
		while (x < 800)
		{
			real = Minre + x / 800 * (Maxre - Minre);
			imag = Minim + y / 800 * (Maxim - Minim);
			c = real + imag * iterations;
			iterations = draw_mandelbrot(data, 0.0, 0.0);
			x++;
		}
		y++;
	}
	return (0);
}
*/
int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "fractol");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	draw_mandelbrot(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 0, close_red_cross, &data);
	mlx_hook(data.win, 3, 0, close_esc, &data);
	//mlx_hook(data.win, 4, 0, zoom, &data);
	mlx_loop(data.mlx);
}