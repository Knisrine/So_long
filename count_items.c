/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:14:41 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 15:39:52 by nikhtib          ###   ########.fr       */
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
		printf(" One player Required !\n");
		free_map(v->map);
		exit(1);
	}
	if (v->exit_door > 1 || v->exit_door < 1)
	{
		printf(" One Exit_Door Required !\n");
		free_map(v->map);
		exit(1);
	}
	if (v->collct < 1)
	{
		printf(" At least one collct !\n");
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
