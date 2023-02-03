#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	close(2, vars);
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
	unsigned	y = 0;
	unsigned	x = 0;
	unsigned	n;
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
	int		maxiterations = 30;
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
			if (n < maxiterations * 0.6)
				color = 0x00FFFFFF;
			if (n == maxiterations || n > maxiterations * 0.6)
				color = (n % 8) * 0x00CC0000;
			else if (n < maxiterations * 0.5)
				color = 0x00660000;
			my_mlx_pixel_put(data, x, y, color);
		}
		else
			my_mlx_pixel_put(data, x, y, 0x00000000);
		x++;
		}
		y++;
	}
}

int	main(void)
{
	t_data	img;
	t_vars	vars;
	int key = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "fractol");
	img.img = mlx_new_image(vars.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_mandelbrot(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}