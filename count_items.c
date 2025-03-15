/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:14:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 19:14:28 by nikhtib          ###   ########.fr       */
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

static void	if_conditions(var *v)
{
	if ((v->player > 1 || v->player < 1))
	{
		write(2, " One player Required !\n", 24);
		free_map(v->map);
		exit(1);
	}
	if (v->exit_door > 1 || v->exit_door < 1)
	{
		write(2, " One Exit_Door Required !\n", 27);
		free_map(v->map);
		exit(1);
	}
	if (v->collct < 1)
	{
		write(2, " At least one collct !\n", 24);
		free_map(v->map);
		exit(1);
	}
}

void	count_items(var *v)
{
	int	i;

	i = 0;
	while (i < v->height - 1)
	{
		v->player = check_player(v->map[i]);
		v->exit_door = check_exit_door(v->map[i]);
		v->collct = check_collct(v->map[i]);
		i++;
	}
	if_conditions(v);
}
