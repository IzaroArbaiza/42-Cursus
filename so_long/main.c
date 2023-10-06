/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:01:23 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/07/03 18:13:57 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	m;
	int		fd;

	if (argc < 2)
	{
		perror("Error!!\nAlgumentos incorrectos");
		return (1);
	}
	fd = open((argv[1]), O_RDONLY);
	if (fd <= 0)
	{
		perror("Error!!\nIntentalo de nuevo");
		return (0);
	}
	if (!read_map(fd, &m))
	{
		perror("Error!!\nFallo al leer el archivo");
		return (1);
	}
	start_game(&m);
	return (0);
}
