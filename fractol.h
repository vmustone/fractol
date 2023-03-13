/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:51:36 by vmustone          #+#    #+#             */
/*   Updated: 2023/03/08 01:00:13 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# include "libft/libft.h"
# include <mlx.h>

enum e_keys
{
	ESC=53,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	LEFT_ARROW=123,
	UP_ARROW=126,
	DOWN_ARROW=125,
	RIGHT_ARROW=124,
};

enum e_set
{
	MANDELBROT,
	JULIA
};

typedef struct s_vars
{
	int				x;
	int				y;
	int				inside;
	int				iter_count;
	double			minre;
	double			maxre;
	double			minim;
	double			maxim;
	double			c_re;
	double			c_im;
	double			re_factor;
	double			im_factor;
	double			z_re;
	double			z_im;
	double			z_re2;
	double			z_im2;
	unsigned char	set;
	double			julia_c;
	double			julia_i;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_vars;

void	init_mandel(t_vars *data);
void	init_julia(t_vars *data, char **argv);
void	draw_mandelbrot(t_vars *vars);
void	draw_julia(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int color);
int		close_cross(t_vars *data);
int		key_controls(int button, t_vars *vars);
int		mouse_zoom(int button, int x, int y, t_vars *vars);
int		main(int argc, char **argv);
#endif