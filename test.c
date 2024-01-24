
#include "get_next_line.h"

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
