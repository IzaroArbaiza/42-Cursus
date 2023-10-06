/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:09:54 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/07/03 17:48:45 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "GNL/get_next_line.h"

char	**read_map(int fd, t_map *m)
{
	get_read_map(fd, m);
	close(fd);
	get_map_info(m);
	if (errors(m) == 0)
		return (0);
	return (m->map);
}

void	get_map_info(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	m->heigth = 0;
	m->width = ft_strlen_sl(m->map[y]);
	m->coin = 0;
	m->player = 0;
	m->exit = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'C')
				m->coin++;
			else if (m->map[y][x] == 'P')
				m->player++;
			else if (m->map[y][x] == 'E')
				m->exit++;
			x++;
		}
		y++;
	}
	m->heigth = y;
}

void	get_read_map(int fd, t_map *m)
{
	char	*line;
	char	*map;

	line = NULL;
	map = NULL;
	while (1) 
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin_sl(map, line);
		free(line);
	}
	if(map != NULL)
	{
		m->map = ft_split_sl(map, '/');
		m->map_ = ft_split_sl(map, '/');
		free(map);
	}
	else
	{
		ft_printf("Error\nArchivo vacio");
		exit(0);
	}
}
