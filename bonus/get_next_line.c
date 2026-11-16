#include "../inc/push_swap.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		i;
	int		rd;

	buf = malloc(1024);
	if (!buf)
		return (NULL);
	i = 0;
	rd = read(fd, &buf[i], 1);
	while (rd > 0 && buf[i] != '\n' && i < 1023)
	{
		i++;
		rd = read(fd, &buf[i], 1);
	}
	if (rd <= 0 && i == 0)
	{
		free(buf);
		return (NULL);
	}
	if (buf[i] == '\n')
		i++;
	buf[i] = '\0';
	return (buf);
}
