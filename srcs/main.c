/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:18:11 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/09 14:51:23 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			expose_hook(t_map *map)
{
	if (map == NULL)
		;
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	ac = 1;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	map = init_map(av[1]);
	ft_create_map(av[1], map);
	init_image(map->mlx_ptr, &map);
	create_image(&map);
	mlx_expose_hook(map->win_ptr, expose_hook, map);
	mlx_hook(map->win_ptr, 2, 1, key_hook, map);
	mlx_loop(map->mlx_ptr);
	free(map->grille);
	return (0);
}
