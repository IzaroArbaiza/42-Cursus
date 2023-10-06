/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:22:17 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/06/29 09:45:36 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_map *m)
{
	search_player(m);
	playable(m, m->p_y, m->p_x);
	if (m->count != m->coin + 1)
	{
		perror("Error\nEl mapa no es jugable");
		return (0);
	}
	return (1);
}

void	playable(t_map *m, int y, int x)
{
	if (m->map_[y][x] == 'C' || m->map_[y][x] == 'E')
		m->count++;
	if (m->map_[y][x] != '1' && m->map_[y][x])
	{
		m->map_[y][x] = '1';
		playable(m, y + 1, x);
		playable(m, y - 1, x);
		playable(m, y, x + 1);
		playable(m, y, x - 1);
	}
}

void	search_player(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
			{
				m->p_x = x;
				m->p_y = y; 
			}
			x++;
		}
		y++;
	}
}
