/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:17:48 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/09 14:47:42 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_close(t_map *map)
{
	free(map);
	exit(0);
	return ;
}

void		move_image(int keycode, t_map **map)
{
	if (keycode == 0)
		(*map)->new_point_win =
		new_point((*map)->new_point_win.x - 10, (*map)->new_point_win.y);
	if (keycode == 2)
		(*map)->new_point_win =
		new_point((*map)->new_point_win.x + 10, (*map)->new_point_win.y);
	if (keycode == 1)
		(*map)->new_point_win =
		new_point((*map)->new_point_win.x, (*map)->new_point_win.y + 10);
	if (keycode == 13)
		(*map)->new_point_win =
		new_point((*map)->new_point_win.x, (*map)->new_point_win.y - 10);
}

void		view(int keycode, t_map **map)
{
	if (keycode == 18)
	{
		(*map)->vector_y = create_vector(-10, 4);
		(*map)->vector_z = create_vector(0, -5.8);
		(*map)->vector_x = create_vector(10, 4);
	}
	if (keycode == 19)
	{
		(*map)->vector_x = create_vector(10, 0);
		(*map)->vector_y = create_vector(0, 10);
		(*map)->vector_z = create_vector(0, -5);
	}
}

int			key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		ft_close(map);
	}
	view(keycode, &map);
	if (keycode == 69)
		map->scale += 0.1;
	if (keycode == 78)
		map->scale -= 0.1;
	if (keycode == 75)
		map->vector_z.y += 0.2;
	if (keycode == 67)
		map->vector_z.y -= 0.2;
	map->color_n = get_color(keycode, &map);
	move_image(keycode, &map);
	create_image(&map);
	return (0);
}
