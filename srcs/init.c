/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:18:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/05 16:13:32 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/fdf.h"

t_point_3d     init_point(int x, int y, int z)
{
    t_point_3d     point;

    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

t_map		*init_map()
{
	t_map *map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->data = 0;
	map->grille = NULL;
	map->pointeur_image = NULL;
	map->mlx_ptr = mlx_init();
	map->new_point_win = new_point(WIDTH/4, LENGTH/4);
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, LENGTH, "window");
	map->scale = 2;
	return (map);
}

void	init_image(void *mlx_ptr, t_map **map)
{
    int     bpp;
    int     s_l;
    int     endian;

    (*map)->pointeur_image = mlx_new_image(mlx_ptr, WIDTH, LENGTH);
    (*map)->data =  (int *)mlx_get_data_addr((*map)->pointeur_image, &(bpp), &(s_l), &(endian));
}
