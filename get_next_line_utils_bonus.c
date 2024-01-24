/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:35:24 by amecani           #+#    #+#             */
/*   Updated: 2024/01/24 14:42:13 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*save_point;

	c = c % 256;
	save_point = NULL;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == c)
			return (save_point = (char *)s);
		s++;
	}
	return (0);
}

char	*ft_substr(char const *src, unsigned int index, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	n;

	if (!src)
		return (NULL);
	if (len > (size_t)ft_strlen(src))
		len = ft_strlen(&src[index]);
	i = 0;
	n = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[index] && len-- && index <= n)
		dest[i++] = src[index++];
	dest[i] = '\0';
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	i = 0;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_new;
	const char	*src_new;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	src_new = (const char *)src;
	dst_new = (char *)dst;
	i = 0;
	while (i < n)
	{
		dst_new[i] = src_new[i];
		i++;
	}
	return (dst);
}
