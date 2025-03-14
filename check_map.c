/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:55:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/14 22:10:54 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_caracters(char *s)
{
	while (*s)
	{
		if ((*s != '1' && *s != '0') && (*s != 'P' && *s != 'C') && (*s != 'E'
				&& *s != 'e'))
			return (0);
		s++;
	}
	return (1);
}

int	trans(char *s)
{
	while (*s)
	{
		if (*s != '1' && *s != '0')
			return (0);
		s++;
	}
	return (1);
}

void	player_pos(char **map, int height, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < ft_strlen(map[j]))
		{
			if (map[j][i] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	ex_door_pos(char **map, int height, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < ft_strlen(map[j]))
		{
			if (map[j][i] == 'E')
			{
				*x = i;
				*y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

char	**valid_map(char *s)
{
	char	*lines;
	// char	**map;
	var		v;
	int		fd;
	int		i;
	int		x;
	int		y;
	char	**new_map;

	fd = 0;
	v.map = NULL;
	lines = NULL;
	v.height = 0;
	i = 0;
	v.height = len_map(s, v);
	printf("len map ---> %d\n", v.height);
	close(fd);
	v.map = malloc(sizeof(char *) * (v.height + 1));
	if (!v.map)
		exit(1);
	fd = open(s, O_RDONLY);

	lines = get_next_line(fd);
	while (lines)
	{
		if (!check_caracters(lines))
		{
			free_map(v.map);
			printf("Error !");
			exit(1);
		}
		v.map[i] = ft_strdup(lines);
		free(lines);
		lines = get_next_line(fd);
		i++;
	}

	v.map[i] = NULL;
	is_rectangl(v.map, v.height, &v);
	new_map = malloc(sizeof(char *) * (v.height + 1));
	if (!new_map)
		exit(1);
	i = 0;

	while (i < v.height)
	{
		new_map[i] = ft_strdup(v.map[i]);
		i++;
	}
	new_map[i] = NULL;
	player_pos(new_map, v.height, &x, &y);
	flood_fill(new_map, x, y, &v);

	i = 0;
	while (i < v.height)
	{
		if (!trans(new_map[i]))
		{
			free_maps(v.map, new_map);
			printf("Incomplet Game !\n");
			exit(1);
		}
		i++;
	}

	free_map(new_map);
	free(new_map);
	return (v.map);
}
