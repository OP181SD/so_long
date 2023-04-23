# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 19:00:07 by yasaidi           #+#    #+#              #
#    Updated: 2023/03/28 16:19:42 by yasaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
SRC_DIR		:= src
BUILD_DIR	:= .build
SRCS		:= 	\
			so_long.c \
			map/map.c \
			parsing/pars_map.c\
			parsing/map_closed.c\
			parsing/map_rect.c\
			parsing/error_map.c\
			parsing/flood_fill.c\
			check_map/check_map.c\
			check_map/extension_check.c\
			utils/utils.c \
			asset_mlx/game.c\
			asset_mlx/command.c\
			asset_mlx/mouvement.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I include -I ./inc -I ./libft -I ./mlx
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)
LIBRARIES	:= -L libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
INCLUDES	:= -Ilibft/include

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
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