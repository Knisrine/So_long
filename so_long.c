/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:59:56 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/12 21:30:40 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void move_right(var *v)
{
	v->put_plr->instances->x += 32 ;
		v->y += 1;
}
static	void move_down(var *v)
{
	v->put_plr->instances->y += 32;
		v->x += 1;
}
static	void move_up(var *v)
{
	v->put_plr->instances->y -= 32;
		v->x -= 1;
		
}
static	void move_left(var *v)
{
	v->put_plr->instances->x -= 32 ;
	v->y -= 1;
}
static	void	press_w(var *v)
{
	if(v->map[v->x - 1][v->y] != wall)
	{
		if(v->map[v->x - 1][v->y] == coll)
		{
			move_up(v);
			mlx_image_to_window(v->ptr, v->put_floor, (v->y *32), (v->x * 32));
			v->map[v->x][v->y] = floor;
			mlx_delete_image(v->ptr, v->put_plr);
			v->put_plr = mlx_texture_to_image(v->ptr , v->plr_texture);
			if(!v->put_plr)
			{
				printf("0eeerrr");
				exit(1);
			}
			mlx_image_to_window(v->ptr, v->put_plr, (v->y *32), (v->x * 32));
			v->collct--;
		}
		else
			move_up(v);
	}	
}

static	void press_s(var *v)
{
	if(v->map[v->x +1][v->y] != wall)
	{
		if(v->map[v->x + 1][v->y] == coll)
		{
			move_down(v);
			mlx_image_to_window(v->ptr, v->put_floor, (v->y *32), (v->x * 32));
			v->map[v->x][v->y] = floor;
			mlx_delete_image(v->ptr, v->put_plr);
			v->put_plr = mlx_texture_to_image(v->ptr , v->plr_texture);
			if(!v->put_plr)
			{
				//free
				printf("0eeerrr");
				exit(1);
			}
				mlx_image_to_window(v->ptr, v->put_plr, (v->y *32), (v->x * 32));
			v->collct--;
		}
		else
			move_down(v);
		if(v->collct == 0 && (v->x == v->i) &&(v->y == v->j))
			mlx_delete_image(v->ptr, v->put_plr);
	}
}
static	void press_a(var *v)
{
	if(v->map[v->x][v->y - 1] != wall)
		{
			if(v->map[v->x][v->y - 1] == coll)
			{
				move_left(v);
				mlx_image_to_window(v->ptr, v->put_floor, (v->y *32), (v->x * 32));
				v->map[v->x][v->y] = floor;
				mlx_delete_image(v->ptr, v->put_plr);
				v->put_plr = mlx_texture_to_image(v->ptr , v->plr_texture);
				if(!v->put_plr)
				{
					//free
					printf("0eeerrr");
					exit(1);
				}
				mlx_image_to_window(v->ptr, v->put_plr, (v->y *32), (v->x * 32));
				v->collct--;
			}
			else
				move_left(v);
		}
}
static	void press_d(var *v)
{
	if(v->map[v->x][v->y + 1] != wall)
	{
		if(v->map[v->x][v->y + 1] == coll)
		{
			move_right(v);
			mlx_image_to_window(v->ptr, v->put_floor, (v->y *32), (v->x * 32));
			v->map[v->x][v->y] = floor;
			mlx_delete_image(v->ptr, v->put_plr);
			v->put_plr = mlx_texture_to_image(v->ptr , v->plr_texture);
			if(!v->put_plr)
			{
				//free
				printf("0eeerrr");
				exit(1);
			}
			mlx_image_to_window(v->ptr, v->put_plr, (v->y *32), (v->x * 32));
			v->collct--;
		}
		else
			move_right(v);
	}
}

void my_hook(mlx_key_data_t keydata, void* param)
{
	var* v = (var *) param;
	static int count_move;

	if(keydata.key == MLX_KEY_W && keydata.action)
	{
		press_w(v);
		count_move++;
	}
	else if(keydata.key == MLX_KEY_S && keydata.action != MLX_PRESS)
	{
		press_s(v);
		count_move++;
	}
	else if(keydata.key == MLX_KEY_A && keydata.action != MLX_PRESS)
	{
		press_a(v);
		count_move++;
	}
	else if(keydata.key == MLX_KEY_D && keydata.action != MLX_PRESS)
	{
		press_d(v);
		count_move++;
	}
}

void	put_player(var *v)
{
	v->y = 0;
	while(v->y < v->height)
	{
		v->x = 0;
        while (v->x < v->width)
        {
			if(v->map[v->y][v->x] == plr)
			{
				mlx_image_to_window(v->ptr, v->put_floor, (v->x *32), (v->y * 32));
				if(!v->put_floor)
				{
					printf("Error: failed to load floor");
					exit(1);
				}
				mlx_image_to_window(v->ptr,v->put_plr, (v->x *32), (v->y * 32));
				if(!v->put_plr)
				{
					printf("Error: failed to load player");
					exit(1);
				}
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
static	void if_conditions(var v)
{
	if ((v.player > 1 || v.player < 1))
	{
		printf(" One player Required !\n");
		exit(1);
	}
	if (v.exit_door > 1 || v.exit_door < 1)
	{
		printf(" One Exit_Door Required !\n");
		exit(1);
	}
	if (v.collct < 1)
	{
		printf(" at least one collct !\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	
	int i;
	var v;
	v.height = 0;
	if (ac == 2)
	{
		check_ext(av[1]);
		v.map = valid_map(av[1]);
	
	v.height = len_map(av[1], v);
	v.width =ft_strlen(v.map[0]);
	
	i = 0;
	while (i < v.height - 1)
	{
		v.player = check_player(v.map[i]);
		v.exit_door = check_exit_door(v.map[i]);
		v.collct = check_collct(v.map[i]);
		i++;
	}
	if_conditions(v);
	v.ptr = mlx_init(TILE_SIZE * v.width, TILE_SIZE * v.height, "Window", false);
	if(!v.ptr)
		return(1);
	v.w_texture = mlx_load_png("./textures/wall.png");
	if(!v.w_texture)
		exit(1);
    v.put_wall = mlx_texture_to_image(v.ptr ,v.w_texture);
	if(!v.put_wall)
	{
		printf("Error: failed to put Wall");
		exit(1);
	}
	v.f_texture = mlx_load_png("./textures/bckg.png");
	if(!v.f_texture)
		exit(1);
    v.put_floor = mlx_texture_to_image(v.ptr ,v.f_texture);
	if(!v.put_floor)
	{
		printf("Error: failed to put floor_texture");
		exit(1);
	}
	v.col_texture = mlx_load_png("./textures/coll.png");
	if(!v.col_texture)
		exit(1);
   v.put_col = mlx_texture_to_image(v.ptr ,v.col_texture);
	if(!v.put_col)
	{
		printf("Error: failed to put coll_textr");
		exit(1);
	}
	v.door_texture = mlx_load_png("./textures/door1.png");
	if(!v.door_texture)
		exit(1);
    v.put_door = mlx_texture_to_image(v.ptr ,v.door_texture);
	if(!v.put_door)
	{
		printf("Error: failed to put door_texture");
		exit(1);
	}
	v.ennemi_texture = mlx_load_png("./textures/ennemi.png");
	if(!v.ennemi_texture)
		exit(1);
    v.put_ennemi = mlx_texture_to_image(v.ptr ,v.ennemi_texture);
	if(!v.put_ennemi)
	{
		printf("Error: failed to put Ennemi_texture\n");
		exit(1);
	}
	v.plr_texture = mlx_load_png("./textures/player.png");
	if(!v.plr_texture)
		exit(1);
    v.put_plr = mlx_texture_to_image(v.ptr ,v.plr_texture);
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
			if(v.map[v.y][v.x] == floor)
			{
				mlx_image_to_window(v.ptr,v.put_floor, (v.x *32), (v.y * 32));
				if(!v.put_floor)
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
			if(v.map[v.y][v.x] == wall)
			{
				mlx_image_to_window(v.ptr,v.put_floor, (v.x *32), (v.y * 32));
				if(!v.put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,v.put_wall, (v.x *32), (v.y * 32));
				if(!v.put_wall)
				{
					printf("failed to open file\n");
					exit(1);
				}
			}
			if(v.map[v.y][v.x] == coll)
			{
				mlx_image_to_window(v.ptr,v.put_floor, (v.x *32), (v.y * 32));
				if(!v.put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,v.put_col, (v.x *32), (v.y * 32));
				if(!v.put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			if(v.map[v.y][v.x] == ex_dr)
			{
				mlx_image_to_window(v.ptr,v.put_floor, (v.x *32), (v.y * 32));
				if(!v.put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,v.put_door, (v.x *32), (v.y * 32));
				if(!v.put_door)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			if(v.map[v.y][v.x] == ennemi)
			{
				mlx_image_to_window(v.ptr,v.put_floor, (v.x *32), (v.y * 32));
				if(!v.put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(v.ptr,v.put_ennemi, (v.x *32), (v.y * 32));
				if(!v.put_ennemi)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			
			v.x++;
		}
		v.y++;
	}

		put_player(&v);
	

		player_pos(v.map, v.height, &v.y, &v.x);
		ex_door_pos(v.map, v.height, &v.i, &v.j);
		mlx_key_hook(v.ptr, my_hook, &v);
		mlx_loop(v.ptr);
	}
	// system("leaks so_long");
}
