#include "get_next_line.h"

int main(int ac, char **av){
	
	int		fd = 0;
	char	*line = 0;
	(void)ac;
	
	fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
		free(line);
    }
	close(fd);
	system("leaks a.out");
	return (0);
}
