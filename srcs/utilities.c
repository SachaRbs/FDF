/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 14:01:39 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 13:50:42 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	create_vector(float x, float y)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_point_2d		new_point(int x, int y)
{
	t_point_2d point;

	point.x = x;
	point.y = y;
	return (point);
}