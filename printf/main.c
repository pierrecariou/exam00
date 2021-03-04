#include <stdio.h>
#include <stdarg.h>

int	ft_printf(char const *format, ...);

int	main(void)
{
	ft_printf("%10.2s\n", "toto");
	ft_printf("Magic %s is %5d", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%10.2s\n", "toto");
	printf("Magic %s is %5d", "number", 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}
