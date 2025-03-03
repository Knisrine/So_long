/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:55:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/03 20:35:57 by nikhtib          ###   ########.fr       */
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

static int	check_player(char *s)
{
	static int	count;

	while (*s)
	{
		if (*s == 'P')
			count++;
		s++;
	}
	return (count);
}

static int	check_exit_door(char *s)
{
	static int	count;

	while (*s)
	{
		if (*s == 'E')
			count++;
		s++;
	}
	return (count);
}

int	is_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != wall)
			return (0);
		i++;
	}
	return (1);
}

static int	check_collct(char *s)
{
	static int	count;

	while (*s)
	{
		if (*s == 'C')
			count++;
		s++;
	}
	return (count);
}

static	void check_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((!is_wall(map[0]) || !is_wall(map[height - 1])) || ((i > 0
			&& i < height - 1) && (map[i][0] != wall || map[i][width
			- 1] != wall)))
		{
			/// free
			write(2, "Invalid Map !!\n", 15);
			exit(1);
		}
		i++;
	}
}

static void	flood_fill(char **map, int x, int y, var *v)
{
	v->width = ft_strlen(map[0]);
	if(x < 0 || y < 0 || x >= v->width || y >= v->height)
		return;
	if(map[y][x] == wall)
		return;
	if(map[y][x] == 'C')
		v->collct--;
	if(map[y][x] == 'E')
		v->exit_door--;
	if(map[y][x] == 'P')
		v->player--;
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
static	void if_conditions(var v)
{
	if ((v.player > 1 || v.player < 1))
	{
		printf(" One player Required !\n");
		exit(1);
	}
	if (v.exit_door > 1 || v.exit_door < 1)
	{
		printf(" One Exit_Door Required !\n");
		exit(1);
	}
	if (v.collct < 1)
	{
		printf(" Atlsst one collct!\n");
		exit(1);
	}
}

static void	is_rectangl(char **map, int height, var *v)
{

	int i;
	int j;

	i = 0;
	j = 1;
	while (i < height - 1)
	{
		if (ft_strlen(map[i++]) != ft_strlen(map[j++]))
		{
			printf("Form Invalid !\n");
			exit(1);
		}
		check_walls(map, height, ft_strlen(*map));
		v->player = check_player(map[i]);
		v->exit_door = check_exit_door(map[i]);
		v->collct = check_collct(map[i]);
	}
	if_conditions(*v);

	}

void	valid_map(char *s)
{
	char	*lines;
	char	**map;
	var		v;
	int		fd;
	int		i;
	int		x;
	int		y;

	map = NULL;
	lines = NULL;
	v.height = 0;
	i = 0;
	////get height
	fd = open(s, O_RDONLY);
	while ((lines = get_next_line(fd)))
		v.height++;
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
	player_pos(map, v.height, &x, &y);
	flood_fill(map, x, y, &v);
	
	if(v.player != 0 || v.collct != 0 || v.exit_door != 0)
	{
		///free
		printf("Incomplet Game !\n");
		exit(1);
	}
	// flood_fill(map,)
}
