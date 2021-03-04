#include "unistd.h"

int	cmp_bef_2(int k, char *str, char *strb, char c)
{
	int i;

	i = -1;
	while (str[++i] && i < k)
	{
		if (c == str[i])
			return (1);
	}
	i = -1;	
	while (strb[++i])
	{
		if (c == strb[i])
			return (1);
	}
	return (0);
}

int	cmp_bef(int k, char	*str, char c)
{
	int i;

	i = -1;
	while (str[++i] && i < k)
	{
		if (c == str[i])
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
		if (!cmp_bef(i, argv[1], argv[1][i]))
			write(1, &argv[1][i], 1);
	}
	i = -1;
	while (argv[2][++i])
	{
		if (!cmp_bef_2(i, argv[2], argv[1], argv[2][i]))
			write(1, &argv[2][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
