/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:07:47 by nikhtib           #+#    #+#             */
/*   Updated: 2025/03/12 18:11:49 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	t_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	t_len = len_s1 + len_s2;
	new_str = malloc(t_len + 1);
	if (!new_str)
		return (free(s1), NULL);
	ft_memcpy(new_str, s1, len_s1);
	ft_memcpy(new_str + len_s1, s2, len_s2);
	free(s1);
	new_str[t_len] = '\0';
	return (new_str);
}

char	*ext_line(char *s)
{
	int		len;
	char	*line;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != '\n')
	{
		line[len] = s[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*rest_of_string(char *s)
{
	char	*p;
	int		i;
	char	*rl;

	i = 0;
	if (!s)
		return (NULL);
	p = ft_strchr(s, '\n');
	if (!p)
		return (free(s), NULL);
	p += 1;
	rl = malloc(ft_strlen(p) + 1);
	if (!rl)
		return (NULL);
	while (p[i] != '\0')
	{
		rl[i] = p[i];
		i++;
	}
	rl[i] = '\0';
	free(s);
	s = NULL;
	return (rl);
}
