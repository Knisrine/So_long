/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:44:21 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 15:52:15 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	press_esc(var *v)
{
	free_map(v->map);
	exit(1);
}

void	my_hook(mlx_key_data_t keydata, void *param)
{
	var	*v;
	v = (var *)param;
	if (keydata.key == MLX_KEY_W && keydata.action)
		press_w(v);
	else if (keydata.key == MLX_KEY_S && keydata.action != MLX_PRESS)
		press_s(v);
	else if (keydata.key == MLX_KEY_A && keydata.action != MLX_PRESS)
		press_a(v);
	else if (keydata.key == MLX_KEY_D && keydata.action != MLX_PRESS)
		press_d(v);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		press_esc(v);
}
