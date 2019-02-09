/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:56:29 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/09 15:02:57 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int		convert_color(t_color *color)
{
	unsigned int	ret;

	ret = (color->r << 16) + (color->g << 8) + color->b;
	return (ret);
}

unsigned int		get_color(int keycode, t_map **map)
{
	if (keycode == 86)
		if ((*map)->color_s->r + 10 <= 255)
			(*map)->color_s->r += 10;
	if (keycode == 83)
		if ((*map)->color_s->r - 10 >= 0)
			(*map)->color_s->r -= 10;
	if (keycode == 87)
		if ((*map)->color_s->g + 10 <= 255)
			(*map)->color_s->g += 10;
	if (keycode == 84)
		if ((*map)->color_s->g - 10 >= 0)
			(*map)->color_s->g -= 10;
	if (keycode == 88)
		if ((*map)->color_s->b + 10 <= 255)
			(*map)->color_s->b += 10;
	if (keycode == 85)
		if ((*map)->color_s->b - 10 >= 0)
			(*map)->color_s->b -= 10;
	return (convert_color((*map)->color_s));
}
