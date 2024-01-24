
#include "get_next_line.h"

// int	ft_strlen(const char *c)
// {
// 	int	i;

// 	i = 0;
// 	while (c[i] != '\0')
// 		i++;
// 	return (i);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	if (dstsize == 0)
// 	{
// 		while (src[i])
// 			i++;
// 		return (i);
// 	}
// 	while (i < dstsize - 1 && src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	if (i < dstsize)
// 		dst[i] = '\0';
// 	while (src[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	char	*save_point;

// 	c = c % 256;
// 	save_point = NULL;
// 	if (c == '\0')
// 	{
// 		while (*s)
// 			s++;
// 		return ((char *)s);
// 	}
// 	while (*s)
// 	{
// 		if (*s == c)
// 			save_point = (char *)s;
// 		s++;
// 	}
// 	return (save_point);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	dst_len;
// 	size_t	src_len;
// 	size_t	i;

// 	dst_len = ft_strlen(dst);
// 	src_len = ft_strlen(src);
// 	i = 0;
// 	if (dstsize <= dst_len)
// 		return (src_len + dstsize);
// 	while (src[i] && dstsize - 1 > dst_len + i)
// 	{
// 		dst[dst_len + i] = src[i];
// 		i++;
// 	}
// 	dst[dst_len + i] = '\0';
// 	return (dst_len + src_len);
// }

int	main(void)
{
	int		i;
	int		migger_fd;
	// char	* ccc line;

	migger_fd = open("/Users/amecani/42_Projects/get_next_line_GITHUB/migger", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		printf("\n////////////////////////////////Test number %i//////////////////////////////////////////////////////////////////////////////////////", i);
		printf("\nThe Result:%s", get_next_line(migger_fd));
		i++;
	}
	// while ((line = get_next_line(migger_fd)) != NULL)
	// {
	// 	printf("\n////////////////////////////////Test number %i//////////////////////////////////////////////////////////////////////////////////////", i);
	// 	printf("\nThe Result:%s", line);
	// 	i++;
	// 	free(line);
	// }
	close(migger_fd);
}
