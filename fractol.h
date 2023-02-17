/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:51:36 by vmustone          #+#    #+#             */
/*   Updated: 2023/02/17 15:04:44 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 50
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	int		y;
	int		x;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	c_re;
	double	c_im;
	double	re_factor;
	double	im_factor;
	int	lock;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_data	*data;
}				t_vars;

enum e_keys 
{
    ESC=53,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
    LEFT_ARROW=123,
    UP_ARROW=126,
    DOWN_ARROW=125,
    RIGHT_ARROW=124,
    I_KEY=34,
    Z_KEY=6,
    C_KEY=8,
    H_KEY=4,
    R_KEY=15
};

int	main(void);
#endif