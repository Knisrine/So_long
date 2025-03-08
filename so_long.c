/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:59:56 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/08 01:54:49 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	var v;
    // data d;
	v.height = 0;
	char **map;
	if (ac == 2)
	{
		check_ext(av[1]);
		map = valid_map(av[1]);
	
	v.height = len_map(av[1], v);
	v.width =ft_strlen(map[0]);
	
	void *ptr = mlx_init(830,350, "Window", false);
	if(!ptr)
		return(1);
	mlx_texture_t* w_texture = mlx_load_png("./textures/pp.png");
	if(!w_texture)
		exit(1);
    mlx_image_t* put_wall = mlx_texture_to_image(ptr ,w_texture);
	if(!put_wall)
	{
		printf("eeerrr");
		exit(1);
	}
	
	mlx_texture_t* f_texture = mlx_load_png("./textures/bg.png");
	if(!f_texture)
		exit(1);
    mlx_image_t* put_floor = mlx_texture_to_image(ptr ,f_texture);
	if(!put_floor)
	{
		printf("eeerrr");
		exit(1);
	}
	mlx_texture_t* col_texture = mlx_load_png("./textures/img00.png");
	if(!col_texture)
		exit(1);
    mlx_image_t* put_col = mlx_texture_to_image(ptr ,col_texture);
	if(!put_col)
	{
		printf("eeerrr");
		exit(1);
	}
	mlx_texture_t* plr_texture = mlx_load_png("./textures/cat.png");
	if(!col_texture)
		exit(1);
    mlx_image_t* put_plr = mlx_texture_to_image(ptr ,plr_texture);
	if(!put_plr)
	{
		printf("eeerrr");
		exit(1);
	}
	// mlx_texture_t* plr_texture = mlx_load_png("./textures/cat.png");
	// if(!col_texture)
	// 	exit(1);
    // mlx_image_t* put_plr = mlx_texture_to_image(ptr ,plr_texture);
	// if(!put_plr)
	// {
	// 	printf("eeerrr");
	// 	exit(1);
	// }
	int j = 0;
	int i;
	while(j < v.height)
    {
		i = 0;
        while (i < v.width)
        {
			if(map[j][i] == wall)
			{
				mlx_image_to_window(ptr,put_floor, (i *32), (j * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(ptr,put_wall, (i *32), (j * 32));
				if(!put_wall)
				{
					printf("failed to open file\n");
					exit(1);
				}
			}
			if(map[j][i] == floor)
			{
				mlx_image_to_window(ptr,put_floor, (i *32), (j * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			if(map[j][i] == coll)
			{
				mlx_image_to_window(ptr,put_floor, (i *32), (j * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(ptr,put_col, (i *32), (j * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			if(map[j][i] == plr)
			{
				mlx_image_to_window(ptr,put_floor, (i *32), (j * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
				mlx_image_to_window(ptr,put_plr, (i *32), (j * 32));
				if(!put_floor)
				{
					printf("failed to open file");
					exit(1);
				}
			}
			i++;
		}
		j++;
	}
	// if(!texture)
	// {
	// 	printf("errr");
	// 	exit(1);
	// }
	// mlx_delete_image(ptr, texture);
	// mlx_delete_texture(texture);
	// mlx_terminate(ptr);
	// return (EXIT_SUCCESS);
	// mlx_image_to_window(ptr, img, 0, 0);
	
	mlx_loop(ptr);
	}
	// system("leaks so_long");
}