#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char *strjoin(char *s1, char *s2)
{
	if (!s2)
		return (s1);
	int	i = 0,	j = 0,	len = ft_strlen(s1)+ ft_strlen(s2);
	char *ret = malloc(sizeof(char) * len + 1);
	ret[len] = 0;
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		ret[i++] = s2[j++];
	free(s1);
	return (ret);
}

int check_temp(char *temp)
{
	int	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *fill(char **temp, int r)
{
	int	i = 0,	j = 0;
	while ((*temp)[i] && (*temp)[i] != '\n')
		i++;
	if ((*temp)[i] == '\n')
		i++;
	if (i == 0 && r == 0){
		free((*temp));
		return (0);
	}
	char	*line = malloc(sizeof(char) * i + 1);
	line[i] = 0;
	i = 0;
	while ((*temp)[i] && (*temp)[i] != '\n')
	{
		line[i] = (*temp)[i];
		i++;
	}
	if((*temp)[i] == '\n')
		line[i] = (*temp)[i];
	if ((*temp)[i])
		i++;
	while ((*temp)[i + j])
		j++;
	char	*t = malloc(sizeof(char) * j + 1);
	t[j] = 0;
	j = 0;
	while ((*temp)[i + j])
	{
		t[j] = (*temp)[i + j];
		j++;
	}
	free((*temp));
	(*temp) = t;
	return (line);
}

char *get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*temp = 0;
	int			r = 1;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	while (!check_temp(temp) && r != 0)
	{
		r = read(fd, &buff, BUFFER_SIZE);
		buff[r] = '\0';
		temp = strjoin(temp, buff);
	}
	return (fill(&temp, r));
}
