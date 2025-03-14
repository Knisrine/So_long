/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:28:44 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/14 18:40:59 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, var *v)
{
	v->width = ft_strlen(map[0]);
	if (x < 0 || y < 0 || x >= v->width || y >= v->height)
		return ;
	if (map[y][x] == WALL)
		return ;
	map[y][x] = WALL;
	flood_fill(map, x, y - 1, v);
	flood_fill(map, x + 1, y, v);
	flood_fill(map, x, y + 1, v);
	flood_fill(map, x - 1, y, v);
}
