/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:40:34 by eahn              #+#    #+#             */
/*   Updated: 2024/06/11 15:45:11 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*sl_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t	sl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (src[i] != '\0' && (i < dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		if (dst[i - 1] == '\n')
			dst[i - 1] = '\0';
		else
			dst[i] = '\0';
	}
	return (src_len);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	sl_strlcpy(new_str, s1, s1_len + 1);
	sl_strlcpy(new_str + (s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_str);
}
