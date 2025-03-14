/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:59:56 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/14 17:47:15 by nikhtib          ###   ########.fr       */
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

static void	load_textures_p2(var *v)
{
	v->col_texture = mlx_load_png("./textures/coll.png");
	if (!v->col_texture)
		texture_error(v);
	v->put_col = mlx_texture_to_image(v->ptr, v->col_texture);
	if (!v->put_col)
		texture_error(v);
	v->door_texture = mlx_load_png("./textures/door1.png");
	if (!v->door_texture)
		texture_error(v);
	v->put_door = mlx_texture_to_image(v->ptr, v->door_texture);
	if (!v->put_door)
		texture_error(v);
	v->ennemi_texture = mlx_load_png("./textures/ennemi.png");
	if (!v->ennemi_texture)
		texture_error(v);
}

static void	load_textures_p3(var *v)
{
	v->put_ennemi = mlx_texture_to_image(v->ptr, v->ennemi_texture);
	if (!v->put_ennemi)
		texture_error(v);
	v->plr_texture = mlx_load_png("./textures/player.png");
	if (!v->plr_texture)
		texture_error(v);
	v->put_plr = mlx_texture_to_image(v->ptr, v->plr_texture);
	if (!v->put_plr)
		texture_error(v);
}
static void	load_textures_p1(var *v)
{
	v->w_texture = mlx_load_png("./textures/wall.png");
	if (!v->w_texture)
		texture_error(v);
	v->put_wall = mlx_texture_to_image(v->ptr, v->w_texture);
	if (!v->put_wall)
		texture_error(v);
	v->f_texture = mlx_load_png("./textures/bckg.png");
	if (!v->f_texture)
		texture_error(v);
	v->put_floor = mlx_texture_to_image(v->ptr, v->f_texture);
	if (!v->put_floor)
		texture_error(v);
	load_textures_p2(v);
	load_textures_p3(v);
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
static void	set_the_ennemi(var *v)
{
	if (v->map[v->y][v->x] == ENNEMI)
	{
		mlx_image_to_window(v->ptr, v->put_ennemi, (v->x * 32), (v->y * 32));
		if (!v->put_ennemi)
		{
			printf("failed to open file");
			exit(1);
		}
	}
}

static void	count_items(var *v)
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
static void	set_items(var *v)
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
			if (v->map[v->y][v->x] == ENNEMI)
				set_the_ennemi(v);
			v->x++;
		}
		v->y++;
	}
}
int	main(int ac, char **av)
{
	var	v;

	v.height = 0;
	if (ac == 2)
	{
		check_ext(av[1]);
		v.map = valid_map(av[1]);
		v.height = len_map(av[1], v);
		v.width = ft_strlen(v.map[0]);
		count_items(&v);
		v.ptr = mlx_init(TILE_SIZE * v.width, TILE_SIZE * v.height, "Window",
				false);
		if (!v.ptr)
			return (1);
		load_textures_p1(&v);
		set_the_floor(&v);
		set_items(&v);
		put_player(&v);
		player_pos(v.map, v.height, &v.y, &v.x);
		ex_door_pos(v.map, v.height, &v.i, &v.j);
		mlx_key_hook(v.ptr, my_hook, &v);
		mlx_loop(v.ptr);
	}
	free_map(v.map);
}
