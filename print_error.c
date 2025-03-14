/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:13:10 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/14 11:59:15 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_error(var *v)
{
	printf("Error : failed to load texture\n");
	free_map(v->map);
	exit(1);
}
void	image_error(var *v)
{
	printf("Error : failed to load image\n");
	free_map(v->map);
	exit(1);
}