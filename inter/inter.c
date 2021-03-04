#include <unistd.h>

int	cmp_bef(char c, char *str, int k)
{
	int i;

	i = -1;
	while (str[++i] && i < k)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	iter_cmp(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i;

	i = -1;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (argv[1][++i])
	{
		if (!cmp_bef(argv[1][i], argv[1], i) && iter_cmp(argv[1][i], argv[2]))
			write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
