# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2023/03/13 11:06:59 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft.a

SRC = main.c key_controls.c mouse_controls.c draw_mandelbrot.c draw_julia.c fractol_utils.c

SBONUS = mouse_controls_bonus.c key_controls_bonus.c main.c draw_mandelbrot.c draw_julia.c fractol_utils.c

OSRC = $(SRC:%.c=%.o)

OBONUS = $(SBONUS:%.c=%.o)

WWW = -Wall -Wextra -Werror -march=skylake -Ofast

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OSRC)
	cc $(WWW) $(OSRC) -L libft/ -lft -lmlx -framework OpenGL -framework Appkit -o $(NAME)

bonus: $(OBONUS)
	cc $(WWW) $(OBONUS) -L libft/ -lft -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	rm -f $(OSRC) $(OBONUS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/$(LIBFT)

%.o: %.c
	cc $(WWW) -c -o $@ $^ 

re: fclean all
