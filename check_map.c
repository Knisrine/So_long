/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:55:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 21:43:19 by nikhtib          ###   ########.fr       */
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

void	part2(var *v, char *s)
{
	char	*lines;
	int		i;

	lines = NULL;
	i = 0;
	v->fd = open(s, O_RDONLY);
	lines = get_next_line(v->fd);
	while (lines)
	{
		if (!check_caracters(lines))
		{
			free_map(v->map);
			write(2, "Error !\n", 8);
			exit(1);
		}
		v->map[i] = ft_strdup(lines);
		free(lines);
		lines = get_next_line(v->fd);
		i++;
	}
	close(v->fd);
	v->map[i] = NULL;
}

void	part3(var *v)
{
	int	i;

	i = 0;
	v->height = 0;
	while (i < v->height)
	{
		v->new_map[i] = ft_strdup(v->map[i]);
		i++;
	}
	v->new_map[i] = NULL;
	player_pos(v->new_map, v->height, &v->x, &v->y);
	flood_fill(v->new_map, v->x, v->y, v);
	i = 0;
	while (i < v->height)
	{
		if (!trans(v->new_map[i]))
		{
			free_maps(v->map, v->new_map);
			write(2, "Incomplet Game !\n", 17);
			exit(1);
		}
		i++;
	}
}

char	**valid_map(char *s, var v)
{
	int	i;

	i = 0;
	v.height = len_map(s, v);
	v.map = malloc(sizeof(char *) * (v.height + 1));
	if (!v.map)
		exit(1);
	part2(&v, s);
	is_rectangl(v.map, v.height, &v);
	v.new_map = malloc(sizeof(char *) * (v.height + 1));
	if (!v.new_map)
		exit(1);
	part3(&v);
	free_map(v.new_map);
	free(v.new_map);
	return (v.map);
}
