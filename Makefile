# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmota <kmota@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/16 12:18:10 by kmota             #+#    #+#              #
#    Updated: 2026/11/16 13:39:02 by kmota            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: libftprintf.a 
CC: cc
CFLAGS: -Wall -Wextra -Werror
RM: rm -f
AR: ar rcs

SRCS = ft_printf.c ft_putchar.c ft_putstr.c

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