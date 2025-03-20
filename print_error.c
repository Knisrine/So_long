/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:13:10 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/18 12:54:27 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_error(var *v)
{
	write(1, "Error : failed to load texture\n", 32);
	clean(v);
	exit(1);
}

void	image_error(var *v)
{
	write(1, "Error : failed to load image\n", 32);
	clean(v);
	exit(1);
}
