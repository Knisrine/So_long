/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:15:23 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 17:15:18 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	if (!map || !(*map))
		return ;
	while (*map)
	{
		free(*map);
		map++;
	}
}

void	free_maps(char **map, char **new_map)
{
	free_map(map);
	free(map);
	free_map(new_map);
	free(new_map);
}
