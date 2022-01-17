#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

int ft_strchr(char *line)
{
    int i = 0;
    while (lline[i])
    {
        if (line[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *ft_strjoin(char *statik, char *buffer)
{
    char *tab;
    unsigned int size;
    int i;
    int j;

    if (!statik && !buffer)
        return (NULL);
    size = ft_strlen(statik) + ft_strlen(buffer);
    if(!(tab = (char * )malloc(sizeof(char) *(size + 1))))
        return NULL;
    i = 0;
    j = 0;
    if (statik)
    {
        while(statik[i])
        {
            tab[j] = statik[i];
            i++;
            j++;
        }
        i = 0;
    }
    while (buffer[i])
    {
        tab[j] = buffer[i];
        j++;
        i++;
    }
    tab[size] = '\0';
    free((void *)statik);
    return (tab);
}

char    *ft_cut_before_next_line(char *statik)
{
    int i;
    int j;
    char *tab;

    i = 0;
    j = 0;
    while (statik[i] && statik[i] != '\n')
        i++;
    if (!statik[i])
    {
        free(statik);
        return (NULL);
    }
    if (!(tab) = (char *)malloc(sizeof(char) * (ft_strlen(tab) - i + 1))))
        return (NULL);
    i++;
    while (statik[i])
    {
        tab[j] =statik[i];
        i++;
        j++;
    }
    tab[j] = '\0';
    free(statik);
    return (tab);
}

char *ft_push_after_line(char *statik)
{
    int i = 0;
    char *tab;

    while (statik[i] && statik[i] != '\n')
        i++;
    if(statik[i] == '\n')
		i++;
    if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (statik[i] && statik[i] != '\n')
    {
        tab[i] = statik[i];
        i++;
    }
	if (statik[i] == '\n')
	{
		tab[i] = '\n';
		tab[i + 1] = '\0';
		return(tab);
	}
    statik[i] = '\0';
    return (tab);
}

char     *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    static char *statik;
	char *line;
    int count;

    count = 1;
    while (!ft_strchr(buffer) && count != 0)
    {
        if ((count = read(fd, buffer, BUFFER_SIZE)) == (-1))
            return (NULL);
        buffer[count] = '\0';
        statik = ft_strjoin(statik, buffer);
    }
    line = ft_push_after_line(statik);
    statik = ft_cut_before_next_line(statik);
	if(line[0] == '\0')
		return(NULL);
    return(line);
}
