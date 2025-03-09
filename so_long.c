/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:59:56 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/09 02:49:39 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void my_hook(mlx_key_data_t keydata, void* param)
{
	var* v = (var *) param;
	static int count_move;

		// printf("---> %d\n", v->y);
	if(keydata.key == MLX_KEY_W && keydata.action)
	{
		v->put_plr->instances->y -= 32 ;
		count_move++;
	}
	else if(keydata.key == MLX_KEY_S && keydata.action != MLX_PRESS)
	{
		// printf("hna \n");
		printf("---> %d\n", v->put_plr->instances->y);
		v->put_plr->instances->y += 32 ;
		count_move++;
	}
	else if(keydata.key == MLX_KEY_A && keydata.action != MLX_PRESS)
	{
		v->put_plr->instances->x -= 32 ;
		count_move++;
	}
	else if(keydata.key == MLX_KEY_D && keydata.action != MLX_PRESS)
	{
		v->put_plr->instances->x += 32 ;
		count_move++;
	}
}

int	main(int ac, char **av)
{
	var v;
	v.height = 0;
	char **map;
	if (ac == 2)
	{
		check_ext(av[1]);
		map = valid_map(av[1]);
	
	v.height = len_map(av[1], v);
	v.width =ft_strlen(map[0]);

	
	v.ptr = mlx_init(830,350, "Window", false);
	if(!v.ptr)
		return(1);
	mlx_texture_t* w_texture = mlx_load_png("./textures/wall.png");
	if(!w_texture)
		exit(1);
    mlx_image_t* put_wall = mlx_texture_to_image(v.ptr ,w_texture);
	if(!put_wall)
	{
		printf("5eeerrr");
		exit(1);
	}
	mlx_texture_t* f_texture = mlx_load_png("./textures/bckg.png");
	if(!f_texture)
		exit(1);
    mlx_image_t* put_floor = mlx_texture_to_image(v.ptr ,f_texture);
	if(!put_floor)
	{
		printf("4eeerrr");
		exit(1);
	}
	mlx_texture_t* col_texture = mlx_load_png("./textures/coll.png");
	if(!col_texture)
		exit(1);
    mlx_image_t* put_col = mlx_texture_to_image(v.ptr ,col_texture);
	if(!put_col)
	{
		printf("3eeerrr");
		exit(1);
	}
	mlx_texture_t* door_texture = mlx_load_png("./textures/door1.png");
	if(!door_texture)
		exit(1);
    mlx_image_t* put_door = mlx_texture_to_image(v.ptr ,door_texture);
	if(!put_door)
	{
		printf("2eeerrr");
		exit(1);
	}
	mlx_texture_t* ennemi_texture = mlx_load_png("./textures/ennemi.png");
	if(!ennemi_texture)
		exit(1);
    mlx_image_t* put_ennemi = mlx_texture_to_image(v.ptr ,ennemi_texture);
	if(!put_ennemi)
	{
		printf("1eeerrr");
		exit(1);
	}
	mlx_texture_t* plr_texture = mlx_load_png("./textures/player.png");
	if(!plr_texture)
		exit(1);
    v.put_plr = mlx_texture_to_image(v.ptr ,plr_texture);
	if(!v.put_plr)
	{
		printf("0eeerrr");
		exit(1);
	}
	v.y = 0;
	while(v.y < v.height)
	{
		v.x = 0;
        while (v.x < v.width)
        {
			if(map[v.y][v.x] == floor)
			{
				mlx_image_to_window(v.ptr,put_floor, (v.x *32), (v.y * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			v.x++;
		}
		v.y++;
	}
	v.y = 0;
	while(v.y < v.height)
    {
		v.x = 0;
        while (v.x < v.width)
        {
			if(map[v.y][v.x] == wall)
			{
				mlx_image_to_window(v.ptr,put_floor, (v.x *32), (v.y * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,put_wall, (v.x *32), (v.y * 32));
				if(!put_wall)
				{
					printf("failed to open file\n");
					exit(1);
				}
			}
			if(map[v.y][v.x] == coll)
			{
				mlx_image_to_window(v.ptr,put_floor, (v.x *32), (v.y * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,put_col, (v.x *32), (v.y * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			if(map[v.y][v.x] == ex_dr)
			{
				mlx_image_to_window(v.ptr,put_floor, (v.x *32), (v.y * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,put_door, (v.x *32), (v.y * 32));
				if(!put_door)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			if(map[v.y][v.x] == ennemi)
			{
				mlx_image_to_window(v.ptr,put_floor, (v.x *32), (v.y * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,put_ennemi, (v.x *32), (v.y * 32));
				if(!put_ennemi)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			
			v.x++;
		}
		v.y++;
	}

	v.y = 0;
	while(v.y < v.height)
	{
		v.x = 0;
        while (v.x < v.width)
        {
			if(map[v.y][v.x] == plr)
			{
				mlx_image_to_window(v.ptr,put_floor, (v.x *32), (v.y * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,v.put_plr, (v.x *32), (v.y * 32));
				if(!v.put_plr)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			v.x++;
		}
		v.y++;
	}
	
		// move_player(map, i, j);
		// mlx_key_data_t data;
		player_pos(map, v.height, &v.y, &v.x);
		mlx_key_hook(v.ptr, my_hook, &v);
		mlx_loop(v.ptr);
	}
	// system("leaks so_long");
}