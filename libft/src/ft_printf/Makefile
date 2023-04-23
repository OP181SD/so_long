# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 07:56:45 by yasaidi           #+#    #+#              #
#    Updated: 2022/12/13 13:43:46 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils_2.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

%.o: %.c
	${CC} ${CFLAGS} -c -I. $< -o $@

${NAME} : $(OBJS)
	ar rc  $(NAME) $(OBJS)

all		: ${NAME}

clean	:
	rm -f  $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re		:	fclean all


.PHONY: all clean fclean re bonus
