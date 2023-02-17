/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:18:31 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/17 15:38:54 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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