# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 15:52:33 by vmustone          #+#    #+#              #
#    Updated: 2022/11/22 09:45:47 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -I.

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	   	ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcpy.c\
		ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
		ft_putendl_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c\
		ft_split.c ft_itoa.c

OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
		ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o\
		ft_memmove.o ft_memset.o ft_strchr.o ft_strdup.o ft_strlcpy.o\
		ft_strlcat.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o\
		ft_tolower.o ft_toupper.o ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o\
		ft_putendl_fd.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_strmapi.o ft_striteri.o\
		ft_split.o ft_itoa.o

SBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
		ft_lstmap_bonus.c

OBONUS = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o\
		ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o\
		ft_lstmap_bonus.o

all: $(NAME)
$(NAME):
	cc -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

bonus: $(OBONUS)
$(OBONUS):
	cc -c $(FLAGS) $(SBONUS)
	ar rus $(NAME) $(OBONUS)

clean:
	/bin/rm -f $(OBJ) $(OBONUS)

fclean:
	/bin/rm -f $(OBJ) $(OBONUS) $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
