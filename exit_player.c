/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:29:21 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/17 02:42:22 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_player(var *v)
{
	if (v->collct == 0 && (v->x == v->j) && (v->y == v->i))
	{
		mlx_delete_image(v->ptr, v->put_plr);
		free_map(v->map);
		free(v->map);
		exit(0);
	}
}
