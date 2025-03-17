/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:28:44 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/17 00:37:30 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int x, int y, var *v)
{
	// printf("a/n");
	v->width = ft_strlen(v->map[0]);
	if (x < 0 || y < 0 || x >= v->width || y >= v->height)
		return ;
	if (v->new_map[y][x] == WALL)
		return ;
	v->new_map[y][x] = WALL;
	flood_fill(x, y - 1, v);
	flood_fill(x + 1, y, v);
	flood_fill(x, y + 1, v);
	flood_fill(x - 1, y, v);
}
