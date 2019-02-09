/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:18:20 by sarobber          #+#    #+#             */
/*   Updated: 2019/02/09 14:52:42 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				ft_count_words_sep(char const *s, char c)
{
	int	count;
	int	sep;

	sep = 0;
	count = 0;
	while (*s != '\0')
	{
		if (sep == 1 && *s == c)
			sep = 0;
		if (sep == 0 && *s != c)
		{
			sep = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int				**ft_tabnew_two(size_t x, size_t y)
{
	size_t	i;
	int		**tab;
	int		*tab2;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(tab) * y)))
		return (NULL);
	if (!(tab2 = (int*)malloc(sizeof(tab2) * (x * y))))
		return (NULL);
	while (i < y)
	{
		tab[i] = &tab2[i * x];
		i++;
	}
	return (tab);
}

int				ft_count(char *argv, t_map *map)
{
	char	*line;
	int		fd;

	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	get_next_line(fd, &line);
	map->len_y++;
	map->len_x = ft_count_words_sep(line, ' ');
	if (line)
		free(line);
	while (get_next_line(fd, &line))
	{
		map->len_y++;
		free(line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

t_map			*ft_fill_map(int fd, t_map *map)
{
	char	*line;
	char	**split_line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(map->grille = ft_tabnew_two(map->len_x, map->len_y)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		x = 0;
		split_line = ft_strsplit(line, ' ');
		while (split_line[x] != NULL)
		{
			map->grille[y][x] = ft_atoi(split_line[x]);
			free(split_line[x]);
			x++;
		}
		free(split_line);
		free(line);
		y++;
	}
	return (map);
}

int				ft_create_map(char *argv, t_map *map)
{
	int		fd;

	ft_count(argv, map);
	fd = (open(argv, O_RDONLY));
	if (fd == -1)
		return (-1);
	map = ft_fill_map(fd, map);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}
