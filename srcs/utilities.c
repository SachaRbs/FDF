/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:18:25 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/05 14:10:08 by sarobber         ###   ########.fr       */
/*                                                                            */
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