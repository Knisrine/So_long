/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:59:56 by nikhtib           #+#    #+#             */
/*   Updated: 2025/02/28 17:23:27 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./MLX42/include/MLX42/MLX42.h"



    //  void *ptr = mlx_init(1200,600, "Window", false);
    // if(ptr == NULL)
    // return(1);
    // mlx_image_t *img = mlx_new_image(ptr,1200, 1200);
    // mlx_image_to_window(ptr, img, 0, 0);
    // for (int i = 0; i < 1200; i++)
    // {
    //     for (int j = 0; j < 1200; j++)
    //      mlx_put_pixel(img, j, i, 0);
    // }
    // mlx_loop(ptr);

    int main(int ac, char **av)
    {
        // int n;
        if(ac == 2)
        {
            check_ext(av[1]);
            valid_map(av[1]);
            
        }
        system("leaks so_long");
    }