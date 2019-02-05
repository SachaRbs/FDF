/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:38:51 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/05 17:12:55 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

#include "../minilibx_macos/mlx.h"
#include "../libft/get_next_line.h"
#include "../libft/libft.h"
#define WIDTH 1000
#define LENGTH 1000
#define ABS(x) ((x < 0) ? -x : x)

typedef struct      s_point_3d
{
    int             x;
    int             y;
    int             z;
}                   t_point_3d;

typedef struct		s_point_2d
{
	float 	x;
	float 	y;
	int		color;
}					t_point_2d;

typedef struct 		s_vector
{
	float x;
	float y;
}					t_vector;

typedef struct		s_map
{
	void*       		pointeur_image;
    int*    	    	data;
	int					**grille;
	t_vector			vector_x;
	t_vector			vector_y;
	t_vector			vector_z;
	t_point_2d 			new_point_win;
	void				*mlx_ptr;
	void				*win_ptr;
	float				scale;
	int					len_x;
	int					len_y;
	int					x;
	int					y;

}					t_map;

int				ft_create_map(char *argv, t_map *map);
void			create_image(t_map **map);
t_point_2d		new_point(int x, int y);
t_point_3d     	init_point(int x, int y, int z);
t_map			*init_map();
t_vector		create_vector(float x, float y);
void			init_image(void *mlx_ptr, t_map **map);
int 			key_press(int keycode, void *param);
int				key_hook(int keycode, t_map *map);
int 			get_color(t_point_2d current, t_point_2d start, t_point_2d end);
#endif