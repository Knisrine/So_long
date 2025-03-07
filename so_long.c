/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:59:56 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/07 01:46:38 by nikhtib          ###   ########.fr       */
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
	
	void *ptr = mlx_init(1200,600, "Window", false);
	if(!ptr)
		return(1);
	mlx_texture_t* texture = mlx_load_png("./textures/img00.png");
	if(!texture)
	{
		printf("errr");
		exit(1);
	}
	// mlx_image_t* img = mlx_new_image(ptr,1400, 1200);
	 mlx_image_t* img = mlx_texture_to_image(ptr,texture);
	if(!img)
	{
		printf("eeerrr");
		exit(1);
	}

	if (mlx_image_to_window(ptr, img, 0, 0) < 0)
		exit(1);

	mlx_texture_t* texture1 = mlx_load_png("./textures/texture00.png");
    mlx_image_t* img1 = mlx_texture_to_image(ptr ,texture1);
	if(!img1)
	{
		printf("eeerrr");
		exit(1);
	}
	//  mlx_image_t* img1 = mlx_texture_to_image(ptr,texture1);
	int j = 0;
	int i;
    // printf("[%d]", v.height);
	// exit(1);
	while(j < v.height)
    {
		i = 0;
		// printf("[%d]\n", j);
        while (i < v.width)
        {
            if(map[j][i] == wall)
			mlx_image_to_window(ptr,img1, (i *32), (j * 32));
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