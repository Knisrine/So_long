/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:06:10 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/20 15:06:19 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	txtr_error(var *v)
{
	write(1, "Error : failed to load texture\n", 32);
	clean_textrs(v);
	free_map(v->map);
	free(v->map);
	exit(1);
}

void	clean_textrs(var *v)
{
	if (v->w_texture)
		mlx_delete_texture(v->w_texture);
	if (v->f_texture)
		mlx_delete_texture(v->f_texture);
	if (v->col_texture)
		mlx_delete_texture(v->col_texture);
	if (v->door_texture)
		mlx_delete_texture(v->door_texture);
	if (v->plr_texture)
		mlx_delete_texture(v->plr_texture);
}

void	check_textures(var *v)
{
	v->w_texture = mlx_load_png("./textures/wall.png");
	if (!v->w_texture)
		txtr_error(v);
	v->f_texture = mlx_load_png("./textures/bckg.png");
	if (!v->f_texture)
		txtr_error(v);
	v->col_texture = mlx_load_png("./textures/coll.png");
	if (!v->col_texture)
		txtr_error(v);
	v->door_texture = mlx_load_png("./textures/door1.png");
	if (!v->door_texture)
		txtr_error(v);
	v->plr_texture = mlx_load_png("./textures/player.png");
	if (!v->plr_texture)
		txtr_error(v);
	clean_textrs(v);
}
