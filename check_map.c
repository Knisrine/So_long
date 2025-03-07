/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:55:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/06 23:31:11 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_caracters(char *s)
{
	while (*s)
	{
		if ((*s != '1' && *s != '0') && (*s != 'P' && *s != 'C') && *s != 'E')
			return (0);
		s++;
	}
	return (1);
}

int		trans(char *s)
{
	while(*s)
	{
		if( *s != '1' && *s != '0')
			return (0);
		s++;
	}
	return (1);
}




static void	flood_fill(char **map, int x, int y, var *v)
{
	v->width = ft_strlen(map[0]);
	if(x < 0 || y < 0 || x >= v->width || y >= v->height)
		return;
	if(map[y][x] == wall)
		return;
	map[y][x]= wall;
	flood_fill(map, x, y - 1, v);
	flood_fill(map, x + 1, y, v);
	flood_fill(map, x, y + 1, v);
	flood_fill(map, x - 1, y, v);
}

void	player_pos(char **map, int height, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	while(j < height)
	{
		i = 0;
		while(i < ft_strlen(map[j]))
		{
			if(map[j][i] == 'P')
			{
				*x = i;
				*y = j;
				return;
			}
			i++;
		}
		j++;
	}
}



char	**valid_map(char *s)
{
	char	*lines;
	char	**map;
	var		v;
	int		fd = 0;
	int		i;
	int		x;
	int		y;

	map = NULL;
	lines = NULL;
	v.height = 0;
	i = 0;
	////get height
	v.height = len_map(s, v);
	close(fd);
	/////
	map = malloc(sizeof(char *) * (v.height + 1));
	if(!map)
		exit(1);
	/////set map to **p
	fd = open(s, O_RDONLY);
	lines = get_next_line(fd);
	while (lines)
	{
		if (!check_caracters(lines))
		{
			//(free)
			perror("Error !");
			exit(1);
		}
		map[i] = ft_strdup(lines);
		free(lines);
		lines = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	is_rectangl(map, v.height, &v);

	char **new_map = malloc(sizeof (char *) * (v.height + 1));
	if(!new_map)
		exit(1);
	i = 0;
	while(i < v.height)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	player_pos(new_map, v.height, &x, &y);
	flood_fill(new_map, x, y, &v);
	
	i = 0;
	while(i < v.height)
	{
		if(!trans(new_map[i]))
		{
			free_maps(map, new_map);
			printf("Incomplet Game !\n");
			exit (1) ;
		}
		i++;
	}
	
	return (map);
}
