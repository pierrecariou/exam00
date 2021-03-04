#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int		r;
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("line %d : %s\n", i, line);
		free(line);
		line = NULL;
		i++;
	}
	printf("line end %d : %s", i, line);
	free(line);
	line = NULL;
}
