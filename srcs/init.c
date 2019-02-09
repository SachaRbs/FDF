/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:18:05 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/09 14:51:13 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point_3d			init_point(int x, int y, int z)
{
	t_point_3d		point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_map				*init_map(char *name)
{
	t_map			*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->data = 0;
	map->grille = NULL;
	map->pointeur_image = NULL;
	map->mlx_ptr = mlx_init();
	map->new_point_win = new_point(WIDTH / 3, LENGTH / 3);
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, LENGTH,
	ft_strsub(ft_strrchr(name, '/'), 1, ft_strlen(ft_strrchr(name, '/')) - 5));
	map->scale = 2;
	map->vector_y = create_vector(-10, 4);
	map->vector_z = create_vector(0, -5.8);
	map->vector_x = create_vector(10, 4);
	map->color_s = init_color();
	map->color_n = convert_color(map->color_s);
	return (map);
}

void				init_image(void *mlx_ptr, t_map **map)
{
	int				bpp;
	int				s_l;
	int				endian;

	(*map)->pointeur_image = mlx_new_image(mlx_ptr, WIDTH, LENGTH);
	(*map)->data = (int *)mlx_get_data_addr((*map)->pointeur_image,
	&(bpp), &(s_l), &(endian));
}

t_color				*init_color(void)
{
	t_color			*color;

	if (!(color = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	color->r = 250;
	color->g = 250;
	color->b = 250;
	return (color);
}
