/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:24:19 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/06/29 09:45:44 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->map_[y])
	{
		x = 0;
		while (m->map_[y][x])
		{
			if (m->map_[y][x] != '1' && m->map_[y][x] != '0' && 
					m->map_[y][x] != 'C' && m->map_[y][x] != 'P' 
					&& m->map_[y][x] != 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	item_error(t_map *m)
{
	if (m->coin < 1)
	{
		perror("Error\nEl mapa debe tener al menos 1 ramen");
		return (0);
	}
	if (m->player != 1)
	{
		perror("Error\nEl mapa debe tener un punto de partida");
		return (0);
	}
	if (m->exit != 1)
	{
		perror("Error\nEl mapa debe tener una salida");
		return (0);
	}
	return (1);
}

int	rectangular(t_map *m, int i)
{
	int	j;

	j = 0;
	while (m->map_[j])
	{
		if (i != ft_strlen_sl(m->map_[j]) - 1)
			return (0);
		j++;
	}
	return (1);
}

int	border_error(t_map *m, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (m->map_[x][++y])
		if (m->map_[x][y] != '1')
			return (0);
	x++;
	while (m->map_[x])
	{
		if (m->map_[x][0] != '1' || m->map_[x][i] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (m->map_[x - 1][++y])
		if (m->map_[x - 1][y] != '1')
			return (0);
	return (1);
}

int	errors(t_map *m)
{
	int	i;

	if (!map_error(m))
	{
		perror("Error\nFaltan objetos del mapa.");
		return (0);
	}
	if (!item_error(m))
		return (0);
	i = ft_strlen_sl(m->map_[0]) - 1;
	if (!rectangular(m, i))
		return (0);
	if (!border_error(m, i))
	{
		perror("Error\nEl mapa no está cerrado");
		return (0);
	}
	if (!flood_fill(m))
		return (0);
	return (1);
}
