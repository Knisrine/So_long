/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_door_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:11:23 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 21:44:09 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
