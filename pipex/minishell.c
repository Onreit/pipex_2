#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (*(s1 + i) && *(s2 + i) && --n)
	{
		if (*(s1 + i) != *(s2 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		i++;
	}
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
    char *inpt;
    int i;

    i = 0;
    while ( i < 10 )
    {
        inpt = readline("heredoc> ");
        add_history(inpt);
        if (!ft_strncmp(av[1], inpt, ft_strlen(av[1])))
            exit(1);
        //printf("%s", inpt);
        //printf("\n");
        ++i;
    }
    return 0;
}
