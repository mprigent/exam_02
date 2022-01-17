#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int tab[127];
    int i = 0;
    int index1 = 0;
    int index2 = 0;

    if (argc != 3)
    {
        ft_putchar('\n');
        return (0);
    }
    while (i < 127)
        tab[i++] = 0;
    while (argv[1][index1])
    {
        if (tab[(int)argv[1][index1]] == 1)
            index1++;
        else
        {
            ft_putchar(argv[1][index1]);
            tab[(int)argv[1][index1++]] = 1;
        }
    }
    while (argv[2][index2])
    {
        if (tab[(int)argv[2][index2]] == 1)
            index2++;
        else
        {
            ft_putchar(argv[2][index2]);
            tab[(int)argv[2][index2++]] = 1;
        }
    }
    ft_putchar('\n');
    return (0);
}