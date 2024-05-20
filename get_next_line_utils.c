/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:05:36 by mshabano          #+#    #+#             */
/*   Updated: 2024/05/20 18:37:59 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*dst_p;

	dst_p = dst;
	if ((!dst && !src) || (dst == src))
		return (dst);
	if (dst > src)
	{
		while (n-- > 0)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		while (n-- > 0)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (dst_p);
}

char	*strjoin_gnl(char *s1, char *s2, int len)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = len;
	p = (char *) malloc((len_s1 + len_s2 + 1) * sizeof (char));
	if (!p)
	{
		free(s1);
		return (NULL);
	}
	ft_memmove(p, s1, len_s1);
	ft_memmove(p + len_s1, s2, len_s2);
	*(p + len_s1 + len_s2) = '\0';
	free(s1);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*temp_s;

	temp_s = (char *)s;
	while (n > 0)
	{
		*(temp_s++) = 0;
		n--;
	}
}
