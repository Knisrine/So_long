/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:59:56 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/17 02:04:56 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(var *v)
{
	v->y = 0;
	while (v->y < v->height)
	{
		v->x = 0;
		while (v->x < v->width)
		{
			if (v->map[v->y][v->x] == PLR)
			{
				mlx_image_to_window(v->ptr, v->put_floor, (v->x * 32), (v->y
						* 32));
				if (!v->put_floor)
					image_error(v);
				mlx_image_to_window(v->ptr, v->put_plr, (v->x * 32), (v->y
						* 32));
				if (!v->put_plr)
					image_error(v);
			}
			v->x++;
		}
		v->y++;
	}
}

void	set_the_floor(var *v)
{
	v->y = 0;
	while (v->y < v->height)
	{
		v->x = 0;
		while (v->x < v->width)
		{
			mlx_image_to_window(v->ptr, v->put_floor, (v->x * 32), (v->y * 32));
			if (!v->put_floor)
			{
				printf("failed to set floor");
				free_map(v->map);
				exit(1);
			}
			v->x++;
		}
		v->y++;
	}
}

void ff()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	atexit(ff);
	var	v;

	v.height = 0;
	if (ac == 2)
	{
		v.count_move = 0;
		check_ext(av[1]);
		v.map = valid_map(av[1], v);
		v.height = len_map(av[1], v);
		v.width = ft_strlen(v.map[0]);
		count_items(&v);
		v.ptr = mlx_init(TILE_SIZE * v.width, TILE_SIZE * v.height, "Window",
				false);
		if (!v.ptr)
			return (1);
		load_textures(&v);
		set_the_floor(&v);
		set_items(&v);
		put_player(&v);
		player_pos(v.map, v.height, &v.y, &v.x);
		ex_door_pos(v.map, v.height, &v.i, &v.j);
		mlx_key_hook(v.ptr, my_hook, &v);
		mlx_loop(v.ptr);
		free_map(v.map);
		// free(v.map);
		// LEAKS 
	}
}
