/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:15:23 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/14 22:10:47 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
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
