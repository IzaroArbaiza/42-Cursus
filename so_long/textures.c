/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:02:07 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/06/29 11:35:30 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_map *m)
{
	int	windth;
	int	heigth;

	m->wall_img = mlx_xpm_file_to_image (m->mlx, WALL, &windth, &heigth);
	m->floor_img = mlx_xpm_file_to_image (m->mlx, FLOOR, &windth, &heigth);
	m->coin_img = mlx_xpm_file_to_image (m->mlx, COIN, &windth, &heigth);
	m->player_img = mlx_xpm_file_to_image (m->mlx, PLAYER, &windth, &heigth);
	m->exit_img = mlx_xpm_file_to_image (m->mlx, EXIT, &windth, &heigth);
}

void	put_images(t_map *m)
{
	t_posi	p;

	p.y = 0;
	while (m->map[p.y])
	{
		p.x = 0;
		while (m->map[p.y][p.x])
		{
			mlx_put_image_to_window (m->mlx, m->mlx_win, 
				m->floor_img, p.x * 16, p.y * 16);
			if (m->map[p.y][p.x] == '1')
				mlx_put_image_to_window (m->mlx, m->mlx_win,
					m->wall_img, p.x * 16, p.y * 16);
			else
			{
				mlx_put_image_to_window (m->mlx, m->mlx_win, 
					m->floor_img, p.x * 16, p.y * 16);
				put_item_images(m, p);
			}
			p.x++;
		}
		p.y++;
	}
}

void	put_item_images(t_map *m, t_posi p)
{
	if (m->map[p.y][p.x] == 'C')
		mlx_put_image_to_window (m->mlx, m->mlx_win, 
			m->coin_img, p.x * 16, p.y * 16);
	else if (m->map[p.y][p.x] == 'E')
		mlx_put_image_to_window (m->mlx, m->mlx_win, 
			m->exit_img, p.x * 16, p.y * 16);
	else if (m->map[p.y][p.x] == 'P')
	{
		mlx_put_image_to_window (m->mlx, m->mlx_win, 
			m->player_img, p.x * 16, p.y * 16);
		m->player_x = p.x;
		m->player_y = p.y;
	}
}
