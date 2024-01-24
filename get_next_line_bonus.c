/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:34:54 by amecani           #+#    #+#             */
/*   Updated: 2024/01/24 14:48:54 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s1, int farewell)
{
	char	*ptr;
	size_t	i;
	size_t	cj;

	if (!s1)
		return (NULL);
	cj = ft_strlen(s1);
	i = 0;
	ptr = malloc(sizeof(char) * cj + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	if (farewell)
		free(s1);
	return (ptr);
}

char	*custom(char *s1, char *s2, int simply_return_s2)
{
	char	*new;
	int		l;

	if (!s1)
	{
		if (!s2 || !*s2)
			return (NULL);
		if (simply_return_s2)
			return (s2);
		return (ft_strdup(s2, 0));
	}
	if (!s2)
		return (s1);
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(l * sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, (ft_strlen(s1) + 1));
	ft_memcpy((new + ft_strlen(s1)), s2, (ft_strlen(s2) + 1));
	free (s1);
	if (simply_return_s2)
		free (s2);
	return (new);
}

char	*where_da_new_line_at(char *found, char *stash, int fd, int checky)
{
	char	*ptr;

	ptr = ft_strchr(stash, '\n');
	if (ptr)
	{
		found = custom(found, ft_substr(stash, 0, (ptr - stash) + 1), 1);
		ft_memmove(stash, ptr + 1, ft_strlen(ptr + 1) + 1);
	}
	else
	{
		found = custom(found, ft_strdup(stash, 0), 1);
		stash[0] = 0;
	}
	if (ft_strchr(found, '\n') || checky != BUFFER_SIZE)
		return (found);
	return (we_readin_an_shiet(fd, stash, found));
}

char	*we_readin_an_shiet(int fd, char *stash, char *found)
{
	int		checky;

	checky = BUFFER_SIZE;
	if (!ft_strchr(stash, '\n'))
	{
		found = custom(found, stash, 0);
		checky = read(fd, stash, BUFFER_SIZE);
		if (checky == -1)
			stash[0] = 0;
		if (checky == -1)
			return (free (found), NULL);
		if (checky <= 0)
		{
			stash[0] = 0;
			return (found);
		}
		stash[checky] = '\0';
	}
	if (stash[0] == 0)
	{
		free (found);
		return (NULL);
	}
	return (where_da_new_line_at(found, stash, fd, checky));
}

char	*get_next_line(int fd)
{
	static char	stash[10240][BUFFER_SIZE + 1];
	char		*found;

	found = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	return (we_readin_an_shiet(fd, stash[fd], found));
}
