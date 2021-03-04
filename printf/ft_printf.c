#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int		champ;
int		prec;

void	write_spaces(int	length)
{
	int i;

	i = 0;
	if (champ != 0 && champ > length)
	{
		while (i < champ - length)
		{
			write(1, " ", 1);
			i++;
		}
	}
}

void	hexaconverter(unsigned int n)
{
	int		d;
	int		i;
	char	array[100];
	int		cp;
	int		l;

	i = 0;
	l = 0;
	if (n == 0)
	{
		write_spaces(1);
		write(1, "0", 1);
		return ;
	}
	while (n != 0)
	{
		d = n%16;
		if (d < 10)
			array[i++] = d + '0';
		else
			array[i++] = d + 55 + 32;
		n/=16;
	}
	cp = i;
	while (--cp >= 0)
		l++;
	write_spaces(l);
	while (--i >= 0)
		write(1, &array[i], 1);
}

void	ft_putnbr(int nb)
{
	int ret;

	if (nb < 0)
	{
		nb*=-1;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ret = nb + '0';
		write(1, &ret, 1);
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	length_nbr(int nb)
{
	int l;
	int cp;

	cp = nb;
	l = 1;
	if (cp < 0)
		l++;
	while (cp >= 10)
	{
		cp/=10;
		l++;
	}
	write_spaces(l);
}

void	ft_putstr(char *str, int prec)
{
	int	i;

	i = 0;
	if (prec == 0)
	{
		write(1, str, ft_strlen(str));
		return ;
	}
	while (str[i] && i < prec)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	actions(va_list parameter, char t)
{
	char	*str;
	int		d;

	if (t == 's')
	{
		str = va_arg(parameter, char *);
		if (prec > 0 && ft_strlen(str) > prec)
			write_spaces(prec);
		else
			write_spaces(ft_strlen(str));
		ft_putstr(str, prec);
	}
	else if (t == 'd')
	{
		d = va_arg(parameter, int);
		length_nbr(d);
		ft_putnbr(d);
	}
	else if (t == 'x')
		hexaconverter(va_arg(parameter, int));
}

int		champ_and_prec(const char *types, int i)
{
	champ = 0;
	prec = 0;
	int	cp;

	if (types[i] == '-')
		i++;
	cp = i;
	while (types[i] <= '9' && types[i] >= '0')
		i++;
	if (i != cp)
	{
		while (cp < i)
			champ = champ * 10 + (types[cp++] - '0');
	}
	if (types[i] == '.')
		i++;
	cp = i;
	while (types[i] <= '9' && types[i] >= '0')
		i++;
	if (i != cp)
	{
		while (cp < i)
			prec = prec * 10 + (types[cp++] - '0');
	}
	return (i);
}

void	args_nb(const char *types, va_list parameter)
{
	int i;

	i = -1;
	while (types[++i])
	{
		if (types[i] == '%')
		{
			i = champ_and_prec(types, ++i);
			actions(parameter, types[i]);
		}
		else
			write(1, &types[i], 1);
	}
}

int		ft_printf(const char *types, ... )
{
	va_list	parameter;

	va_start(parameter, types);
	args_nb(types, parameter);
	va_end(parameter);
	return (0);
}
