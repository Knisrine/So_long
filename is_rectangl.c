/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:34:01 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/06 15:37:20 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		printf(" at least one collct !\n");
		exit(1);
	}
}

int	is_rectangl(char **map, int height, var *v)
{

	int i;
	int j;

	i = 0;
	j = 1;
	while (i < height - 1)
	{
		if (ft_strlen(map[i++]) != ft_strlen(map[j++]))
		{
			perror("Form Invalid !\n");
			exit(1);
		}
		check_walls(map, height, ft_strlen(*map));
		v->player = check_player(map[i]);
		v->exit_door = check_exit_door(map[i]);
		v->collct = check_collct(map[i]);
	}
	if_conditions(*v);
	
	return (ft_strlen(map[0]));
	}