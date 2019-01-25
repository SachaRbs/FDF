/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sarobber <sarobber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 14:22:21 by sarobber     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 18:05:56 by sarobber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     main(int ac, char **av)
{
    int         fd;
    t_map		*map;

	ac = 1;
    if ((fd = open(av[1], O_RDONLY)) == -1)
    {   
        write (1, "error\n", 6);
        return (0);
    }
	map = init_map();
	ft_create_map(av[1], map);
	init_image(map->mlx_ptr, &map);
    create_image(&map);
    mlx_loop(map->mlx_ptr);
    return (0);
}
