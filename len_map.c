/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:51:26 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/17 00:44:27 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_map(char *s, var v)
{
	char	*lines;

	lines = NULL;
	v.fd = open(s, O_RDONLY);
	lines = get_next_line(v.fd);
	if (!lines)
	{
		close(v.fd);
		write(2, "Empty file !\n", 13);
		exit(2);
	}
	while (lines)
	{
		v.height++;
		free(lines);
		lines = get_next_line(v.fd);
	}
	close(v.fd);
	return (v.height);
}
