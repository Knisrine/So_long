/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:59:19 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/17 16:39:04 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean(var *v)
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
	free_map(v->map);
	free(v->map);
	mlx_terminate(v->ptr);
}
