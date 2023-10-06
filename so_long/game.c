/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:09:40 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/06/29 15:28:19 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map *m)
{
	m->move = 0;
	m->c_coin = 0;
	m->mlx = mlx_init();
	m->mlx_win = mlx_new_window(m->mlx, m->width * 16, 
			m->heigth * 16, "So_long");
	images(m);
	put_images(m);
	mlx_hook(m->mlx_win, 2, 1, key_hook, m);
	mlx_hook(m->mlx_win, 17, 1, close_game, m);
	mlx_loop(m->mlx);
}

void	set_floor(t_map *m, int y, int x)
{
	if (m->map[y][x] != '1')
	{
		mlx_put_image_to_window(m->mlx, m->mlx_win, 
			m->floor_img, x * 16, y * 16);
		m->map[m->player_y][m->player_x] = '0';
	}
}

void	set_player(t_map *m, int y, int x)
{
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->player_img, x * 16, y * 16);
	m->map[m->player_y][m->player_x] = 'P';
}

void	collect_item(t_map *m, int y, int x)
{
	if (m->map[y][x] == 'C')
		m->c_coin++;
}

int	check_exit(t_map *m, int y, int x)
{
	if (m->map[y][x] == 'E')
	{
		if (m->coin == m->c_coin)
		{
			ft_printf("\nHas ganado!🎉🎉\n");
			ft_printf("%d Movimientos\n", m->move);
			close_game(m);
		}
		else
			return (1);
	}
	return (0);
}
