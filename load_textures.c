/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:20:18 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/17 21:08:46 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

static void	load_textures_p3(var *v)
{
	v->plr_texture = mlx_load_png("./textures/player.png");
	if (!v->plr_texture)
		texture_error(v);
	v->put_plr = mlx_texture_to_image(v->ptr, v->plr_texture);
	if (!v->put_plr)
		texture_error(v);
}

void	load_textures(var *v)
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
