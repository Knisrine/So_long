/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smll_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:41:40 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/20 15:07:14 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	smll_putnbr(int nb)
{
	if (nb > 9)
		smll_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
