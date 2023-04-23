# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 11:49:02 by yassine           #+#    #+#              #
#    Updated: 2023/03/28 00:24:12 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
SRC_DIR     := src
BUILD_DIR   := .build
SRCS		:= 	\
			bool/ft_isalpha.c \
			bool/ft_isdigit.c \
			bool/ft_isascii.c \
			bool/ft_isalnum.c \
			bool/ft_isspace.c \
			ctypes/ft_tolower.c \
			ctypes/ft_toupper.c \
			stdlib/ft_atoi.c	\
			stdlib/ft_calloc.c \
			stdlib/ft_strdup.c \
			stdlib/ft_swap.c\
			strings/ft_bzero.c \
			strings/ft_memchr.c \
			strings/ft_memcmp.c \
			strings/ft_memset.c \
			strings/ft_memove.c\
			strings/ft_memset.c\
			strings/ft_strchr.c \
			strings/ft_strlcat.c \
			strings/ft_strlcpy.c \
			strings/ft_strlen.c \
			strings/ft_strncmp.c\
			strings/ft_strnstr.c\
			strings/ft_split.c\
			strings/ft_striteri.c\
			strings/ft_strmapi.c\
			strings/ft_strnstr.c\
			strings/ft_strrchr.c\
			strings/ft_substr.c\
			strings/ft_strtrim.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_printf_utils.c \
			ft_printf/ft_printf_utils_2.c \
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			get_next_line/get_next_line_utils_bonus.c\
			get_next_line/get_next_line_bonus.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT: