/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:09:20 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/14 18:35:59 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_the_walls(var *v)
{
	mlx_image_to_window(v->ptr, v->put_wall, (v->x * 32), (v->y * 32));
	if (!v->put_wall)
	{
		printf("failed to open file\n");
		exit(1);
	}
}

static void	set_the_collct(var *v)
{
	mlx_image_to_window(v->ptr, v->put_col, (v->x * 32), (v->y * 32));
	if (!v->put_floor)
	{
		printf("failed to open file");
		exit(1);
	}
}

static void	set_the_dor(var *v)
{
	mlx_image_to_window(v->ptr, v->put_door, (v->x * 32), (v->y * 32));
	if (!v->put_door)
	{
		printf("failed to open file");
		exit(1);
	}
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
