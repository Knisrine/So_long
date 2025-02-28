/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 03:56:19 by nikhtib           #+#    #+#             */
/*   Updated: 2025/02/28 16:54:40 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while(s1[i] || s2[i])
    {
        if(s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}


void     check_ext(char *s)
{
    char *ext = ".ber";
    char *str;
    int n;
    n = open(s, O_RDONLY);

    if(n < 0)
    {
        perror("File Not Found !\n");
        exit (1);
    }
    str = ft_strchr(s, '.');
    if(ft_strcmp(ext, str))
    {
        perror("Invalid file\n");
        exit (1);
    }
}
