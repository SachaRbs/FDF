/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_image.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 13:36:34 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 18:05:57 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	new_pos(t_point_2d *pos, t_point_2d point1, t_point_2d step, int index)
{
	pos->x = point1.x + index * step.x;
	pos->y = point1.y + index * step.y;
}

static void		get_step(t_point_2d p1, t_point_2d p2, t_point_2d *step)
{
	step->x = p2.x - p1.x;
	step->y = p2.y - p1.y;
}

void	drawline(t_point_2d point1, t_point_2d point2, t_map **map)
{
	t_point_2d	tmp;
	t_point_2d	step;
	t_point_2d	pos;
	int 		k;
	int 		index ;

	index = 0;
	get_step(point1, point2, &step);
	tmp = new_point(ABS(step.x), ABS(step.y));
    if (tmp.x > tmp.y)
    {
        k = ABS(step.x);
        step.y /= ABS(step.x);
        step.x /= ABS(step.x);
    }
    else
    {
        k = ABS(step.y);
        step.x /= ABS(step.y);
        step.y /= ABS(step.y);
	}
	while (index < k)
	{
		new_pos(&pos, point1, step, index);
		if ((pos.x >= 0 && pos.x <= WIDTH) && (pos.y >= 0 && pos.y <= LENGTH))
			(*map)->data[(int)pos.y * LENGTH + (int)pos.x] = 0XFFFFFF;
		index++;
	}
}

void create_image(t_map **map)
{
	t_point_2d proj;
	t_point_2d proj_1;
	t_point_3d index;
	t_point_3d index_1;

	proj = new_point(0, 0);
	proj_1 = new_point(0, 0);
	index = init_point(0, 0, 0);
	index_1 = init_point(0, 0, 0);
	while (index.y < (*map)->len_y)
	{
		index.x = 0;
		while (index.x < (*map)->len_x)
		{
			index.z = (*map)->grille[index.y][index.x];
			proj.x = ((index.x * (*map)->vector_x.x * (*map)->scale) + (index.y * (*map)->vector_y.x * (*map)->scale) + (index.z * (*map)->vector_z.x * (*map)->scale)) + (*map)->new_point_win.x;
			proj.y = ((index.x * (*map)->vector_x.y * (*map)->scale) + (index.y * (*map)->vector_y.y * (*map)->scale) + (index.z * (*map)->vector_z.y * (*map)->scale)) + (*map)->new_point_win.y;
			if ((index.x + 1) < (*map)->len_x)
			{
				index_1 = init_point(index.x + 1, index.y, (*map)->grille[index.y][index.x + 1]);
				proj_1.x = ((index_1.x * (*map)->vector_x.x * (*map)->scale) + (index_1.y * (*map)->vector_y.x * (*map)->scale) + (index_1.z * (*map)->vector_z.x * (*map)->scale)) + (*map)->new_point_win.x;
				proj_1.y = ((index_1.x * (*map)->vector_x.y * (*map)->scale) + (index_1.y * (*map)->vector_y.y * (*map)->scale) + (index_1.z * (*map)->vector_z.y * (*map)->scale)) + (*map)->new_point_win.y;
				//mlx_pixel_put((*map)->mlx_ptr, (*map)->win_ptr, proj_1.x, proj_1.y, 0xFFFFFF);
				drawline(proj, proj_1, &(*map));
			}

			if ((index.y + 1) < (*map)->len_y)
			{
				index_1 = init_point(index.x, index.y + 1, (*map)->grille[index.y + 1][index.x]);
				proj_1.x = ((index_1.x * (*map)->vector_x.x * (*map)->scale) + (index_1.y * (*map)->vector_y.x * (*map)->scale) + (index_1.z * (*map)->vector_z.x * (*map)->scale)) + (*map)->new_point_win.x;
				proj_1.y = ((index_1.x * (*map)->vector_x.y * (*map)->scale) + (index_1.y * (*map)->vector_y.y * (*map)->scale) + (index_1.z * (*map)->vector_z.y * (*map)->scale)) + (*map)->new_point_win.y;
				drawline(proj, proj_1, &(*map));
				//mlx_pixel_put((*map)->mlx_ptr, (*map)->win_ptr, proj_1.x, proj_1.y, 0xFFFFFF);
			}
			index.x++;
		}
		index.y++;
	}
	mlx_put_image_to_window((*map)->mlx_ptr, (*map)->win_ptr, (*map)->pointeur_image, 0, 0);
}