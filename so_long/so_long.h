/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:26:19 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:00 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESQ 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define WALL "textures/wall.xpm"
# define FLOOR "textures/floor.xpm"
# define PLAYER "textures/player.xpm"
# define COIN "textures/Noodle.xpm"
# define EXIT "textures/ScrollEmpty.xpm"
# define EXIT2 "textures/ScrollThunder.xpm"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "mini/mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct s_position
{
	int	x;
	int	y;
}	t_posi;

typedef struct mapa
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_;
	int		width;
	int		heigth;
	int		move;
	int		wall;
	int		floor;
	int		player;
	int		coin;
	int		c_coin;
	int		exit;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*coin_img;
	void	*exit_img;
	int		player_x;
	int		player_y;
	int		p_x;
	int		p_y;
	int		count;
}	t_map;

/* read map */
char	**read_map(int fd, t_map *m);
void	get_read_map(int fd, t_map *m);
void	get_map_info(t_map *m);

/* utils */
int		ft_strlen_sl(char *str);
char	*ft_strjoin_sl(char *s1, char *s2);
char	**ft_split_sl(const char *str, char c);

/* images */
void	put_images(t_map *m);
void	put_item_images(t_map *m, t_posi p);
void	images(t_map *m);

/* game */
void	start_game(t_map *m);
void	ft_game(t_map *m);

/* Keys */
int		key_hook(int key, t_map *m);
void	key_w(t_map *m);
void	key_s(t_map *m);
void	key_a(t_map *m);
void	key_d(t_map *m);

/* items */
void	set_floor(t_map *m, int y, int x);
void	set_player(t_map *m, int y, int x);
void	collect_item(t_map *m, int y, int x);
int		check_exit(t_map *m, int y, int x);

/* Free */
int		close_game(t_map *m);
void	destroy_images(t_map *m);
void	free_map(t_map *m);

/* Error */
int		map_error(t_map *m);
int		item_error(t_map *m);
int		rectangular(t_map *m, int i);
int		border_error(t_map *m, int i);
int		flood_fill(t_map *m);
void	playable(t_map *m, int y, int x);
void	search_player(t_map *m);
int		errors(t_map *m);

#endif
