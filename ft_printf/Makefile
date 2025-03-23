# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iltellat <iltellat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 17:20:55 by iltellat          #+#    #+#              #
#    Updated: 2024/11/13 20:38:51 by iltellat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf utils/ft_strlen utils/ft_putchar utils/ft_putstr utils/ft_putnbr \
		utils/ft_putnbr_base utils/ft_putunbr
HEADER = ft_printf.h utils/utils.h
OBJ = $(SRCS:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(AR) $(NAME) $(OBJ)

%.o:%.c $(HEADER)
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: clean