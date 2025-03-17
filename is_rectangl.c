/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:34:01 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/16 23:30:51 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static void	check_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((!is_wall(map[0]) || !is_wall(map[height - 1])) || ((i > 0
					&& i < height - 1) && (map[i][0] != WALL || map[i][width
				- 1] != WALL)))
		{
			free(map);
			write(2, "Invalid Map !!\n", 15);
			exit(1);
		}
		i++;
	}
}

int	is_rectangl(char **map, int height, var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	(void)v;
	while (i < height - 1)
	{
		if (ft_strlen(map[i++]) != ft_strlen(map[j++]))
		{
			// WAAA FREEEEEEEEE
			free(v->map);
			write (1,"Form Invalid !\n", 14);
			exit(1);
		}
		check_walls(map, height, ft_strlen(*map));
	}
	return (ft_strlen(map[0]));
}
