/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:55:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/02 21:58:31 by nikhtib          ###   ########.fr       */
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
		if (*s == 'P')
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

static void	flood_fill(char **map, int x, int y)
{
	int	height;
	int	width;

	width = ft_strlen(map[0]);
	height = y;
	if(x < 0 || y < 0 || x >= width || y >= height)
		return;
	if(map[x][y] != wall)
		map[x][y] = wall;
	
	flood_fill(map, x, y - 1);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x - 1, y);
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
static	void if_conditions(int player, int exit_door, int collct)
{
	if ((player > 1 || player < 1))
	{
		perror(" One player Required !\n");
		exit(1);
	}
	if (exit_door > 1 || exit_door < 1)
	{
		perror(" One Door Required !\n");
		exit(1);
	}
	if (collct < 1)
	{
		perror(" Atlsst one collct!\n");
		exit(1);
	}
}

static void	is_rectangl(char **map, int height)
{
	int	player;
	int	exit_door;
	int	collct;
	int i;
	int j;
	
	player = 0;
	exit_door = 0;
	collct = 0;
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
		player = check_player(map[i]);
		exit_door = check_exit_door(map[i]);
		collct = check_collct(map[i]);
	}
	if_conditions(player, exit_door, collct);
	}

void	valid_map(char *s)
{
	char	*lines;
	char	**map;
	int		height;
	int		fd;
	int		i;
	int	x;
	int	y;

	map = NULL;
	lines = NULL;
	height = 0;
	i = 0;
	////get height
	fd = open(s, O_RDONLY);
	while ((lines = get_next_line(fd)))
		height++;
	close(fd);
	/////
	map = malloc(sizeof(char *) * (height + 1));
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
	is_rectangl(map, height);
	player_pos(map, height, &x, &y);
	x = 0;
	y = height;
	flood_fill(map, x, y);
	// flood_fill(map,)
	// printf("%d",height);
}
