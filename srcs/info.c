/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:51:54 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/09 14:48:23 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	info(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 5, 0xFFFFFF, "RED");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 100, 5, 0xFFFFFF,
	ft_itoa(map->color_s->r));
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 25, 0xFFFFFF, "GREEN");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 100, 25, 0xFFFFFF,
	ft_itoa(map->color_s->g));
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 45, 0xFFFFFF, "BLUE");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 100, 45, 0xFFFFFF,
	ft_itoa(map->color_s->b));
}
