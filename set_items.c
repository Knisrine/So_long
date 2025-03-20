/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:09:20 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/20 14:47:31 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_the_walls(var *v)
{
	mlx_image_to_window(v->ptr, v->put_wall, (v->x * 32), (v->y * 32));
	if (!v->put_wall)
		image_error(v);
}

static void	set_the_collct(var *v)
{
	mlx_image_to_window(v->ptr, v->put_col, (v->x * 32), (v->y * 32));
	if (!v->put_floor)
		image_error(v);
}

static void	set_the_dor(var *v)
{
	mlx_image_to_window(v->ptr, v->put_door, (v->x * 32), (v->y * 32));
	if (!v->put_door)
		image_error(v);
}

void	set_items(var *v)
{
	v->y = 0;
	while (v->y < v->height)
	{
		v->x = 0;
		while (v->x < v->width)
		{
			if (v->map[v->y][v->x] == WALL)
				set_the_walls(v);
			if (v->map[v->y][v->x] == COLL)
				set_the_collct(v);
			if (v->map[v->y][v->x] == EX_DR)
				set_the_dor(v);
			v->x++;
		}
		v->y++;
	}
}
