# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoinus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 13:11:55 by acoinus           #+#    #+#              #
#    Updated: 2021/12/21 12:04:46 by acoinus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC			= check.c\
			  ft_list.c\
			  main.c\
			  libft/ft_atoi.c\
			  libft/ft_free.c\
			  libft/ft_split.c\
			  libft/ft_strjoin.c\
			  libft/ft_strlen.c\
			  algo/algo.c\
			  algo/algo_345.c\
			  algo/operation.c\
			  algo/operation2.c\
			  algo/big_nb.c\

OBJ			= $(SRC:.c=.o)

CC			= clang

FLAGS		= -Wall -Wextra -Werror

FS			= -fsanitize=address -g3

RM			= rm -f

all			: $(NAME)

$(NAME)		: $(OBJ)
					$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB)

%.o			: %.c
					$(CC) $(FLAGS) -o $@ -c $<

norme		:
					norminette $(SRC)
					norminette push_swap.h

clean		:
					$(RM) $(OBJ)

fclean		: clean
					$(RM) $(NAME)

re			: fclean all

s			: $(OBJ)
					$(CC) $(FLAGS) $(FS) -o $(NAME) $(SRC)

sre			: fclean s

.PHONY		: all norme clean fclean re


