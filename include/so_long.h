/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:32:40 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/27 21:58:09 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Macro  for the game
# define PIXEL 32
# define WALL_XMP "./img/wall.xpm"
# define FLOOR_XMP "./img/floor.xpm"
# define COIN_XMP "./img/coin.xpm"
# define PLAYER_XMP "./img/player.xpm"
# define EXIT_XMP "./img/exit.xpm"
# define W 119
# define A 97
# define S 115
# define D 100
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_game
{
	int			x;
	int			y;
	int			player_x;
	int			player_y;

}				t_game;

typedef struct s_map_check
{
	int			exit;
	int			player;
	int			collect;
	int			empty;
	int			wall;
	int			unvalid;
	int			rows;
	int			cols;
}				t_map_check;

typedef struct s_pars
{
	int			closed;
	int			rect;
	int			error;
	int			all;
	int			fd;
	char		**pars;
}				t_pars;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			img_width;
	int			img_height;
	void		*img;
	int			y;
	int			x;
	char		*filename;
	char		**get;
	int			key_hook;
	int			collect_curr;
	t_pars		pars;
	t_game		map;
	t_map_check	data;
}				t_mlx;

char			**get_map(t_game *map, char *filename);
int				count_lines(char *filename);
int				get_map_fd(char *filename);
int				verify_map(t_mlx *params);
int				check_map(char *filename);
void			free_map(char **map);
int				is_map_closed(char **map, t_game *map_c);
int				check_map_rectangular(char **map, t_game *map_c);
void			pars_map(t_mlx *params);
void			process_char(char c, t_mlx *data);
int				is_exit_next_to_z(char **map, int i, int j);
int				check_exit(char **map);
void			error_map(char **map, char *msn_error);
int				flood_fill(char **tab, t_game *map, t_mlx *params);
void			get_player_pos(t_mlx *params);
char			**cpy_map(char **map, int line_count);
void			process_fill(t_mlx *params, char **cpy);
int				check_map_value(t_map_check *data);
void			map_check_data_init(t_map_check *data);
void			init_params(t_mlx *params);
void			init_game(t_mlx *params);
int				close_mouse(t_mlx *params);
int				echap_key(int keysym, t_mlx *params);
void			control_command(t_mlx *params);
void			control_command(t_mlx *params);
void			handle_movement(t_mlx *params, int new_y, int new_x);
int				free_all(t_mlx *params);
void			init_player(t_mlx *params);
int				key_maps(int key_hook, t_mlx *params);

#endif