/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:55:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/02/28 20:47:18 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_caracters(char *s)
{
	while (*s)
	{
		if ((*s != '1' && *s != '0') && (*s != 'P' && *s != 'C') && *s != 'E')
			return (0);
		s++;
	}
	return (1);
}

int	check_player(char *s)
{
	static int	count;

	count = 0;
	while (*s)
	{
		if (*s == 'P')
			count++;
		if (count > 1 || count < 1)
			return (0);
		s++;
	}
	return (1);
}

int		check_wall(char *s)
{
	while(*s)
	{
		if(*s != '1')
			return(0);
		s++;
	}
	return (1);
}

static	void check_form(char **map, int height)
{
	int	j;
	int	i;
		
	i = 0;
	j = 1;
	while(i < height -1)
	{
		if(ft_strlen(map[i++]) !=  ft_strlen(map[j++]))
		{
			perror("Form Invalid !\n");
			exit (1);
		}
	}
}


void	valid_map(char *s)
{
	char	*lines;
	char	**map;
	int height;
	int	fd;
	int	i;
	
	height = 0;
	i = 0;
	map = NULL;

	////get height
	fd = open(s, O_RDONLY);
	lines = get_next_line(fd);
	while(lines)
	{
		height++;
		lines = get_next_line(fd);
	}
	close(fd);
	map = malloc(sizeof(char *) * (height + 1));
	/////set map to **p
	fd = open(s, O_RDONLY);
	lines = get_next_line(fd);
	while(lines)
	{
		map[i] = ft_strdup(lines);
		free(lines);
		lines = get_next_line(fd);
		i++;
	}
	map[i] = NULL;

	check_form(map, height);
	// printf("%d",height);
}
