/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:10:30 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 21:45:03 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
