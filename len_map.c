/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:26 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/15 17:00:09 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_map(char *s, var v)
{
	int		fd;
	char	*lines;

	fd = 0;
	lines = NULL;
	fd = open(s, O_RDONLY);
	lines = get_next_line(fd);
	if (!lines)
	{
		///close file
		printf("Empty file !\n");
		exit(2);
	}
	while (lines)
	{
		v.height++;
		free(lines);
		lines = get_next_line(fd);
	}
	return (v.height);
}
