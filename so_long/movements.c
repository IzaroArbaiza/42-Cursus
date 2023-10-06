/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:20:29 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/06/29 10:20:25 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_map *m)
{
	if (key == KEY_ESQ)
		exit(0);
	if (key == KEY_W)
		key_w(m);
	if (key == KEY_S)
		key_s(m);
	if (key == KEY_A)
		key_a(m);
	if (key == KEY_D)
		key_d(m);
	return (0);
}

void	key_w(t_map *m)
{
	if (m->map[m->player_y - 1][m->player_x] != '1')
	{
		if (!check_exit(m, m->player_y - 1, m->player_x))
		{
			m->player_y--;
			collect_item(m, m->player_y, m->player_x);
			set_player(m, m->player_y, m->player_x);
			set_floor(m, m->player_y + 1, m->player_x);
			m->move++;
		}
		ft_printf("%d Movimientos\n", m->move);
	}
}

void	key_s(t_map *m)
{
	if (m->map[m->player_y + 1][m->player_x] != '1')
	{
		if (!check_exit(m, m->player_y + 1, m->player_x))
		{
			m->player_y++;
			collect_item(m, m->player_y, m->player_x);
			set_player(m, m->player_y, m->player_x);
			set_floor(m, m->player_y - 1, m->player_x);
			m->move++;
		}
		ft_printf("%d Movimientos\n", m->move);
	}
}

void	key_a(t_map *m)
{
	if (m->map[m->player_y][m->player_x - 1] != '1')
	{
		if (!check_exit(m, m->player_y, m->player_x - 1))
		{
			m->player_x--;
			collect_item(m, m->player_y, m->player_x);
			set_player(m, m->player_y, m->player_x);
			set_floor(m, m->player_y, m->player_x + 1);
			m->move++;
		}
		ft_printf("%d Movimientos\n", m->move);
	}
}

void	key_d(t_map *m)
{
	if (m->map[m->player_y][m->player_x + 1] != '1')
	{
		if (!check_exit(m, m->player_y, m->player_x + 1))
		{
			m->player_x++;
			collect_item(m, m->player_y, m->player_x);
			set_player(m, m->player_y, m->player_x);
			set_floor(m, m->player_y, m->player_x - 1);
			m->move++;
		}
		ft_printf("%d Movimientos\n", m->move);
	}
}
