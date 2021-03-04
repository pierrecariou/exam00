#include "get_next_line.h"
#include "stdio.h"

int	get_next_line(char **line)
{	
	char	buf[2];
	int		ret;
	int		i;
	
	i = 0;
	*line = malloc(1000);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
		line[0][i++] = buf[0];
	line[0][i] = '\0';
	if (!ret)
		return (0);
	else if (ret == -1)
		return (-1);
	return (1);
}
