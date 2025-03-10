/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:26 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/10 14:02:21 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		len_map(char *s, var v)
{
	int		fd;
	char	*lines;
	fd = 0;
	lines = NULL;
	fd = open(s, O_RDONLY);
	while ((lines = get_next_line(fd)))
	{
		v.height++;
		free(lines);
	}
	return (v.height);
}
