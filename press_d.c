/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:44:38 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/20 15:04:06 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(var *v)
{
	v->put_plr->instances->x += 32;
	v->y += 1;
	v->count_move++;
	smll_putnbr(v->count_move);
	ft_putchar('\n');
}

void	press_d(var *v)
{
	if (v->map[v->x][v->y + 1] != WALL)
	{
		if (v->map[v->x][v->y + 1] == COLL)
		{
			move_right(v);
			mlx_image_to_window(v->ptr, v->put_floor, (v->y * 32), (v->x * 32));
			v->map[v->x][v->y] = FLOOR;
			mlx_delete_image(v->ptr, v->put_plr);
			v->put_plr = mlx_texture_to_image(v->ptr, v->plr_texture);
			if (!v->put_plr)
			{
				texture_error(v);
				exit(1);
			}
			mlx_image_to_window(v->ptr, v->put_plr, (v->y * 32), (v->x * 32));
			v->collct--;
		}
		else
			move_right(v);
	}
	exit_player(v);
}
