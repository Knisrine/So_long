/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:41:07 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/20 15:04:14 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_down(var *v)
{
	v->put_plr->instances->y += 32;
	v->x += 1;
	v->count_move++;
	smll_putnbr(v->count_move);
	ft_putchar('\n');
}

void	press_s(var *v)
{
	if (v->map[v->x + 1][v->y] != WALL)
	{
		if (v->map[v->x + 1][v->y] == COLL)
		{
			move_down(v);
			mlx_image_to_window(v->ptr, v->put_floor, (v->y * 32), (v->x * 32));
			v->map[v->x][v->y] = FLOOR;
			mlx_delete_image(v->ptr, v->put_plr);
			v->put_plr = mlx_texture_to_image(v->ptr, v->plr_texture);
			if (!v->put_plr)
				texture_error(v);
			mlx_image_to_window(v->ptr, v->put_plr, (v->y * 32), (v->x * 32));
			v->collct--;
		}
		else
			move_down(v);
	}
	exit_player(v);
}
