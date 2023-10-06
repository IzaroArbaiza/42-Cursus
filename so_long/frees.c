/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:02:59 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/07/03 10:33:43 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_map *m)
{
	mlx_destroy_window(m->mlx, m->mlx_win);
	destroy_images(m);
	free(m->mlx);
	exit(0);
}

void	destroy_images(t_map *m)
{
	mlx_destroy_image(m->mlx, m->wall_img);
	mlx_destroy_image(m->mlx, m->floor_img);
	mlx_destroy_image(m->mlx, m->player_img);
	mlx_destroy_image(m->mlx, m->coin_img);
	mlx_destroy_image(m->mlx, m->exit_img);
}

void	free_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		free(m->map[i]);
		i++;
	}
	free(m->map);
}
