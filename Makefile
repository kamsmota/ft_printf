# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kams <kams@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/16 12:18:10 by kmota             #+#    #+#              #
#    Updated: 2026/11/18 20:51:39 by kams             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRCS = ft_printf.c ft_putchar.c ft_puthex.c ft_putintus.c ft_putnbr.c ft_putptr.c ft_putstr.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re 